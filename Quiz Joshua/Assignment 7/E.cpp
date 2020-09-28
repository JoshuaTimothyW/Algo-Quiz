#include <stdio.h> 
#include <string.h> 

long long count=1;

void power(int max){
	for(int i=0;i<max;i++){
		count *= 2;
	}
} 
  

int main() 
{ 
	int N;
	
	scanf("%d",&N);
	
	power(N);
	printf("%lld\n",count-1); 

    return 0; 
} 
