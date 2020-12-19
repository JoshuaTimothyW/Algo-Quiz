#include <stdio.h>
#define ll long long int

struct Polynomial{
	ll a;
	ll b;
	ll c;
	ll n;
}poly[100001];

void compare(int index){
	ll start=1,end=1000000,mid,result;
	
	while(start <= end){
		result=0;
		
		mid = (start+end)/2;
		
		result += poly[index].c*mid;
		
		result += poly[index].b*mid*mid;
		
		result += poly[index].a*mid*mid*mid;
		
		if( result <= poly[index].n ){
			start = mid+1;
		}else{
			end = mid-1;
		}
		
	}
	
	printf("%lld\n",start-1);
}

int main(){
	
	ll m;
	
	scanf("%lld",&m);
	
	for(int i=0;i<m;i++){
		scanf("%lld",&poly[i].a);
	}
	
	for(int i=0;i<m;i++){
		scanf("%lld",&poly[i].b);
	}
	
	for(int i=0;i<m;i++){
		scanf("%lld",&poly[i].c);
	}
	
	for(int i=0;i<m;i++){
		scanf("%lld",&poly[i].n);
		compare(i);
	}
	
    return 0;
}
    
