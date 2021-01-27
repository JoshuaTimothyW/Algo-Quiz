#include <stdio.h>
#define ll long long int

ll arr[100001];

void swap(ll *x,ll *y){ 
	ll temp = *x; 
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

int search_start(int n, ll x){
	int start=0,end=n-1,mid,index=-1;
	
	while(start <= end){
		mid = start+(end-start+1)/2;
		
		if(arr[mid] == x){
			index = mid;
			end = mid-1;
		}
		else if(arr[mid] < x){
			start = mid+1;
		}
		else if(arr[mid] > x){
			end = mid-1;
		}
	}
	
	return index;
}

int search_end(int n, ll x){
	int start=0,end=n-1,mid,index=-1;
	
	while(start <= end){
		mid = start+(end-start+1)/2;
		
		if(arr[mid] == x){
			index = mid;
			start = mid+1;
		}
		else if(arr[mid] < x){
			start = mid+1;
		}
		else if(arr[mid] > x){
			end = mid-1;
		}
	}
	
	return index;
}

int main(){
	
	int n,q,start,end;
	ll num;
	
	scanf("%d %d",&n,&q);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	
	for(int i=0;i<q;i++){
		scanf("%lld",&num);
		start = search_start(n,num);
		end = search_end(n,num);
		
		if(start == -1){
			printf("0");
		}
		else{
			printf("%d",end-start+1);
		}
		printf("\n");
	}
	
    return 0;
}
    
