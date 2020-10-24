#include <stdio.h>

int main(){
	long long int N, K, A[1001], B[1001],count;

	scanf("%lld %lld", &N, &K);
	
	for(int i=0;i<N;i++){
		scanf("%lld", &A[i]);
	}
	
	for(int i=0;i<N;i++){
		scanf("%lld", &B[i]);
	}
	
	count=0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(A[i] + B[j] == K){
				count++;
			}		
		}	
	}
	
	printf("%lld\n",count);
	
    return 0;
}
    
