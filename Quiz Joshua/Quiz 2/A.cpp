#include <stdio.h>
#include <string.h>
#define get getchar();
#define MAX 10000

long long T,N;
char jojo[MAX], lili[MAX];

void read(){
	
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		while(!feof(rd)){
			fscanf(rd,"%d\n",&T);
			
			for(int i=0;i<T;i++){
				fscanf(rd,"%d\n",&N);
				
				for(int j=0;j<N;j++){
					
				}
			}
		}
	}
	
	fclose(rd);
	
	printf("%d",(A+B));
}

int main(){
	
	
	return 0;
}
