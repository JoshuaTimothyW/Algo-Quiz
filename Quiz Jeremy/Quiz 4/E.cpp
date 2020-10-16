#include <stdio.h>


int main(){
	long long int T, N, A, total, result;
	scanf("%lld",&T);
		
	for(int i=1;i<=T;i++){
		scanf("%lld",&N);
		total = result = 0;
				
		for(int j=1;j<=N;j++){
			scanf("%lld",&A);
			total += A;
			
			if(result > total){
				result = total;
			}
		}
		
		if(result < 0){
			result *= -1;
		}
		
		printf("Case #%d: %lld\n",i,result+1);
	}
	
    return 0;
}
    
