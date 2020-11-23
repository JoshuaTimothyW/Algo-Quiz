#include <stdio.h>
#define ll long long int

ll count=0;

ll lili_fibo(ll x){
	
	if(x < 2){
		return x+1;
	}
	
	if(x == 3 || x == 4){
		count++;
	}
	
	if(x%3 == 0){
		return lili_fibo(x - (x/3))+1;
	}else{
		return lili_fibo(x-1)+x+lili_fibo(x-2)+1;	
	}
	
}

int main(){
	
	ll T,N;

	scanf("%lld",&T);
	
	for(int i=1;i<=T;i++){
		scanf("%lld",&N);
		printf("Case #%lld: %lld",i,lili_fibo(N));
		printf(" %lld\n",count);
		count=0;
	}
	
    return 0;
}
    
