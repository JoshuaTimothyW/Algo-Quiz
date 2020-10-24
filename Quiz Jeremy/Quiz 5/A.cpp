#include <stdio.h>

int main(){

long long int T, N, V, A, B, total;
scanf("%lld", &T);
	for(int i=1;i<=T;i++){
		
		scanf("%lld", &N);
		A = B = -1000000;
		
		for(int j=1;j<=N;j++){
			scanf("%lld", &V);
			
			if(V>A){
				B = A;
				A = V;
			}else if(V>B && V<=A){
				B = V;
			}
			
		}
		printf("Case #%lld: %lld\n",i ,(A+B));
	}


	
	return 0;
}
