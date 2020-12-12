#include <stdio.h>
#include <string.h>

int t;
char n[201];

void process(){
	
	int result=0;
	
	for(int i=0;i<strlen(n);i++){
		result = (result*10 + (int)n[i]-48)%6;
	}
	
	if(result == 0){
		printf("YES\n");	
	}else{
		printf("NO\n");
	}
}

void read(){
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%llu\n",&t);
		
		for(int i=1;i<=t;i++){
			fscanf(rd,"%[^\n]\n",&n);
			printf("Case #%d: ",i);
			process();
		}
	}
	
	fclose(rd);
}

int main(){
	read();

    return 0;
}
    
