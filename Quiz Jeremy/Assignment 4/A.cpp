#include <stdio.h>

int main(){
	long long int T, A, B, P, X=0;
	scanf("%lld", &T);
	for(int i=1;i<=T;i++){
		scanf("%lld %lld", &A, &B);
		X = i;
		if(A>B){
			printf("Case #%lld: Go-Jo\n", X, A, B);
		}
		if(B>A){
			printf("Case #%lld: Bi-Pay\n", X, A, B);
		}
		
	}
	
	
	
	
	return 0;
}
