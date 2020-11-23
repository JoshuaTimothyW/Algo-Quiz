#include <stdio.h>
#define ll long long int

ll max;

ll infinite(ll start, ll end){
	for(int i=3;i<=5;i++){
		if(start*i > end){
			return -1;
		}
		
		if(start*i > max){
			max = start*i;
		}
	}
	
	for(int i=3;i<=5;i++){
		infinite(start*i,end);
	}
}


int main(){
	
	ll T,x,l;
	
	scanf("%lld",&T);
	for(int i=1;i<=T;i++){
		scanf("%lld %lld",&x,&l);
		max=x;
		infinite(x,l);
		printf("Case #%lld: %lld\n",i,max);
	}
	
    return 0;
}
    
