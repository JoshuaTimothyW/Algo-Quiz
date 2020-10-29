#include <stdio.h>

int main(){
	long long int T,N,schedule[100001],count,prev_start, prev_end, curr_start, curr_end;
	
	scanf("%lld",&T);
	
	for(int i=0;i<T;i++){
		scanf("%lld",&N);
		
		count=0;
		
		schedule[0] = 1;
		scanf("%lld %lld",&prev_start,&prev_end);
		
		if(N == 1){
			printf("Case #%d: %lld\n",i+1,1);
			continue;
		}
		
		for(int j=1;j<N;j++){
			schedule[j] = 1;
			scanf("%lld %lld",&curr_start,&curr_end);
			
			if(curr_start < prev_end){
				schedule[j-1] = schedule[j] = 0;
			}
			
			prev_start = curr_start;
			prev_end = curr_end;	
		}
		
		for(int j=0;j<N;j++){
			count += schedule[j];
		}
		
		printf("Case #%d: %lld\n",i+1,count);
	}
	
    return 0;
}
    
