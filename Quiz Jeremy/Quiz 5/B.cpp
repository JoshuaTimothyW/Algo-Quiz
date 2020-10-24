#include <stdio.h>

int main(){
	long long int N, Q, V[101], A, B, total;
	scanf("%lld", &N);
	for(int i=1;i<=N;i++){
		scanf("%lld", &V[i]);
		}
	scanf("%lld", &Q);
	for(int j=1;j<=Q;j++){
		scanf("%lld %lld", &A, &B);
			total = 0;
			for(int k=A;k<=B;k++){
				total += V[k];
				
			}
			printf("Case #%lld: %lld\n", j, total);
		
	}
	
	
    return 0;
}
