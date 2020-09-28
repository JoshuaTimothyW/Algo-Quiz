#include <stdio.h>

int arr[1001],arr_sort[1001],min,max;

void swap(int *x,int *y){ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
}

void bublesort(int list[], int n){ 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if(list[j] < list[j+1]){
				swap(&list[j],&list[j+1]); 
			} 	
		} 
	} 
}

void calculate(int n){
	int arr_rank[101],rank=1;
	
	for(int i=0;i<n;i++){
		if(arr_sort[i] != arr_sort[i+1]){
			rank++;
		}
		
		arr_rank[arr_sort[i]] = rank;
	}
	
	for(int i=0;i<n;i++){
		if(arr[i] == max){
			printf(" 1");
		}else if(arr[i] == min){
			printf(" %d",n);
		}else{
			printf(" %d",arr_rank[arr[i]]);
		}
	}
	printf("\n");	
}

int main(){		
	
	int T,N;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d",&N);
		
		min = 100;
		max = -1;
		
		for(int j=0;j<N;j++){
			scanf("%d",arr[j]);
			arr_sort[j] = arr[j];
			
			if(arr[j] < min){
				min = arr[j];
			}
			
			if(arr[j] > max){
				max = arr[j];
			}
		}
		
		bublesort(arr_sort,N);
		printf("Case #%d:",i+1);
		calculate(N);
	}
	
	printf("\n");
	return 0;
}
