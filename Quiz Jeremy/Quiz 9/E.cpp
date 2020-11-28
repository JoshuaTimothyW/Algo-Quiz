#include <stdio.h>
#define ll long long int

ll vip[1001];
ll reg[1001];

ll shift_left(ll arr[],ll count, ll max, ll length){
	if(count == length){
		return max+length;
	}
	
	ll temp = arr[0];
	ll total=0;
	
	for(int i=0;i<length-1;i++){
		arr[i] = arr[i+1];
		if(arr[i] > vip[i]){
			total++;
		}
	}
	
	arr[length-1] = temp;
	
	if( arr[length-1] > vip[length-1] ){
		total++;
	}
	
	max = (total > max) ? total : max;
	
	shift_left(arr,count+1,max,length);
}

int main(){
	
	ll t,n,a;
	
	scanf("%lld",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		
		for(int j=0;j<n;j++){
			scanf("%lld",&vip[j]);
		}
		
		for(int j=0;j<n;j++){
			scanf("%lld",&reg[j]);
		}
		
		printf("Case #%d: %lld\n",i,shift_left(reg,0,0,n));		
	}

    return 0;
}
    
