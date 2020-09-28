#include <stdio.h>

int main(){
	
	int T,N[100];
	char S[100][100];
	int bibi,lili;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d",&N[i]);
		scanf("%s",S[i]);
	}
	
	for(int i=0;i<T;i++){
		
		bibi = lili = 0;
		
		for(int j=0;j<N[i];j++){
			if(S[i][j] == 'L'){
				lili++;	
			}else if(S[i][j] == 'B'){
				bibi++;
			}else{
				lili++; bibi++;
			}
		}
		
		if(lili > bibi){
			printf("Lili");
		}else if(lili < bibi){
			printf("Bibi");
		}else{
			printf("None");
		}
		
		printf("\n");	
	}
	
	return 0;
}
