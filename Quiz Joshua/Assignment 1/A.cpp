#include <stdio.h>

int main(){
	
	char N[100], A[9];
	int U;
	
	gets(N);
	scanf("%s %d",&A,&U);
	
	printf("Name: %s\nNIS: %s\nAge: %d",N,A,U);
	
	printf("\n");
	return 0;
}
