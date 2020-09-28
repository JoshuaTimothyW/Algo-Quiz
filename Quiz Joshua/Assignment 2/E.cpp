#include <stdio.h>

int main(){
	
	int T;
	int min,mid,max;
	char arr[100][3];
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%s %s %s",&arr[i][0],&arr[i][1],&arr[i][2]);
	}
	
	for(int i=0;i<T;i++){
		
		min = max = 0;
		
		for(int j=0;j<3;j++){
			if( arr[i][j] < arr[i][min] ){
				min = j;
			}
			
			if( arr[i][j] > arr[i][max]){
				max = j;
			}
		}
		
		mid = 3 - max - min;
		
		printf("Case #%d: %c %c %c\n",i+1,arr[i][min],arr[i][mid],arr[i][max]);
	}
	
	return 0;
}
