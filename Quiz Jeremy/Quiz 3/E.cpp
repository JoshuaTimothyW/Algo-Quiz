#include <stdio.h>

int main(){
	
	long long int N, S, A, B, C, K, total;
	scanf("%lld %lld %lld %lld %lld", &N, &S, &A, &B, &C);
	
	K = (A/S)*(B/S)*(C/S);
	total = N/K;
	
	if(N%K != 0){
		total += 1;
	}
	
	
	printf("%lld\n", total);
	

    return 0;
}
    
