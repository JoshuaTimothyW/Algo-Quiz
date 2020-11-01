#include <stdio.h>

int main(){

	long long int N,K,body[1001],max,sum,index;
	
	scanf("%lld %lld",&N,&K);
	
	for(int i=0;i<N;i++){
		scanf("%lld",&body[i]);
	}
	
	for(int i=0;i<N;i++){
		sum=0;
		index = i+K-1;
		
		if( index < N ){
			for(int j=i;j<=index;j++){
				sum += body[j];
			}
			
			if(sum > max){
				max = sum;
			}
		}
		
		if(i==0){
			max = sum;
		}
	}
	
	if(max <= 0){
		printf("0\n");
	}else{
		printf("%lld\n",max);
	}

    return 0;
}
    
