#include <stdio.h>
#define ll long long int

ll vector1[1001];
ll vector2[1001];

void swap(ll *x,ll *y){ 
	ll temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort_vector2(int start,int end) {
	int i,j;
	
	if(start < end){
		i = start;  j = end+1;
		
		do{
			do{ 
				i=i+1;
			} while(vector2[i] > vector2[start]);
			
			do{
				j=j-1;
			} while(vector2[j] < vector2[start]);
			
			if(i < j){
				swap(&vector2[i],&vector2[j]);
			}
			
		}while(i <= j);
	
	    swap(&vector2[start],&vector2[j]);
	    sort_vector2(start,j-1);
	    sort_vector2(j+1,end);
	}
}

void sort_vector1(int start,int end) {
	int i,j;
	
	if(start < end){
		i = start;  j = end+1;
		
		do{
			do{ 
				i=i+1;
			} while(vector1[i] < vector1[start]);
			
			do{
				j=j-1;
			} while(vector1[j] > vector1[start]);
			
			if(i < j){
				swap(&vector1[i],&vector1[j]);
			}
			
		}while(i <= j);
	
	    swap(&vector1[start],&vector1[j]);
	    sort_vector1(start,j-1);
	    sort_vector1(j+1,end);
	}
}

int main(){
	
	ll t,n, total;
	
	scanf("%lld",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		
		total=0;
		
		for(int j=0;j<n;j++){
			scanf("%lld",&vector1[j]);	
		}
		sort_vector1(0,n-1);
		
		for(int j=0;j<n;j++){
			scanf("%lld",&vector2[j]);	
		}
		sort_vector2(0,n-1);
		
		for(int j=0;j<n;j++){
			total += (vector1[j]*vector2[j]);
		}
		
		printf("Case #%d: %lld\n",i,total);
	}
	
    return 0;
}
    
