#include <stdio.h>
#define ll long long int

ll tillOne(ll x){
	if(x < 2){
		return x;
	}
	
	if(x%2 == 0){
		return tillOne(x/2);
	}else{
		return tillOne(x-1)+tillOne(x+1);
	}
}

int main(){
	
	ll t,n;
	
	scanf("%lld",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		printf("Case #%d: %lld\n",i,tillOne(n));
	}
	
    return 0;
}
    
