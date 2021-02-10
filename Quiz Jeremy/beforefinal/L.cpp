#include <stdio.h>
#define ll long long int

ll arr[30001];

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
			} while( arr[i] < arr[start] );
			
			do{
				j=j-1;
			} while( arr[j] > arr[start] );
			
			if(i < j){
				swap(&arr[i],&arr[j]);
			}
			
		}while(i <= j);
	
	    swap(&arr[start],&arr[j]);
	    sort(start,j-1);
	    sort(j+1,end);
	}
}

ll search_min(ll n,ll x){
	
	ll start=0,end=n-1,mid;
	
	if( x > arr[end] ){
		return -1;
	}

	while(start <= end){
		
		mid = (start+end)/2;
		
		if( arr[mid] >= x ){
			if( arr[mid-1] < x && mid > 0 ){
				return mid;
			}
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	
	return mid;
}

ll search_max(ll n,ll x){
	
	ll start=0,end=n-1,mid;
	
	if( x < arr[start] ){
		return -1;
	}
	
	while(start <= end){
		
		mid = (start+end)/2;
		
		if( arr[mid] <= x ){
			if( arr[mid+1] > x && mid < n-1 ){
				return mid;
			}
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	
	return mid;
}

int main(){
	
	ll t,n,q,start,end,index1,index2,sum;
	
	scanf("%lld",&t);
	
	for(int i=0;i<t;i++){
		
		scanf("%lld",&n);
		
		for(int j=0;j<n;j++){
			scanf("%lld",&arr[j]);
		}
		
		sort(0,n-1);
		
		scanf("%lld",&q);
		
		ll list_sum[q];
		
		for(int j=0;j<q;j++){
			scanf("%lld %lld",&start,&end);
			
			sum=0;
			
			index1 = search_min(n,start);
			index2 = search_max(n,end);
			
//			printf("index : %lld %lld\n",index1,index2);
			
			if(index1 < 0 || index2 < 0){
				sum = 0;
			}
			else{
				while( index1 < index2 ){
					sum += arr[index1]+arr[index2];
					index1++;
					index2--;	
				}
				
				if(index1 == index2){
					sum += arr[index1];
				}
			}
				
			list_sum[j] = sum;
		}
		
		printf("Case #%d:\n",i+1);
		
		for(int j=0;j<q;j++){
			printf("%lld\n",list_sum[j]);
		}
		
	}
	
    return 0;
}
    
