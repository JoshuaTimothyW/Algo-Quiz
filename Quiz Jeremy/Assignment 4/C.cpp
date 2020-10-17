#include <stdio.h>

int main(){
	long long int T, N, A, total1, total2;
	scanf("%lld %lld", &T, &N);
	A = 0;
	
	total1=0;
	for(int i=1;i<=T;i++){
		scanf("%lld", &A);
		
		if(A%N == 0){
			total1++;
		}
	}
	printf("%lld\n", total1);
		
	
	
	return 0;
}
