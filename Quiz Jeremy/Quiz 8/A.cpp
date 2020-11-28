#include <stdio.h>
#define ll long long int

ll arr[41];

ll joque(ll x){
	if(arr[x] != -1){
		return arr[x];
	}
	
	arr[x] = joque(x-2)+joque(x-1)+1;
	return arr[x];
}

int main(){
	
	ll t,n;
	
	scanf("%lld",&t);
	
	for(int i=0;i<=41;i++){
		arr[i] = -1;
	}
	
	arr[0] = 2;
	arr[1] = 1;
	
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		printf("Case #%d: %lld\n",i,joque(n));
	}
	
    return 0;
}
    
