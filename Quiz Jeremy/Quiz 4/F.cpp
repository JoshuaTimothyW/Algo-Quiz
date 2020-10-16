#include <stdio.h>

int main(){
	long long int T, N, factor, pangkat;
	scanf("%lld",&T);
	
	for(int i = 1; i <= T; i++){
		scanf("%lld", &N);
		printf("Case #%d: ",i);
		
		for(int factor=2; factor*factor <= N; factor++){
			pangkat = 0;
			
			while(N % factor == 0){
				N = N/factor;
				pangkat++;
			}
			
			if(pangkat > 0){
				printf("%lld ^ %lld",factor,pangkat);
				if(N > 1){
					printf(" * ");
				}
			}
			
		}
		
		
		if(N > 1){
			printf("%lld ^ 1",N);
		}
		printf("\n");
	}

    return 0;
}
    
