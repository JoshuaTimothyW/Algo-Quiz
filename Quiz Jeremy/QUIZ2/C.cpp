#include <stdio.h>

int arr[30001];

int search_min(int x, int n){
	
	int start=0,end=n-1,mid;
	
	while(start <= end){
		
		mid = (start+end)/2;
		
		if(arr[mid] == x){
			return mid;
		}
		
		if( x < arr[mid] ){
			end = mid-1;
		}else{
			start = mid+1;
		}
	}
	
	return start;
}

int search_max(int x, int n){
	
	int start=0,end=n-1,mid;
	
	while(start <= end){
		
		mid = (start+end)/2;
		
		if(arr[mid] == x){
			return mid;
		}
		
		if( x > arr[mid] ){
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
	
	return end;
}

int main(){

	int n,q,min,max,min_index,max_index;

	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	scanf("%d",&q);
	
	for(int i=0;i<q;i++){
		scanf("%d %d",&min,&max);
		
		min_index = max_index = 0;
		
		if(min > arr[n-1] || max < arr[0]){
			printf("Case #%d: 0\n",i+1);
			continue;
		}
		
		min_index = search_min(min,n);
		max_index = search_max(max,n);
		
		if(max_index-min_index > -1){
			printf("Case #%d: %d\n",i+1,max_index-min_index+1);	
		}
		else{
			printf("Case #%d: 0\n",i+1);
		}
		
	}

    return 0;
}
    
