#include <stdio.h>
#define ll long long int

ll ori[1001];
ll permute[1001];
ll list_index[1001];

void swap(ll *a,ll *b){
	ll temp = *a;
	*a = *b;
	*b = temp;
}

ll sort(ll n){ 
	
	ll count=0;

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if(list_index[j] > list_index[j+1]){
				swap(&list_index[j],&list_index[j+1]);
				count++;	
			}
		} 
	}
	
	return count; 
}

int main(){
	
	ll n;
	
	scanf("%lld",&n);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&permute[i]);
	}
	
	for(int i=0;i<n;i++){
		scanf("%lld",&ori[i]);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if( permute[i] == ori[j] ){
				list_index[i] = j;
			}
		}	
	}
	
	printf("%lld\n",sort(n));
	
    return 0;
}
    
