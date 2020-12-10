#include <stdio.h>
#include <string.h>

struct Password{
	char str[1001];
	int len;
}pass[1001];

int prefix(int min,int n){
	int length = strlen(pass[min].str);
	
	for(int i=0;i<length;i++){
		for(int j=0;j<n;j++){
			if( pass[min].str[i] != pass[j].str[i] ){
				return i;	
			}		
		}
	}
	
	return length;
}

int suffix(int min, int n){
	int length = strlen(pass[min].str);

	for(int i=0;i<length;i++){
		for(int j=0;j<n;j++){
			if( pass[min].str[length-(i+1)] != pass[j].str[pass[j].len-(i+1)] ){
				return length-i;	
			}
		}
	}
	
	return 0;
}

void read(){
	
	int t,n,min,index;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d\n",&t);
		
		for(int i=1;i<=t;i++){
			fscanf(rd,"%d\n",&n);
			
			min = 0;
			
			for(int j=0;j<n;j++){
				fscanf(rd,"%s\n",&pass[j].str);
				pass[j].len = strlen(pass[j].str);
				
				if( strlen(pass[min].str) > strlen(pass[j].str) ){
					min = j;
				}
			}
			
			printf("Case #%d: ",i);
			index = prefix(min,n);
			
			for(int j=0;j<index;j++){
				printf("%c",pass[min].str[j]);
			}
			
			index = suffix(min,n);
			
			for(int j=index;j<pass[min].len;j++){
				printf("%c",pass[min].str[j]);
			}
			
			printf("\n");
		}
	}
	
	fclose(rd);
}

int main(){
	
	read();
	
    return 0;
}
    
