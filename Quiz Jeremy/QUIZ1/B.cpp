#include <stdio.h>

int main(){
	long long int N, Y;
	scanf("%lld", &N);
	for(int i=0;i<N;i++){
		scanf("%lld", &Y);
		for(int j=0;j<9;j++){
			
			if(j == Y-1){
				printf("#");
			 	}
			else{
				printf(".");
				}
		}
		printf("\n");

	}	
	
	return 0;
}
