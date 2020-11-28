#include <stdio.h>
#define ll long long int

ll arr[41];

ll joequ(ll x){
	
	if(arr[x] != -1){
		return arr[x];
	}
	
	arr[x] = 2*x + joequ(x-1) + joequ(x-2);
	return arr[x];
}

int main(){
	
	ll n;
	
	for(int i=0;i<=41;i++){
		arr[i] = -1;
	}
	
	arr[0] = 0;	
	arr[1] = 1;
	
	scanf("%lld",&n);
	printf("%lld\n",joequ(n));
	
    return 0;
}
    
