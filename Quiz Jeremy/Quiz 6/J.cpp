#include <stdio.h>

int main(){
	
	long long int T,A,B,C,L,R,sum;
	
	scanf("%lld",&T);
	
	for(int i=0;i<T;i++){
		scanf("%lld %lld %lld %lld %lld",&A,&B,&C,&L,&R);
		
		sum=0;
		
		while(L <= R){
			if( L%A==0 && L%B==0 && L%C==0){
				sum+=L;
			}
			L++;
		}
		
		printf("Case #%d: %lld\n",i+1,sum);
	}
	
    return 0;
}
    
