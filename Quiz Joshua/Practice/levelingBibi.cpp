#include <stdio.h>

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

void swap(int *x,int *y){ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
}

void quick_sort(int arr[],int l,int r) 
{ 
	int j,k; 
	if(l < r){
		j = l;
		k = r + 1;
		do{ 
			do{ j=j+1; } while(arr[j] < arr[l]); 
			do{ k=k-1; } while(arr[k] > arr[l]); 
			if(j < k) swap(&arr[j],&arr[k]); 
		}while(j <= k); 
		
		swap(&arr[l],&arr[k]); 
		quick_sort(arr,l,k-1); 
		quick_sort(arr,k+1,r); 
	}
}



int main(){
	
	int arr[] = {1,3,4,7,5,2};
	
	quick_sort(arr,0,5);
	
	for(int i=0;i<6;i++){
		printf("%d",arr[i]);
	}
	
	printf("\n");
	return 0;
}
