#include <stdio.h>
#include <string.h>

int isGood(char str[]){
	
	for(int i=0;str[i]!=NULL;i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] += 32;
		}
	}
	
	
	if(strstr(str,"good")){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	
	int T;
	char S[81];
	
	scanf("%d",&T);
	getchar();
	for(int i=0;i<T;i++){
		scanf("%[^\n]",S);
		getchar();
		printf("Case #%d: %s\n",(i+1),(isGood(S) ? "yes" : "no" ));
	}
	
	return 0;
}
