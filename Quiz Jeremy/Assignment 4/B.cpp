#include <stdio.h>

int main(){
	long long int T, A, N, Even,Odd;
	
	scanf("%lld", &T);
	
	for(int i=1;i<=T;i++){
		scanf("%lld", &N);
		Even = Odd = 0;
		
		for(int j=1;j<=N;j++){
			scanf("%lld", &A);
			
			if(A%2 == 0){
				Even++;						
			}else{
				Odd++;
			}
		}	
				
		printf("Odd group : %lld integer(s).\n", Odd);
		printf("Even group : %lld integer(s).\n\n", Even);
	}
	
	return 0;
}
