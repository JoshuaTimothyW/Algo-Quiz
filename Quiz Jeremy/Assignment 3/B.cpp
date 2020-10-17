#include <stdio.h>

int main(){

double A, B, C, D=1;
	scanf("%lf %lf", &A, &B);
	C = (1+(B/100));

		
	for(int i=0;i<3;i++){
		D*=C;
	}
	
	D*=A;


	printf("%.2lf\n",D);
	
	
	
}
