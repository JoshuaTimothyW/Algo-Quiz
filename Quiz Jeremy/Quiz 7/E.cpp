#include <stdio.h>
#define ll long long int

ll facto(ll x){
	if(x<2){
		return 1;
	}
	
	return x*facto(x-1);
}

ll digits_permute(ll arr[], ll n){
	
	ll sum = 0;
	ll final = 0;
	ll multi = 1;
	
	for(int i=0;i<n;i++){
		sum += arr[i];
	}
	
	sum *= (facto(n)/n);
	
	for(int i=0;i<n;i++){
		final += (sum*multi);
		multi *= 10;
	}
	
	return final;
}

int main(){
	
	ll t,n,a;
	
	scanf("%lld",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		ll arr[n];
		
		for(int j=0;j<n;j++){
			scanf("%lld",&arr[j]);
		}
		
		printf("Case #%d: %lld\n",i,digits_permute(arr,n));
	}
	
    return 0;
}
    
