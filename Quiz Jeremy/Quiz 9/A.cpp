#include <stdio.h>
#define ll long long int

ll plant(ll total,ll count, ll max){
	if(count == max){
		return total;
	}
	
	ll a;
	
	scanf("%lld",&a);
	
	total+=a;
	
	return plant(total,count+1,max);
}

int main(){
	
	ll t,n,total;
	
	scanf("%lld",&t);
	
	for(int i=1;i<=t;i++){
		total = 0;
		scanf("%lld",&n);
		total = plant(total,0,n);
		printf("Case #%lld: %lld\n",i,total);
	}
	
    return 0;
}
    
