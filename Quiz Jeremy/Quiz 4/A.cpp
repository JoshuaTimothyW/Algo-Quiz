#include <stdio.h>

int main(){
long long int a, b, c, d, hasil1, hasil2;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	hasil1 = a*b;
	hasil2 = c+d;
	if(hasil1 > hasil2){
		printf("True\n");
	}else{
		printf("False\n");
	}
    return 0;
}
    
