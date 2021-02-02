#include <stdio.h>
#define ll long long int

struct Number{	
	ll num;
	int index;
}arr[100001];

void swap(Number *a, Number *b){
	Number temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int n) {
	for(int i=0;i<n;i++){
		for(int j=0;j<n-(i+1);j++){
			if( arr[j].num > arr[j+1].num ){
				swap(&arr[j],&arr[j+1]);
			}
		}	
	}
}

int search(int n, ll x){
	
	int start=0,end=n-1,mid,index=-1;
	
	while(start <= end){
		
		mid = start+(end-start+1)/2;
		
		if( arr[mid].num < x ){
			start = mid+1;
		}
		else if( arr[mid].num > x ){
			end = mid-1;
		}
		else if( arr[mid].num == x ){
			index = mid;
			end = mid-1;
		}
		
	}
	
	return (index > -1) ? arr[index].index+1 : -1;
}

void display(int n){
	for(int i=0;i<n;i++){
		printf("%lld at %d\n",arr[i].num,arr[i].index);
	}
}

int main(){
	
	ll n,m,x;
	
	scanf("%lld %lld",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i].num);
		arr[i].index = i;
	}
	
	sort(n);
	
	for(int i=0;i<m;i++){
		scanf("%lld",&x);
		printf("%d\n",search(n,x));
	}
	
    return 0;
}
    
