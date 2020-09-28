#include <stdio.h>

int main(){
	
	long long a,b,c,d;
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	
	if( (a*b) > (c+d) ){
		printf("True");
	}else{
		printf("False");
	}

	printf("\n");
	return 0;
}
