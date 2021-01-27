#include <stdio.h>

struct Divisor{
	int ori;
	int sum;
}arr[1001];

int divisor(int n){
	
	int res=0; 
  
    for (int i=2; i*i<=n; i++) 
    { 
        if( n%i == 0 ) 
        { 
            if( i == (n/i) ){
            	res += i; 	
			} 
            else{
            	res += (i + n/i);	
			} 
        } 
    } 
  	
  	if(n > 1){
  		return (res+n+1);	
	}
	  	
    return res+1; 
}

void swap(Divisor *x,Divisor *y){ 
	Divisor temp = *x; 
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
			} while(arr[i].sum < arr[start].sum);
			
			do{
				j=j-1;
			} while(arr[j].sum > arr[start].sum);
			
			if(i < j){
				swap(&arr[i],&arr[j]);
			}
			
		}while(i <= j);
	
	    swap(&arr[start],&arr[j]);
	    sort(start,j-1);
	    sort(j+1,end);
	}
}

int main(){
	
	int n;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i].ori);
		arr[i].sum = divisor(arr[i].ori);	
	}
	
	sort(0,n-1);
	
	printf("%d",arr[0].ori);
	for(int i=1;i<n;i++){
		printf(" %d",arr[i].ori);
	}
	printf("\n");
	
    return 0;
}
    
