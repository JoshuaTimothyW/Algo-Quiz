#include <stdio.h>

int matrix[100][100];
int arr[100];

void clear(){
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			matrix[i][j] = 0;
		}	
	}
}

void fill(int n){
	for(int i=0;i<n;i++){
		for(int col=0;col<arr[i];col++){
			matrix[i][col] = 1;
		}
	}
}

int check(int row, int col){
	int count=0;
	
	if(row > 0 && matrix[row-1][col]){
		count++;
	}
	
	if(row < 99 && matrix[row+1][col]){
		count++;
	}
	
	if(col > 0 && matrix[row][col-1]){
		count++;
	}
	
	if(col < 99 && matrix[row][col+1]){
		count++;
	}
	
	return count;
}

int perimeter(int n){
	int total=0;
	
	for(int row=0;row<n;row++){
		for(int col=0;col<arr[row];col++){
			if(matrix[row][col]){
				total += ( 4 - check(row,col) );
			}
		}
	}
	
	return total;	
}

void read(){
	
	int t,n,area;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d\n",&t);
		
		for(int i=1;i<=t;i++){
			clear();
			area=0;
			
			fscanf(rd,"%d\n",&n);
			
			for(int j=0;j<n;j++){
				fscanf(rd,"%d",&arr[j]);
				area += arr[j];
			}
			fill(n);
			printf("Case #%d: %d %d\n",i,2*perimeter(n),4*area);	
		}
	}
	
	fclose(rd);
}

int main(){
	
	read();
	
    return 0;
}
    
