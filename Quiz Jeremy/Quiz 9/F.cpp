#include <stdio.h>
#define ll long long int

ll arr[21];

ll power(ll x, ll n){
	if(n == 0){
		return 1;
	}
	
	return x*power(x,n-1);
}

ll sum(ll total, ll start, ll end){
	if(start > end){
		return total;
	}
	
	total += arr[start];
	
	return sum(total,start+1,end);
}

int main(){
	
	ll t,n,m;
	
	scanf("%lld",&t);
	
	for(int i=0;i<20;i++){
		arr[i] = power(2,i);
	}
	
	for(int i=1;i<=t;i++){
		scanf("%lld %lld",&n,&m);
		printf("Case #%lld: %lld\n",i,sum(0,n-1,m-1));
	}
	
    return 0;
}
    
