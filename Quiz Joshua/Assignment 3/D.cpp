#include <stdio.h>

int main(){
	
	int T,N[10];
	char str[10][200];
	int count=0;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d",&N[i]);
		while( (getchar()) != '\n' );
		scanf("%[^\n]",str[i]);
	}
	
	for(int i=0;i<T;i++){
		count=0;
		printf("Case #%d: ",i+1);
		while(count < N[i]){
			printf("%c",str[i][count]);
			
			if(str[i][count] == ' '){
				do{
					count++;
				}while(str[i][count] != ' ');		
			}
			count++;			
		}
		printf("\n");
	}
	
	return 0;
}
