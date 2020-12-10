#include <stdio.h>
#include <string.h>

int arr[26],mark[26];
char str[1001];

void init(){
	for(int i=0;i<26;i++){
		mark[i] = 0;
		arr[i] = 0;
	}
}

void change(char a, char b){
	if( mark[a-65] < 1 ){
		for(int i=0;i<strlen(str);i++){
			if(str[i] == a){
				str[i] = b;
			}
		}
		
		mark[a-65] = 1;	
	}
}

void read(){
	
	int t,n,index;
	char a,b;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d\n",&t);
		
		init();
		
		for(int i=1;i<=t;i++){
			fscanf(rd,"%s\n",&str);	
			
			fscanf(rd,"%d\n",&n);
			
			for(int j=0;j<n;j++){
				fscanf(rd,"%c %c\n",&a,&b);
				change(a,b);
			}
			
			for(int j=0;j<strlen(str);j++){
				arr[str[j]-65]++;
			}
			
			for(int j=0;j<26;j++){
				if(arr[j] > 0){
					printf("%c %d\n",j+65,arr[j]);
				}
				
				mark[j] = 0;
				arr[j] = 0;
			}
		}
		
	}
	
	fclose(rd);
}

int main(){
	read();
	
    return 0;
}
    
