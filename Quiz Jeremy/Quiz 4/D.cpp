#include <stdio.h>

int main(){
	long long int N, X, Y, Z, sum_ganjil=0, sum_genap=0, hasil;
	scanf("%lld %lld %lld",&N, &X, &Y);
	
	for(int i=0; i<N; i++){
		scanf("%lld", &Z);
		if(Z%2 == 1){
			sum_ganjil += Z;
		}

		if(Z%2 == 0){
			sum_genap += Z;
		}
	}
		sum_ganjil*=X;
		sum_genap*=Y;
		
	printf("%lld\n", sum_ganjil+sum_genap);
	
    return 0;
}
    
