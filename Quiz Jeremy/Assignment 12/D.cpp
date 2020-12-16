#include <stdio.h>

int arr[100001];

void swap(int *x,int *y){ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort(int start,int end) {
	int i,j;
	
	if(start < end){
		i = start;  j = end+1;
		
		do{
			do{ 
				i=i+1;
			} while(arr[i] < arr[start]);
			
			do{
				j=j-1;
			} while(arr[j] > arr[start]);
			
			if(i < j){
				swap(&arr[i],&arr[j]);
			}
			
		}while(i <= j);
	
	    swap(&arr[start],&arr[j]);
	    sort(start,j-1);
	    sort(j+1,end);
	}
}


int search(int x, int n){
	
	int start=0,end=n-1,mid;
	
	if(x < arr[start]){
		return -1;
	}else if(x > arr[end]){
		return -1;
	}
	
	while(start <= end){
		mid = (start+end)/2;
		
		if(arr[mid] == x){
			return mid+1;
		}
		
		if(arr[mid] < x){
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
	
	return -1;
}

int main(){
	
	int n,q,x;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	sort(0,n-1);
	
	scanf("%d",&q);
	
	for(int i=0;i<q;i++){
		scanf("%d",&x);
		printf("%d\n",search(x,n));
	}
	
	
    return 0;
}
    
