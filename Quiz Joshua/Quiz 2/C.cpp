#include <stdio.h>

long long T,N,min,max,case_num=1;
long long arr[1000],arr_sorted[1000];

void swap(long long *x,long long *y){ 
	long long temp = *x; 
	*x = *y; 
	*y = temp; 
} 

void bubblesort(long long list[],long long n){ 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if(list[j] < list[j+1]){
				swap(&list[j],&list[j+1]); 
			} 	
		} 
	} 
}

void calculate(long long n){
	
	long long arr_rank[n+1];
	long long rank = 1;
	
	for(int i=0;i<n;i++){
		
		if(arr_sorted[i] != arr_sorted[i-1]){
			
			if(arr_sorted[i] == max){
				rank = 1;	
			} 
			else if(arr_sorted[i] == min){
				rank = n;
			}
			else{
				rank++;
			}
			
			arr_rank[arr_sorted[i]] = rank;			
		}
	}
	
	for(int i=0;i<n;i++){
		printf(" %lld",arr_rank[arr[i]]);
	}
	
	printf("\n");
}

int main(){
	
	scanf("%lld",&T);
	
	for(int i=0;i<T;i++){
		scanf("%lld",&N);
		
		min = 101;
		max = 0;
		
		for(int j=0;j<N;j++){
			scanf("%lld",&arr[j]);
			
			arr_sorted[j] = arr[j];
			
			if(arr[j] < min){
				min = arr[j];
			}
			
			if(arr[j] > max){
				max = arr[j];
			}
			
		}
		printf("Case #%d:",i+1);
		
		bubblesort(arr_sorted,N);
		calculate(N);
	}
	
	return 0;
}
