#include <stdio.h>

int arr[15];

int pow(int x,int y){
	if(arr[y] != -1){
		return arr[y];
	}
	
	arr[y] = x*pow(x,y-1);
	
	return arr[y];
}

int main(){
	
	int n,max,space;
	
	scanf("%d",&n);
	
	for(int i=0;i<15;i++){
		arr[i] = -1;
	}
	
	arr[0] = 1;

	for(int i=n,j=1;i>0;i--,j++){
		space = pow(2,j-1)-1;
		max = pow(2,i)-1;
		
		for(int a=0;a<max;a++){
			for(int b=0;b<space;b++){
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}
	
    return 0;
}
    
