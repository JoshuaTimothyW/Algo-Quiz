#include <stdio.h>
#include <string.h>

char str[100]="";
char temp[] = "ABA";
	
void empty_str(){
	for(int i=0;strlen(str);i++){
		str[i] = "";
	}
}


void pattern(int curr,int max){
	if(max == 1){
		printf("A");
		return
	}else if(max == 2){
		printf("ABA");
		return
	}else if(curr == max){
		printf("%s\n",str);
		return
	}
	
	
	strcpy(temp,str);
	
}

int main(){
	
	int T,N;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d",&N);
		printf("Case #%d: ",(i+1));
		pattern(3,N,"ABA");
		empty_str();
	}
	
	return 0;
}
