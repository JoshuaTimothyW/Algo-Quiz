#include <stdio.h>

int main(){
	
	int T, N[101], j;
	char msg[101][1001], temp;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d",&N[i]);
		getchar();
		scanf("%[^\n]",msg[i]);
	}
	
	for(int i=0;i<T;i++){
		j=0;
		printf("Case #%d: ",i+1);
			
		while(msg[i][j] != '\0'){
			temp = msg[i][j];
			
			if(temp >= 65 && temp <= 90){
				
				if(temp+N[i] > 90){
					temp = ( (temp-65+N[i]) %26) + 65;
				}else{
					temp += N[i];
				}
				
			}else if(temp >= 97 && temp <= 122){
				
				if(temp+N[i] > 122){
					temp = ( (temp-97+N[i]) %26) + 97;
				}else{
					temp += N[i];
				}
				
			}
			
			printf("%c",temp);
			j++;
		}
		printf("\n");
	}
	
	return 0;
}
