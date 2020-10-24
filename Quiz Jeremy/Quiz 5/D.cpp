#include <stdio.h>

int main(){
	long long int T, N, A[1000], B, C;
	
	scanf("%lld", &T);
	
	for(int i=0;i<T;i++){
		scanf("%lld", &N);
		
		for(int j=0;j<N;j++){
			scanf("%lld", &A[j]);	
		}
		
		printf("Case #%lld:", i+1);
		
		for(int k=N-1;k>0;k-=2){
			printf(" %lld %lld", A[k-1], A[k]);
		}
		printf("\n");	
	}
			
		
	
	
    return 0;
}
    
