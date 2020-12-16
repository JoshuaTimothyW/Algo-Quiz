#include <stdio.h>
#define ll long long int

double arr[5001];

void swap(double *x,double *y){ 
	double temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort(ll n){ 
	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}	
		} 
	} 
}

int main(){
	
	ll t,n;
	double total,median;
	
	scanf("%lld",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		
		total = 0;
		
		for(int j=0;j<n;j++){
			scanf("%lf",&arr[j]);
			total += arr[j];
		}
		
		printf("Case #%d:\n",i);
		printf("Mean : %.2lf\n",total/n);
		
		sort(n);
		
		if(n%2 == 1){
			median = arr[n/2];
		}else{
			median = ( arr[n/2] + arr[(n/2)-1] )/2;
		}
		
		printf("Median : %.2lf\n",median);
	}
	
    return 0;
}
    
