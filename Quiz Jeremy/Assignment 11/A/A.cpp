#include <stdio.h>
#include <string.h>

int table[] = {'O','I','-','E','A','S','G','T','B'};

char str[1001];

void transform(int gap){
	for(int i=0;i<strlen(str);i++){
		if( str[i] >= '0' && str[i] <= '8' ){
			str[i] = table[(int)str[i]-48];
		}
		
		if( str[i] != ' ' ){
			if( str[i]-gap < 65){
				str[i] = (str[i]-65-gap)+91;	
			}else{
				str[i] -= gap;
			}
		}
	}
	
	printf("%s\n",str);
}

void read(){
	
	int t,n;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d\n",&t);
		
		for(int i=1;i<=t;i++){
			fscanf(rd,"%d\n",&n);
			fscanf(rd,"%[^\n]",str);
			printf("Case #%d: ",i);
			transform(n);
		}
	}
	
	fclose(rd);
}

int main(){
	
	read();
	
    return 0;
}
    
