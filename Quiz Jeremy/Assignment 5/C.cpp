#include <stdio.h>

int main(){
long long int T, N, A[100000];
scanf("%lld", &T);
	for(int i=0;i<T;i++){
		scanf("%lld", &N);
		for(int j=0;j<N;j++){
			scanf("%lld", &A[j]);	
		}
		printf("Case #%lld: ", i+1);
		for(int k=1;N-k;k++){
			printf("%lld ", A[k]);
		}
		printf("%lld\n", A[0]);
	}

    return 0;
}
    
