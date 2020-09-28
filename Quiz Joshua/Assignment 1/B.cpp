#include <stdio.h>

int main(){
	
	float T, Ut, Ua, total=0;
	
	scanf("%f %f %f",&T,&Ut,&Ua);
	
	total = (0.2*T) + (0.3*Ut) + (0.5*Ua);
	
	printf("%.2f",total);
	
	printf("\n");
	return 0;
}
