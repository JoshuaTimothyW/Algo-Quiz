#include <stdio.h>
#define ll long long int

struct Array{
	ll value;
	ll rank;
	ll index;
}arr[1001];

void swap(struct Array *x,struct Array *y){ 
	struct Array temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort_value(ll start,ll end) {
	ll i,j;
	
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
	    sort_value(start,j-1);
	    sort_value(j+1,end);
	}
}

void sort_index(ll start,ll end) {
	ll i,j;
	
	if(start < end){
		i = start;  j = end+1;
		
		do{
			do{ 
				i=i+1;
			} while(arr[i].index < arr[start].index);
			
			do{
				j=j-1;
			} while(arr[j].index > arr[start].index);
			
			if(i < j){
				swap(&arr[i],&arr[j]);
			}
			
		}while(i <= j);
	
	    swap(&arr[start],&arr[j]);
	    sort_index(start,j-1);
	    sort_index(j+1,end);
	}
}

void rank(ll n){
	ll rank = 1;
	ll curr = arr[0].value;
	
	for(int i=0;i<n;i++){
		if(curr == arr[i].value){
			arr[i].rank = rank;	
		}else{
			rank++;
			curr = arr[i].value;
			arr[i].rank = rank;	
		}
		
	}
}

void display(ll n){
	for(int i=0;i<n;i++){
		printf(" %lld",arr[i].rank);
	}
	printf("\n");
}

int main(){
	
	ll t,n;
	
	scanf("%lld",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		
		for(int j=0;j<n;j++){
			scanf("%lld",&arr[j].value);
			arr[j].index = j;
		}
		
		sort_value(0,n-1);

		rank(n);

		sort_index(0,n-1);

		printf("Case #%d:",i);
		display(n);		
	}

    return 0;
}
    
