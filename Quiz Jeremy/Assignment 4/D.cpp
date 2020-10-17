#include <stdio.h>

int main(){
	long long int T, N, K, A, B, X=0;
	
	scanf("%lld", &T);
	for(int i=1;i<=T;i++){
		scanf("%lld %lld", &N, &K);
		X = i;
		B=0;
		
		for(int j=1;j<=N;j++){
				scanf("%lld", &A);
			int min = N-K+1;
			if(j>=min){
				B+=A;
			}
		}
		
			printf("Case #%lld: %lld\n", X, B);
	}
	

	return 0;
}

