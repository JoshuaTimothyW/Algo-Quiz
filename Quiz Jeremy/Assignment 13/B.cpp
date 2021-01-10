#include <stdio.h>

int arr[101];

int max=-1;

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

int search(int n,int x){
	
	int start=0,end=n-1,mid;
	
	if(x < arr[start]){
		return -1;
	}else if(x > arr[end]){
		return -1;
	}
	
	while(start <= end){
		
		mid = (start+end)/2;
		
		if( arr[mid] == x ){
			return mid;
		}
		 
        if ( arr[mid] < x ) { 
            start = mid+1;
      	}else { 
            end = mid-1;
        }     
	}
	
	return -1;
}

int main(){
	
	int n,m,num,index,gap;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	sort(0,n-1);
	
	for(int i=0;i<m;i++){
		scanf("%d",&num);
		index = search(n,num);
		
		while(index > -1){
			for(int i=index;i<n-1;i++){
				arr[i] = arr[i+1];
			}
			n--;
			index = search(n,num);
		}
	}
	
	if(n > 0){
		max = arr[n-1];	
	}
	
	printf("Maximum number is %d\n",max);
	
    return 0;
}
    
