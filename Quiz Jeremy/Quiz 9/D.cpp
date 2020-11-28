#include <stdio.h>

int arr[21][21];

int count_step(int step, int row, int col){
	
	if( arr[row-1][col] == 0 ){
		arr[row-1][col] = 1;
		return count_step(step+1,row-1,col);
	}else if( arr[row+1][col] == 0 ){
		arr[row+1][col] = 1;
		return count_step(step+1,row+1,col);
	}else if( arr[row][col-1] == 0 ){
		arr[row][col-1] = 1;
		return count_step(step+1,row,col-1);
	}else if( arr[row][col+1] == 0 ){
		arr[row][col+1] = 1;
		return count_step(step+1,row,col+1);
	}else{
		return step;
	}
}

int main(){
	
	int n,m;
	int row_start, col_start;
	char cell;
	
	scanf("%d %d",&n,&m); getchar();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%c",&cell); 
			
			if(cell == 'S' || cell == '#'){
				arr[i][j] = 1;
				if(cell == 'S'){
					row_start = i;
					col_start = j;	
				}
			}else{
				arr[i][j] = 0;
			}
		}
		getchar();
	}
	
	printf("%d\n",count_step(0,row_start,col_start));
	
    return 0;
}
    
