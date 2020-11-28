#include <stdio.h>
#define ll long long int

ll arr[31];

ll fib(ll x){
	if(arr[x] != -1001){
		return arr[x];
	}
	
	return fib(x-1)+fib(x-2);
}

int main(){
	
	ll first,second,n;
	
	scanf("%lld %lld",&first,&second);
	
	for(int i=0;i<31;i++){
		arr[i] = -1001;
	}
	
	arr[0] = first;
	arr[1] = second;
	
	scanf("%lld",&n);
	
	printf("%lld\n",fib(n));
	
    return 0;
}
    
