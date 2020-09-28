#include <stdio.h>


// Sample Read Function
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

//Swap by int
// Parameter reference
void swap(int *x,int *y){ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
}

// Swap by long long
void swap(long long *x,long long *y){ 
	long long temp = *x; 
	*x = *y; 
	*y = temp; 
} 

//Bubblesort for int
void bublesort(int list[], int n){ 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if(list[j] > list[j+1]){
				swap(&list[j],&list[j+1]); 
			} 	
		} 
	} 
}

// Quick Sort
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

// Quick Sort PPT Version
// Left is first index and right is last index
void quick_sort(int arr[],int l,int r) 
{ 
	int j,k; 
	if(l < r){
		j = l;
		k = r + 1;
		do{ 
		
//			Change 2 compare signs below for descending
			do{ j=j+1; } while(arr[j] < arr[l]); 
			do{ k=k-1; } while(arr[k] > arr[l]); 
			if(j < k) swap(&arr[j],&arr[k]); 
		}while(j <= k); 
		
		swap(&arr[l],&arr[k]); 
		quick_sort(arr,l,k-1); 
		quick_sort(arr,k+1,r); 
	}
}

// Regular Binary Search
int binary_search(int arr[],int n,long long target){
	
	int l=0,r=n,mid=0;
	
	while(l < r){
		
		mid = (l+r)/2;
		
		if(arr[mid] == target) return mid;
		 
        if (target < arr[mid]) { 
            r = mid;
      	}else { 
            l = mid + 1;
        }     
	}
}

int main(){
	
	
	printf("\n");
	return 0;
}
