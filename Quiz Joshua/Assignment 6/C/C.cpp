#include <stdio.h>

int N,M;
int list_price[10000], list_money[50000];

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

int binary_search(int n,int target){
	
	int l=0,r=n,mid=0;
	
	if(target < list_price[0]){
		return 0;
	}else if(target > list_price[n-1]){
		return n;
	}
	
	while(l < r){
		
		mid = (l+r)/2;
		 
        if (target < list_price[mid]) { 
  
            if (mid > 0 && target > list_price[mid - 1]) 
                return mid; 
  
            r = mid;
			 
        }else { 
        
            if (mid < n - 1 && target < list_price[mid + 1]) 
                return mid+1; 

            l = mid + 1;
			  
        }     
         
	}
	
}

void calculate(){
	
	int count;
	
	for(int i=0;i<M;i++){
		
		count=binary_search(N,list_money[i]);
		
		printf("Query #%d: %d\n",(i+1),count);	
	}
}

void read(){
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d %d\n",&N,&M);
		for(int i=0;i<N;i++){
			fscanf(rd,"%d",&list_price[i]);
		}
		for(int i=0;i<M;i++){
			fscanf(rd,"%d",&list_money[i]);
		}
		quickSort(list_price,0,N-1);
		calculate();
		
	}
	
	fclose(rd);
	
}

int main(){
	read();
	
	return 0;
}
