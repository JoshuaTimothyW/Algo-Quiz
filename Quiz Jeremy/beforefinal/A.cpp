#include <stdio.h>
#include <string.h>

struct Station{
	char id[21];
	char src[101];
	char dst[101];
	char time[6];
}arr[1001];

char id[21];

void swap(Station *x,Station *y){ 
	Station temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort(int start,int end) {
	int i,j;
	
	if(start < end){
		i = start;  j = end;
		
		do{
			do{ 
				i=i+1;
			} while( strcmp(arr[i].id,arr[start].id) < 0 );
			
			do{
				j=j-1;
			} while( strcmp(arr[j].id,arr[start].id) > 0 );
			
			if(i < j){
				swap(&arr[i],&arr[j]);
			}
			
		}while(i <= j);
	
	    swap(&arr[start],&arr[j]);
	    sort(start,j-1);
	    sort(j+1,end);
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
	
	sort(0,t);
	
	for(int i=0;i<t;i++){
		scanf("%s ",id);
		index = search(t);
		scanf("%s %s",arr[index].src,arr[index].dst); getchar();
		printf("%s\n",index);
	}
	
	for(int i=0;i<t;i++){
		printf("%s %s %s %s\n",arr[i].id,arr[i].time,arr[i].src,arr[i].dst);
	}
		
    return 0;
}
    
