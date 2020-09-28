#include <stdio.h>
#define MAX 100000

int main(){
	
	long long N, P, b[MAX], count;
	
	scanf("%ld %ld",&N,&P);
	
	for(int i=0;i<N;i++){
		scanf("%ld",&b[i]);	
	}
	
	count=0;
	for(int i=0;i<N;i++){
		if(P > b[i]){
			count++;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
