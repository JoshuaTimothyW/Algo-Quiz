#include <stdio.h>

long long int isBigger(long long int a, long long int b){
	return (a > b) ? a : b;
}

int main(){
	
	long long int T,arr[1000],max[1000],gap,size,N,max_gap;
	
	scanf("%lld",&T);
	
	for(int i=0;i<T;i++){
		scanf("%lld %lld",&size,&N);
		max[i]=0;
		
		for(int j=0;j<size;j++){
			scanf("%lld",&arr[j]);
		}
		
		for(int j=0;j<size;j++){
			for(int k=j+1;k<=j+N;k++){
				if(k == size){
					break;
				}
				gap = arr[k]-arr[j];
				
				if(gap < 0){
					gap*=-1;
				}
				
				max[i] = isBigger(gap,max[i]);
			}
		}
	}
	
	max_gap = max[0];
	
	for(int i=0;i<T;i++){
		printf("%lld ",max[i]);
	}
	
	for(int i=1;i<T;i++){
		max_gap = isBigger(max[i],max[i-1]);
	}	
	
	printf("%lld\n",max_gap);
	
    return 0;
}
    
