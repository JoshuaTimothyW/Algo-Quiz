#include <stdio.h>

int main(){
	
	int T, N[100], M[100];
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d %d",&N[i],&M[i]);
	}
	
	for(int i=0;i<T;i++){
		printf("Case #%d:\n",i+1);
		
		for(int j=0;j<N[i];j++){
			for(int k=0;k<M[i];k++){
				if(j == 0 || j == N[i]-1 || k == 0 || k == M[i]-1){
					printf("#");
				}else{
					printf(" ");
				}
			}
			printf("\n");
		}
		
	}
	
	return 0;
}
