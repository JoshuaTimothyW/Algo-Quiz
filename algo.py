from bs4 import BeautifulSoup as bs 
import requests
import os
import json
import base64
import androidhelper
import ui

requests.packages.urllib3.util.ssl_.DEFAULT_CIPHERS = "TLS13-CHACHA20-POLY1305-SHA256:TLS13-AES-128-GCM-SHA256:TLS13-AES-256-GCM-SHA384:ECDHE:!COMPLEMENTOFDEFAULT"

s = requests.Session()

# List URL
URL_LOGIN = "https://socs1.binus.ac.id/quiz/public/login.php"
URL_PROBLEMS = "https://socs1.binus.ac.id/quiz/team/problems.php"
URL_SCOREBOARD = "https://socs1.binus.ac.id/quiz/team/scoreboard.php"
URL_BASE = "https://socs1.binus.ac.id/quiz/team/"
URL_CHANGE_CONTEST = "https://socs1.binus.ac.id/quiz/team/change_contest.php"

# Option to download problem case (default 1)
download_case = 1

dir = "/storage/emulated/0/Download/"

# Create profile.json if not exist, otherwise use data
if(not os.path.exists("./profile.json")):
    while True:
        # GUI for android
        droid = androidhelper.Android()
        email = droid.dialogGetInput('Email or Username Binus','example@binus.ac.id','').result
        passwd = droid.dialogGetPassword('Password Binus','Enter your password').result
        
        # email = input("Email: ")
        # passwd = input("Pass: ")

        new_profile = {
            "email":email, 
            "passwd":passwd, 
        }
        
        # Remove @binus.ac.id
        new_profile["email"] = new_profile["email"].split("@")[0]
        
        # Validate login data
        result = s.post(URL_LOGIN,data=new_profile)
        
        # If true, break loop
        if(result.url is not URL_LOGIN):
            break  

    # Encode password
    encoded_pass = base64.b64encode(new_profile["passwd"].encode("utf-8"))
    new_profile["passwd"] = str(encoded_pass,"utf-8")

    open("profile.json","w+").write(json.dumps(new_profile))


# Read profile data
setting = json.loads(open("./algo_profile.json").read())


# Get filename
def get_filename_from_cd(cd):
    """
    Get filename from content-disposition
    """
    if not cd:
        return None
    fname = re.findall('filename=(.+)', cd)
    if len(fname) == 0:
        return None
    return fname[0]

# Scrape
def scrape():

    # Login
    header_config = {
        'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.75 Safari/537.36',
        'referer':'https://socs1.binus.ac.id/quiz/team/'
    }

    data_config = {
        "login":setting["email"]+"@binus.ac.id",
        "passwd":setting["passwd"],
        "cmd":"login",
    }

    # Decode Password
    decoded_pass = base64.b64decode(data_config["passwd"])
    data_config["passwd"] = str(decoded_pass,"utf-8")

    result = s.post(URL_LOGIN,data=data_config,headers=header_config)

    html = bs(result.text,features="html5lib")

    if(result.url is not URL_LOGIN):
        print("Login...")
    else:
        print("Login Failed...")
        return

    # Change contest
    list_options = html.find("select",{"id":"cid"})

    # If contest more than 1, continue
    if list_options:
        list_options = list_options.find_all("option")
        
        new_list_options = [int(option["value"]) for option in list_options]

        new_list_options.sort()
        #print(new_list_options) 
        
        change_contest_config = {
            "cid":new_list_options[-1]
        }

        result = s.get(URL_BASE+"change_contest.php",params=change_contest_config,headers=header_config)
    
    # Open Scoreboard Page
    result = s.get(URL_SCOREBOARD,headers=header_config)
    html = bs(result.text,features="html5lib")

    title = html.find("h1").text
    deadline = html.find("h4").text

    print(title)
    print(deadline)
    
    if(deadline is "final stand"): deadline = "No Deadline" 

    # Open Problem Page
    result = s.get(URL_PROBLEMS,headers=header_config)
    html = bs(result.text,features="html5lib")
    list_link_file = html.find("ul").find_all("a")
    
    if(len(list_link_file) == 0):
        print("No Case Problems")
    else:
        print("You got",len(list_link_file),"Case Problems")
    
    download_case = ui.dialog(title,deadline+" \n\nTotal : "+str(len(list_link_file))+" problem cases.\n\nDownload Problem Case?")

    
    # Download all problem cases if set to 1
    if(download_case == 0):
        print("Download Problem Cases...")
        # if(setting["download_case"] == 1):

        for link in list_link_file:
            # Open file from url
            response = s.get(URL_BASE+link["href"],headers=header_config)

            # Get filename from header content
            filename = response.headers.get('content-disposition').split("\"")[1]

            # Create File
            open(dir+filename, 'wb').write(response.content)


######################################

scrape()
