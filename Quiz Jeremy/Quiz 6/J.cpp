#include <stdio.h>

int main(){
	
	long long int T,A,B,C,L,R,factor,temp,sum;
	
	scanf("%lld",&T);
	
	for(int i=0;i<T;i++){
		scanf("%lld %lld %lld %lld %lld",&A,&B,&C,&L,&R);
		
		sum = factor = temp = 0;
		
		factor = (A < B) ? A : B;
		
		while(1){
			if(factor%A==0 && factor%B == 0){
				break;
			}
			factor++;
		}
		
		temp = factor;
		
		factor = (temp < C) ? temp : C;
		
		while(1){
			if(factor%temp==0 && factor%C == 0){
				break;
			}
			factor++;
		}
		
		
		if(L < factor){
			temp = factor;
		}else if(L%factor != 0){
			temp = ( (L/factor)+1 )*factor;
		}else{
			temp = L;
		}
		
		while(temp <= R){
			sum += temp;
			temp += factor;
		}
		
		printf("Case #%d: %lld\n",i+1,sum);
	}
	
    return 0;
}
    
