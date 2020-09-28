#include <stdio.h>

long long unsigned modulo = 1000000009;

long long unsigned fibo(int n){
	
	long long unsigned fibo[n+1],total; 
    
    fibo[0] = 0;
	fibo[1] = fibo[2] = 1; 
  	
  	total = (fibo[0] + fibo[1])%modulo;
  
    for (int i=2;i<=n;i++) 
    { 
        fibo[i] = (fibo[i-1]%modulo) + (fibo[i-2]%modulo); 
        total += fibo[i]%modulo; 
    } 
  
    return total; 
}


int main(){
	
	long long unsigned T,N;
	
	scanf("%llu",&T);
	
	for(int i=0;i<T;i++){
		scanf("%llu",&N);
		printf("Case #%d: %llu\n",i+1,fibo(N)%modulo);
	}
	
	return 0;
}
