#include <stdio.h>


void read(){
	
	int A, B;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		while(!feof(rd)){
			fscanf(rd,"%d %d\n",&A,&B);
		}
	}
	
	fclose(rd);
	
	printf("%d",(A+B));
}

int main(){
	
	read();
	printf("\n");
	return 0;
}
