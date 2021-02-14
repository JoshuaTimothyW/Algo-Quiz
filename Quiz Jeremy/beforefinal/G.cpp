#include <stdio.h>
#define ll long long int

struct Divisor{
	ll ori;
	ll sum;
}arr[1001];

ll divisor(ll n){
	
	ll result = 1;
	
	if( n == 1 ){
		return result;
	}
	
	for(int i=2;i*i <= n;i++){
		if( n%i == 0 ) 
        { 
            if( i == (n/i) ){
            	result += i; 	
			} 
            else{
            	result += (i + n/i);	
			} 
        } 
	}
	
	return result+n;
}

void swap(Divisor *x,Divisor *y){ 
	Divisor temp = *x; 
	*x = *y; 
	*y = temp; 
}

int check(int index1, int index2){
	if( arr[index1].sum == arr[index2].sum ){
		 return arr[index1].ori > arr[index2].ori;
	}
	
	 return arr[index1].sum > arr[index2].sum;
}

void sort(int n){ 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<n-(i+1);j++){
			if( check(j,j+1) ){
				swap(&arr[j],&arr[j+1]);
			}
		} 
	} 
}

int main(){
	
	ll n;
	
	scanf("%lld",&n);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i].ori);
		arr[i].sum = divisor(arr[i].ori);
	}
	
	sort(n);
	
	for(int i=0;i<n-1;i++){
		printf("%lld ",arr[i].ori);	
	}
	printf("%lld\n",arr[n-1].ori);
	
	return 0;
}
