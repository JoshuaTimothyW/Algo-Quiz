#include <stdio.h>

struct Array{
	int value;
	int index;
}arr[100001];

void swap(struct Array *x,struct Array *y){ 
	struct Array temp = *x; 
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
			} while(arr[i].value < arr[start].value);
			
			do{
				j=j-1;
			} while(arr[j].value > arr[start].value);
			
			if(i < j){
				swap(&arr[i],&arr[j]);
			}
			
		}while(i <= j);
	
	    swap(&arr[start],&arr[j]);
	    sort(start,j-1);
	    sort(j+1,end);
	}
}

int search_max(int x, int n){
	
	int start=0,end=n-1,mid;
	
	if(x < arr[0].value){
		return -1;
	}
	
	while(start <= end){
		
		mid = (start+end)/2;
		
		if(arr[mid].value == x){
			return mid;
		}
		
		if( x < arr[mid].value ){
			end = mid-1;
		}else{
			start = mid+1;
		}
	}
	
	return start;
}

void display(int n){
	for(int i=0;i<n;i++){
		printf("value: %d, index: %d\n",arr[i].value,arr[i].index);
	}
}

int main(){
	
	int n,m,x;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i].value);
		arr[i].index = i;
	}
	display(n);
	
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		printf("%d\n",search_max(x,n));
	}
	
    return 0;
}
    
