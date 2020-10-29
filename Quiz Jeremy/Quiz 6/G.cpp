#include <stdio.h>

int main(){
	long long int T, N, A[10000], min, total, temp, index, gap;
	
	scanf("%lld", &T);
	
	for(int i=0;i<T;i++){
		scanf("%lld", &N);
		
		for(int j=0;j<N;j++){
			scanf("%lld", &A[j]);
		}
		
		min = -1;
		
		for(int j=0;j<N;j++){
			gap = A[j+1]-A[j]; 
			if( gap > min ){
				min = gap;
			}	
		}
		
		index = 0;
		temp = total = 0;
		
		while(index < N){
			gap = A[index+1]-A[index];
			
			if( temp >= gap ){
				temp -= gap;
				index++;
			}
			else{
				temp = min;
				total++;
			}
		}
			
		printf("Case #%lld: %lld %lld\n",i+1,min,total);	
	}
    return 0;
}
    
