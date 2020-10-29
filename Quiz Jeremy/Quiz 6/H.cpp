#include <stdio.h>

int main(){
	
	long long int T,L,R,fibo[65],sum,temp,num1;
	
	fibo[0] = fibo[1] = 1;
	
	for(int j=2;j<65;j++){
		fibo[j] = fibo[j-1]+fibo[j-2];
	}
	
	scanf("%lld",&T);
	
	for(int i=0;i<T;i++){
		scanf("%lld %lld",&L,&R);
	
		sum = temp = 0;
		
		for(int j=L-1;j<R;j++){
			num1 = fibo[j];
			if( num1 > 9 ){
				temp=0;
				
				while(num1 > 0){
					temp += num1%10;
					num1/=10;
				}
				
				sum+=temp;
			}else{
				sum+=num1;
			}
		}
		
		printf("Case #%d: %lld\n",i+1,sum);		
	}

    return 0;
}
    
