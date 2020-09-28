#include <stdio.h>

int arr[] = {13,648,321,48,333,9486,4576};

int getClosest(int val1, int val2, int target){ 
    if (target - arr[val1] >= arr[val2] - target) 
        return val2; 
    else
        return val1; 
} 

int binary_search(int n,int target){
	
	int l=0,r=n,mid=0;
	
	while(l < r){
		
		mid = (l+r)/2;
		
		if (arr[mid] == target) 
            return arr[mid]; 
            
        if (target < arr[mid]) { 
  
            if (mid > 0 && target > arr[mid - 1]) 
                return getClosest(mid - 1,mid, target); 
  
            r = mid; 
        }else { 
            if (mid < n - 1 && target < arr[mid + 1]) 
                return getClosest(mid,mid + 1, target); 

            l = mid + 1;  
        }  
		
	}
	
}

int main(){
	int n= sizeof(arr) / sizeof(arr[0]);
	printf("%d",binary_search(n,325));
	// 333
	
	
	return 0;
}
