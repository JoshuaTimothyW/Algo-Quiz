#include <stdio.h>

int jobo(int x){
	if(x <= 0){
		return 0;
	}
	
	if(x <= 2){
		return 1;
	}
	
	return jobo(x-1)+jobo(x-3);
}

int main(){
	
	int N;
	
	scanf("%d",&N);
	printf("%d",jobo(N));
	
	printf("\n");
	return 0;
}
