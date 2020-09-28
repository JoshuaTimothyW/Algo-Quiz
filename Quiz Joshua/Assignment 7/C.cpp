#include <stdio.h>
#define get getchar();

void swap(int *x,int *y){ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

double get_median(int arr[],int n){
	if (n % 2 != 0) 
       return (double)arr[n/2]; 
      
    return (double)(arr[(n-1)/2] + arr[n/2])/2.0; 
}


int main(){
	
	int T, N;
	int arr[5000];
	double mean, median;
	long long sum;
	
	scanf("%d",&T); get
	
	for(int i=0;i<T;i++){
		
		scanf("%d",&N); get
		
		sum=0;
		
		for(int j=0;j<N;j++){
			scanf("%d",&arr[j]); get
			sum += arr[j];
		}
		
		quickSort(arr,0,N-1);
		
		median = get_median(arr,N);
		mean = (double)sum/(double)N;
		
		printf("Case #%d:\n",(i+1));
		printf("Mean : %.2lf\n",mean);
		printf("Median : %.2lf\n",median);
		
	}
	
	return 0;
}
