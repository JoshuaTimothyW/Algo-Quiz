#include <stdio.h>
#define ll long long int

ll epic_game(ll turn, ll n){
	if(n == 1){
		return !turn;
	}
	
	if(n%2 == 0){
		n/=2;
	}else{
		n = (n*3)+1;
	}
	
	return epic_game(!turn,n);
}

int main(){
	
	ll t,n;

	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		printf("Case #%d: %s\n",i,(epic_game(0,n) == 0) ? "Jojo" : "Lili");
	}
	
    return 0;
}
    
