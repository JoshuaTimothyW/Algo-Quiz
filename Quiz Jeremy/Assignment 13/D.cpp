#include <stdio.h>
#define ll long long int

ll search(ll target){
	
	ll start=0,end=target,mid;
	double result,min;
	
	while(start <= end){
		
		mid = (start+end)/2;
		
		result = (double)mid*(mid+1)*(2*mid+1)/6.0;
		 
        if( result >= target ){ 
            end = mid-1;
			min = mid;
      	}
		else { 
			start = mid+1;
        }
		     
	}
	
	return min;
}


int main(){
	
	int t;
	ll target;
	
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%lld",&target);
		printf("Case #%d: %lld\n",i,search(target));
	}
	
    return 0;
}
    
