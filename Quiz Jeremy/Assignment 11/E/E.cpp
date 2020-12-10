#include <stdio.h>

char matrix[501][501];
int min_row, min_col, max_row, max_col;

void check(int row, int col){
	
	if(min_row > row){
		min_row = row;
	}
	
	if(max_row < row){
		max_row = row;
	}
	
	if(min_col > col){
		min_col = col;
	}
	
	if(max_col < col){
		max_col = col;
	}
}

void display(){
	for(int row=min_row;row<=max_row;row++){
		for(int col=min_col;col<=max_col;col++){
			printf("%c",matrix[row][col]);
		}
		printf("\n");
	}
}

void read(){
	
	int t,n,m;
	
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d\n",&t);
		
		for(int i=1;i<=t;i++){
			min_row = min_col = 501;
			max_row = max_col = -1;
			
			fscanf(rd,"%d %d\n",&n,&m);
			
			for(int j=0;j<n;j++){
				for(int k=0;k<m;k++){
					fscanf(rd,"%c",&matrix[j][k]);
					if(matrix[j][k] != '.'){
						check(j,k);
					}
				}
				fscanf(rd,"\n");
			}
			
			printf("Case #%d:\n",i);
			printf("%d %d\n",(max_row-min_row)+1,(max_col-min_col)+1);
			display();
		}
	}
	
	fclose(rd);
}

int main(){
	read();
    return 0;
}
    
