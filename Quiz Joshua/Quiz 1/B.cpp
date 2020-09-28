#include <stdio.h>
#define MAX 100000

int main(){
	
	int T, N[MAX],  index, temp,count;
	long long arr[10][MAX];
	
	scanf("%d",&T);

	for(int i=0;i<T;i++){
		scanf("%d",&N[i]);
		
		for(int j=0;j<N[i];j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	for(int i=0;i<T;i++){
		
		printf("Case #%d:\n",i+1);
		temp=0;
		
		for(int a=0;a<N[i];a++){
			for(int b=0;b<N[i];b++){
				if(arr[i][b] > arr[i][a]){
					temp = arr[i][a];
					arr[i][a] = arr[i][b];
					arr[i][b] = temp;
				}
			}
		}
		
		index=0;
		
		while(index < N[i]){
			count=1;
			printf("%d ",arr[i][index]);
			
			while(arr[i][index] == arr[i][index+1]){
				index++;
				count++;
			}
			
			printf("%d\n",count);
			index++;
		}
	}
	
	
	
	return 0;
}
