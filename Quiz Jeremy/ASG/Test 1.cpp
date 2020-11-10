#include <stdio.h>

long long int rumus(long long int angka, long long int pangkat){
	if(pangkat == 0){
		return 1;
	}else if(pangkat%2 == 0){
		return rumus(angka, pangkat/2)*rumus(angka, pangkat/2);
	}else {
		return angka*rumus(angka, pangkat/2)*rumus(angka, pangkat/2);
	}
	
}
int main(){
	long long int A, B, C;
	scanf("%lld %lld", &A, &B);


	C = rumus(A, B);
	printf("%lld\n", C);
	
	return 0;
}
