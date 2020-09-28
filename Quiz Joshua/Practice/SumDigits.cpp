#include <stdio.h>

int sum(int x){
	if(x < 1){
		return 0;
	}
	
	return (x%10) + sum(x/10);
}

int main(){
	
	printf("%d",sum(1938));
	
	printf("\n");
	return 0;
}
