#include <stdio.h>
#include <string.h>

int T,N;
char arr[1001][101];


void swap(char x[],char y[]){ 
	char temp[101];
	 
	strcpy(temp,x);
	strcpy(x,y);
	strcpy(y,temp);
} 

void bublesort(int n){ 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if( strcmp(arr[j],arr[j+1]) > 0){
				swap(arr[j],arr[j+1]); 
			} 	
		} 
	} 
	
}

void display(int n){
	for(int i=0;i<n;i++){
		printf(" %s",arr[i]);
	}
	printf("\n");
}

void read(){
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		
		fscanf(rd,"%d\n",&T);
		
		for(int i=0;i<T;i++){
			fscanf(rd,"%d\n",&N);
			for(int j=0;j<N;j++){
				fscanf(rd,"%s",arr[j]);
			}
			bublesort(N);
			printf("Case #%d:",(i+1));
			display(N);
		}
	}
	
	
	fclose(rd);
	
}

	

int main(){
	read();
	
	return 0;
}
