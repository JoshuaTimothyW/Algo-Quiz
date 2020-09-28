#include <stdio.h>

int main(){
	
	int T, N[10],index;
	char str[10][100000], temp;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%s %d",str[i],&N[i]);				
	}
	
	for(int i=0;i<T;i++){
		printf("Case #%d: ",i+1);
		
		for(int j=0;j<N[i];j++){
			if(str[i][j] >= 'A' && str[i][j] <= 'Z'){
				for(int k=j+1;str[i][k] != NULL;k++){
					if(str[i][k] >= 'a' && str[i][k] <= 'z'){
						str[i][k] -= 32;
					}else if(str[i][k] >= 'A' && str[i][k] <= 'Z'){
						str[i][k] += 32;
					}
				}
			}
			
			printf("%c",str[i][j]);
		}
		
		printf("\n");
	}
	
	return 0;
}
