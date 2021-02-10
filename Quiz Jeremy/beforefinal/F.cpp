#include <stdio.h>
#define ll long long int

ll arr[100001];

ll search(ll num,ll n, ll total){
	
	ll start=0,end=n-1,index,mid;
	
	if( arr[end]+num <= total ){
		return end;
	}
	
	while(start <= end){
		
		mid = (start+end)/2;
		
		if( arr[mid]+num <= total && mid < n-1 ){
			if( arr[mid+1]+num > total ){
				return mid;
			}
			else{
				start = mid+1;
			}
		}
		else if( arr[mid]+num > total ){
			end = mid-1;
		}
	}
	
	return -1;
}

int main(){
	
	ll n,total,max,sum,index;
	
	scanf("%lld %lld",&n,&total);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	
	max = -1;
	
	for(int i=0;i<n;i++){
		
		index = search(arr[i],n,total);
		
		if( arr[index] == arr[i] || index == -1 ){
			sum = -1;
		}
		else{
			sum = arr[i]+arr[index];
		}
		
		if(sum > max ){
			max = sum;
		}
	}
	
	printf("%lld\n",max);
	
    return 0;
}
    
