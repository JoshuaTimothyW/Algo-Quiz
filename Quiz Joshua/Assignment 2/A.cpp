#include <stdio.h>

int main(){
	
	int T, N[10];
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d",&N[i]);
	}
	
	for(int i=0;i<T;i++){
		printf("Case #%d:\n",i+1);
		
		for(int j=N[i];j>0;j--){
			printf("%d",j);
			if(j == N[i] || j == 60 || j == 30 || j == 10 || j == 5){
				printf(" SECONDS TILL NEW YEAR!!");
			}
			printf("\n");	
		}
		
	}
	
	return 0;
}
