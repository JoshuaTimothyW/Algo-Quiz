#include <stdio.h>

int main(){
	long long int T, N, A[10001], gap[10001], max, total, temp, jump;
	
	scanf("%lld", &T);
	
	for(int i=0;i<T;i++){
		scanf("%lld", &N);
		
		gap[0] = max = 0;
		
		for(int j=0;j<N;j++){
			scanf("%lld",&A[j]);
			if(j > 0){
				gap[j] = A[j]-A[j-1];
				
				if(max < gap[j]){
					max = gap[j];
				}
			}
			
		}
		
		if(N == 1){
			printf("Case #%lld: %lld 0\n",i+1,max);
			continue;
		}
		
		jump = max;
		total = 1;
		
		for(int j=0;j<N;j++){
			if( jump >= gap[j] ){
				jump -= gap[j];
			}else{
				total++;	
				jump = max-gap[j];			
			}
		}		
			
		printf("Case #%lld: %lld %lld\n",i+1,max,total);	
	}
    return 0;
}
    
