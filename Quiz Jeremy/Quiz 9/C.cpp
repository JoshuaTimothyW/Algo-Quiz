#include <stdio.h>

struct Knight{
	int row;
	int col;
	int step;
}knight[1000];

int end;

int knight_row[] = {-1,-2,-2,-1,1,2,2,1};
int knight_col[] = {2,1,-1,-2,-2,-1,1,2};

int board[8][8];

void clear(){
	for(int i=0;i<end;i++){
		knight[i].row=0;
		knight[i].col=0;
		knight[i].step=0;
	}
}

int is_valid(int curr){
	if(knight[curr].row < 0 || knight[curr].col < 0 || knight[curr].row > 7  || knight[curr].col > 7){
		return 0;
	}
	
	return 1;
}

int min_step(int curr,int target_row, int target_col){
	
	int row = knight[curr].row;
	int col = knight[curr].col;
	
	if(curr > end){
		return 0;
	}
	
	if( is_valid(curr)==1 && board[row][col] == 0 ){
		
		if(row == target_row && col == target_col){
			return knight[curr].step;
		}
		
		board[row][col]=1;
		
		for(int i=0;i<8;i++){
			end++;
			knight[end].row = row + knight_row[i];
			knight[end].col = col + knight_col[i];			
			knight[end].step = knight[curr].step+1;
		}
	}
	
	min_step(curr+1,target_row,target_col);
}

int main(){
	
	char x1,x2;
	int t,y1,y2;
	
	scanf("%d",&t); getchar();
	
	for(int i=1;i<=t;i++){
		
		for(int j=0;j<8;j++){
			for(int k=0;k<8;k++){
				board[j][k] = 0;
			}
		}
		
		scanf("%c%d %c%d",&x1,&y1,&x2,&y2); getchar();
		x1 = (int)x1-65;
		y1-=8;
		
		end = 0;
		
		if(y1<0){
			y1 *= -1;
		}
		
		x2 = (int)x2-65;
		y2-=8;
		
		if(y2<0){
			y2 *= -1;
		}
		
		knight[0].row = y1;
		knight[0].col = x1;
		knight[0].step = 0;
		
		printf("Case #%d: %d\n",i,min_step(0,y2,x2));
		clear();
	}
	
    return 0;
}
    
