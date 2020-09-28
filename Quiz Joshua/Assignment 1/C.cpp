#include <stdio.h>

int main(){
	
	int N,base=100,bonus=50;
	long total=0;
	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		total += base + (bonus*i);
	}
	
	printf("%lld",total);
	
	printf("\n");
	return 0;
}
