#include <stdio.h>
#include <string.h>
#define get getchar();

char arr[10][30];
int count=0;

void swap(char *x, char *y){
	char temp[21];
	
	strcpy(temp,x);
	strcpy(x,y);
	strcpy(y,temp);
	
}

void swap_active(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int is_empty(){
	for(int i=0;i<count;i++){
		if(strcmp(arr[i],"")){
			return i;
		}
	}
	
	return -1;
}


int main(){
	
	int arr[] = {1,2,3,4,5,6,7,8,9,NULL};
	
	for(int i=9;i>=0;i--){
		swap_active(&arr[i],&arr[i-1]);
	}
	
	for(int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}
