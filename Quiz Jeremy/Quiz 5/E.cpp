#include <stdio.h>

int main(){
	long long int N, M, Q, A, B, X, Y;
	
	long long int knightX[] = {-1,-2,-2,-1,1,2,2,1};
	long long int knightY[] = {2,1,-1,-2,-2,-1,1,2};
	
	long long int enemyX[210], enemyY[210];
	
	long long int board[210][210];
	
	long long int posX, posY, cost[4], max, output[210];

		
	scanf("%lld %lld", &N, &M);
	
	for(int i=0;i<210;i++){
		for(int j=0;j<210;j++){
			board[i][j] = 0;
		}	
	}
	
	for(int i=0;i<M;i++){
		scanf("%lld %lld", &X,&Y);
		enemyX[i] = X;
		enemyY[i] = Y;
		board[X][Y] = 1;
	}
	
	scanf("%lld", &Q);
	
	for(int pos=0;pos<Q;pos++){
		
		scanf("%lld %lld", &A, &B);
		
		for(int i=0;i<=3;i++){
			cost[i] = 0;
		}
		
		for(int i=0;i<M;i++){
			posX = enemyX[i];
			posY = enemyY[i];
			
			
			for(int knight=0;knight<8;knight++){
				if( A+knightX[knight] == enemyX[i] && B+knightY[knight] == enemyY[i]){
					cost[1]++;
				}
			}
			

			if(enemyX[i]-A == enemyY[i]-B){
				
				
				if(posX > A){
					do{
						posX--;
						posY++;
					}while(posX > A && board[posX][posY] == 0);

				}else{
					do{
						posX++;
						posY++;
					}while(posX < A && board[posX][posY] == 0);
				}
			}else if(-enemyX[i]+A == enemyY[i]-B){

				if(posX > A){
					do{
						posX--;
						posY--;
					}while(posX > A && board[posX][posY] == 0);
				}else{

					do{
						posX++;
						posY--;
					}while(posX < A && board[posX][posY] == 0);
				}
			}
			
			if(posX == A && posY == B){
				cost[2]++;
			}
			
			
			posX = enemyX[i];
			posY = enemyY[i];
			
			if(posY == B){
					if(posX < A){
						do{
							posX++;
						}while(posX < A && board[posX][posY] == 0);
					}else{
						do{
							posX--;
						}while(posX > A && board[posX][posY] == 0);
					}
			}else if(posX == A){
					if(posY < B){
						do{
							posY++;
						}while(posY < B && board[posX][posY] == 0);
					}else{
						do{
							posY--;
						}while(posY > B && board[posX][posY] == 0);
					}
			}
			
			if(posX==A && posY==B){
				cost[3]++;
			}
			
		}
		
		max=1;
		
		for(int index=1;index<=3;index++){
			if( cost[index]-index > cost[max]-max ){
				max = index;
			}else if( cost[index]-index == cost[max]-max ){
				if(cost[index] > cost[max]){
					max = index;
				}
			}
		}
		
		output[pos] = max;
	}	
	
	for(int i=0;i<Q;i++){
		printf("%lld\n", output[i]);
	}
	
	
    return 0;
}
    
