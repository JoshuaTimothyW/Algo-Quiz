#include <stdio.h>

int main(){
	long long int N, M, Q, A, B, X, Y, cost[4], max, output[201];
	long long int xKnight[] = {-1,-2,-2,-1,1,2,2,1};
	long long int yKnight[] = {2,1,-1,-2,-2,-1,1,2};
	long long int board[201][201];
	
		
	scanf("%lld %lld", &N, &M);
	
	for(int i=0;i<201;i++){
		for(int j=0;j<201;j++){
			board[i][j] = 0;
		}	
	}
	
	for(int i=0;i<M;i++){
		scanf("%lld %lld", &X,&Y);
		board[X-1][Y-1] = 1;
	}
	
	scanf("%lld", &Q);
	
	for(int pos=0;pos<Q;pos++){
		
		scanf("%lld %lld", &A, &B);
		
		for(int i=0;i<=3;i++){
			cost[i] = 0;
		}
		
		for(int enemy=0;enemy<M;enemy++){
			
//			Knight
			for(int knight=0;knight<8;knight++){
				if( A+xKnight[knight] == X[enemy] && B+yKnight[knight] == Y[enemy]){
					cost[1]++;
				}
			}
			
//			Bishop
			if(X[enemy]-A == Y[enemy]-B){
				cost[2]++;
			}else if(-X[enemy]+A == Y[enemy]-B){
				cost[2]++;
			}
			
//			Rook
			
			
		}
		
		max=1;
		
		for(int index=1;index<=3;index++){
			if(cost[index] > cost[max]){
				max = index;
			}else if(cost[index] >= cost[max]){
				if(cost[index]-index > cost[max]-max){
					max = index;
				}
			}
		}
		
		for(int index=1;index<=3;index++){
			printf("Scoreboard : %lld ", cost[index]);
		}
		printf("\n");
//		output[j] = max;
	}	
	
//	for(int i=0;i<Q;i++){
//		printf("%lld\n", output[i]);
//	}
	
	
    return 0;
}
    
