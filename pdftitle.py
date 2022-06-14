from PyPDF2 import PdfFileReader
import os
import re

def extract_text(fullpath):
    pdf = open(fullpath,'rb')
    pdf_reader = PdfFileReader(pdf)
    first_page = pdf_reader.getPage(0)

    lines = first_page.extractText().splitlines()
    
    # r = re.compile("*{AlgorithmandProgramming*")
    for index, i in enumerate(lines):
        # print(lines)
        if i.endswith("{AlgorithmandProgramming"):
            title = lines[index+1]
            print("###",title)
            return

def get_pdf(path):
    for path, subdir, file in os.walk(path):
        print()
        print("##",path.split("/")[-1])

        for name in file:
            if(name[-3:] == 'pdf'):
                extract_text(os.path.join(path,name))

path = "./Quiz Jeremy/"
get_pdf(path)