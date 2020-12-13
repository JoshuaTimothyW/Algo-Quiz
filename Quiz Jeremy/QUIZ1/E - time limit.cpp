#include <stdio.h>

int main(){
	long long int N, M, arr[100002], L, R,total,sum,start,end;
	
	scanf("%lld %lld", &N, &M);
	
	
	for(int i=1;i<=N;i++){
		scanf("%lld", &arr[i]);
		if(i%2 == 0){
			arr[i] = 0;
		}else{
			sum += arr[i];
		}	
	}
	
	for(int i=0;i<M;i++){
		scanf("%lld %lld", &L, &R);		
		total = 0;
		start = 1;
		end = N;
		
		if(L == R){
			printf("%lld\n",arr[L]);
			continue;
		}
		
		for(int j=start;j<=L;){
			
		}
		
		if(L == R){
			total += arr[L];
		}
		
		printf("%lld\n",total);
	}
	return 0;	
}
