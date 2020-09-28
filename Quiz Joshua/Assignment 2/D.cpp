#include <stdio.h>

int main(){
	
	int T, N[10];
	int count;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d",&N[i]);
	}
	
	for(int i=0;i<T;i++){
		printf("Case #%d:\n",i+1);
		
		for(int j=0;j<=N[i];j++){
			count=0;
			
			for(int i=2;i<=j;i++){
				if(j%i == 0){
					count++;
				}		
			}
			
			if(count == 1){
				printf("I will become a good boy.\n");
			}		
		}
	}
	
	return 0;
}
