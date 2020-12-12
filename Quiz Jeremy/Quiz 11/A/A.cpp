#include <stdio.h>

void read(){
	
	int num1,num2;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d %d",&num1,&num2);
		printf("%d\n",(num1+num2));
	}
	
	fclose(rd);
}

int main(){
	read();
    return 0;
}
    
