#include <stdio.h>
int main(){
long long int N, K, D, A=0;
	scanf("%lld %lld %lld", &N, &K, &D);
	while(N>=K){
		A+=K;
		N-=K+1;		
	}
	A = (A+N)*D;
	printf("%lld\n", A);
	
	return 0;
}
