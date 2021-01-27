#include <stdio.h>
#include <string.h>

char board[31][31];
char str[31];
int n,flag,length;
int list_row[] = {1,-1,0,0};
int list_col[] = {0,0,1,-1};

int out(int row, int col){
	if(row < 0 || row > n-1 || col < 0 || col > n-1){
		return 1;
	}
	
	return 0;
}

int explore(int count, int row, int col, int pos_row, int pos_col, int index){
	
	if( out(pos_row,pos_col) || count == length ){
		return count;
	}
	else if(board[pos_row][pos_col] != str[index]){
		return 0;		
	}
	
	return explore(count+1,row,col,pos_row+row,pos_col+col,index+1);
}

void find_word(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(board[i][j] == str[0]){
				
				for(int k=0;k<4;k++){
					
					flag = explore(0,list_row[k],list_col[k],i,j,0);
					
					if(flag == length){
						printf("YES");
						return;
					}	
				}		
			}
		}
	}
	
	printf("NO");
}

int main(){
	
	scanf("%d %s",&n,str); getchar();
	
	length = strlen(str);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%c",&board[i][j]);
		}
		getchar();	
	}
	find_word();
	printf("\n");	
    return 0;
}
    
