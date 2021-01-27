#include <stdio.h>
#include <string.h>

struct Destiny{
	char src[101];
	char dst[101];
}temp;

struct Station{
	char id[21];
	char time[6];
	Destiny station;	
}arr[1001];

char id[21];

void swap(Station *x,Station *y){ 
	Station temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort(int n) {
	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if( strcmp(arr[j].id,arr[j+1].id) > 0 ){
				swap(&arr[j],&arr[j+1]); 
			} 	
		} 
	} 
}

int search(int n){
	
	int start=0,end=n-1,mid;
	
	while(start <= end){
		
		mid = (start+end)/2;
		
		if( strcmp(arr[mid].id,id) == 0 ){
			return mid;
		}
		 
        if ( strcmp(arr[mid].id,id) < 0 ) { 
            start = mid+1;
      	}else { 
            end = mid-1;
        }     
	}
	
	return -1;
}


int main(){
	
	int t,index;
	
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		scanf("%s %s",arr[i].id,arr[i].time); getchar();
	}
	
	sort(t);
	
	for(int i=0;i<t;i++){
		scanf("%s %s %s",id,temp.src,temp.dst); getchar();
		index = search(t);
		
		if(index > -1){
			arr[index].station = temp;
		}
	}
	
	for(int i=0;i<t;i++){
		printf("%s %s",arr[i].id,arr[i].time);
		printf(" %s %s\n",arr[i].station.src,arr[i].station.dst);
	}
		
    return 0;
}
    
