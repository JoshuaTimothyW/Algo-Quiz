#include <stdio.h>
#include <string.h>

struct Email{
	char origin[101];
}arr[1001];

char filter[101];

void swap(Email *x,Email *y){ 
	Email temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort(int n){ 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if( strcmp(arr[j].origin,arr[j+1].origin) > 0 ){
				swap(&arr[j],&arr[j+1]); 
			} 	
		} 
	} 
}

int search_start(int n){
	
	int start=0,end=n-1,mid,index=-1;
	
	while(start <= end){
		
		mid = start+(end-start+1)/2;
		
		if( strcmp(arr[mid].origin,filter) == 0 ){
			index = mid;
			end = mid-1;
		}
		 
        if ( strcmp(arr[mid].origin,filter) < 0 ) { 
            start = mid+1;
      	}else if( strcmp(arr[mid].origin,filter) > 0 ) { 
            end = mid-1;
        }     
	}
	
	return index;
}

int search_end(int n){
	
	int start=0,end=n-1,mid,index=-1;
	
	while(start <= end){
		
		mid = start+(end-start+1)/2;
		
		if( strcmp(arr[mid].origin,filter) == 0 ){
			index = mid;
			start = mid+1;
		}
		 
        if ( strcmp(arr[mid].origin,filter) < 0 ) { 
            start = mid+1;
      	}else if( strcmp(arr[mid].origin,filter) > 0 ){ 
            end = mid-1;
        }     
	}
	
	return index;
}

int main(){
	
	int n,start,end;
	char domain[101];
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%[^@]@%[^\n]",domain,arr[i].origin);
	}
	scanf("%s",filter);
	
	sort(n);
	
	start = search_start(n);
	end = search_end(n);
	
	if(start == -1){
		printf("0");
	}
	else{
		printf("%d",end-start+1);
	}
	
	printf("\n");
	
    return 0;
}
    
