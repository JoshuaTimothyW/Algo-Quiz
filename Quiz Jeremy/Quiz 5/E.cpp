#include <stdio.h>

int main(){
	long long int N, M, Q, A, B, X[200], Y[200], cost[4],max,output[200];
	long long int xKnight[] = {-1,-2,-2,-1,1,2,2,1};
	long long int yKnight[] = {2,1,-1,-2,-2,-1,1,2};
	
		
	scanf("%lld %lld", &N, &M);
	for(int i=0;i<M;i++){
		scanf("%lld %lld", &X[i], &Y[i]);
	}
	
	scanf("%lld", &Q);
	
	for(int j=0;j<Q;j++){
		scanf("%lld %lld", &A, &B);
		
		for(int i=0;i<=3;i++){
			cost[i] = 0;
		}
		
		for(int enemy=0;enemy<M;enemy++){
			
			for(int k=0;k<8;k++){
				if(A+xKnight[k] == X[enemy] && B+yKnight[k] == Y[enemy]){
					cost[1]++;
				}
			}
			
			if(X[enemy]-A == Y[enemy]-B){
				cost[2]++;
			}else if(-X[enemy]+A == Y[enemy]-B){
				cost[2]++;
			}
			
		}
		
		max=1;
		
		for(int l=1;l<=3;l++){
			if(cost[l] > cost[max]){
				max = l;
			}else if(cost[l] >= cost[max]){
				if(cost[l]-l > cost[max]-max){
					max = l;
				}
			}
		}
		
		for(int i=1;i<=3;i++){
			printf("Scoreboard : %lld ", cost[i]);
		}
		printf("\n");
//		output[j] = max;
	}	
	
//	for(int i=0;i<Q;i++){
//		printf("%lld\n", output[i]);
//	}
	
	
    return 0;
}
    
