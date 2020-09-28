#include <stdio.h>

int factorial(int x){
	if(x <= 1){
		return x;
	}
	
	return x*factorial(x-1);
}

int main(){
	
	printf("%d",factorial(5));
	
	printf("\n");
	return 0;
}
