#include <stdio.h>

int main(){
	double A, B, C;
	for(int i=0;i<4;i++){
		
		scanf("%lf %lf",&A, &B);
		C = (100/(100-A))*B;
			printf("$%.2lf\n", C);	
	}


	
	return 0;
}
