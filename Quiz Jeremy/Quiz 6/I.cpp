#include <stdio.h>

int main(){
	
	int T,N,start[100001],end[100001],count,max, arr[100001];
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		
		scanf("%d",&N);
		
		for(int j=0;j<N;j++){
			scanf("%d %d",&start[j],&end[j]);
			arr[j] = 1;
		}
		
		count=0;
		max = end[0];
		
		for(int j=1;j<N;j++){
			if(start[j] < max){
				arr[j] = arr[j-1] = 0;	
			}
			
			if(max < end[j]){
				max = end[j];
			}
		}
		
		for(int j=0;j<N;j++){
			count += arr[j];
		}
		
		printf("Case #%d: %d\n",i+1,count);
	}
	
	return 0;
}
