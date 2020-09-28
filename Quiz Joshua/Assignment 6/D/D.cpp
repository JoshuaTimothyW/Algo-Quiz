#include <stdio.h>

int N,M,arr_enemy[50001],arr_player[50001];
long long total=0,curr=0,index=0;

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
	
	if(target < arr_enemy[0]){
		return 0;
	}else if(target > arr_enemy[n-1]){
		return n;
	}
	
	while(l < r){
		
		mid = (l+r)/2;
		 
        if (target < arr_enemy[mid]) { 
  
            if (mid > 0 && target > arr_enemy[mid - 1]) 
                return mid; 
  
            r = mid;
			 
        }else { 
        
            if (mid < n - 1 && target < arr_enemy[mid + 1]) 
                return mid+1; 

            l = mid + 1;
			  
        }     
         
	}
	
}

void calculate(){
	
	int max_index=0,index=0;
	
	for(int i=0;i<M;i++){
		
		if(arr_player[i] != arr_player[i-1]){

			max_index = binary_search(N,arr_player[i]);
			
			for(int j=index;j<max_index;j++){
				curr += arr_enemy[j];
			}
			
			index = max_index;
			
		}
		
		total += curr;
	}
}

void read(){
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d %d\n",&N,&M);
		
		for(int i=0;i<M;i++){
			fscanf(rd,"%d ",&arr_player[i]);
		}
		
		quickSort(arr_player,0,M-1);
				
		for(int i=0;i<N;i++){
			fscanf(rd,"%d ",&arr_enemy[i]);
		}
		
		calculate();
		
		printf("%lld\n",total);
	}
	
	fclose(rd);
	
}

int main(){
	
	read();
	
	return 0;
}
