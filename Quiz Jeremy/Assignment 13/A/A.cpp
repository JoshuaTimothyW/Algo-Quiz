#include <stdio.h>
#include <string.h>

struct Plant{
	int num;
	char name[41];
}arr[1000];

void swap(struct Plant *x,struct Plant *y){ 
	struct Plant temp = *x; 
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
			} while( strcmp(arr[i].name,arr[start].name) < 0 );
			
			do{
				j=j-1;
			} while( strcmp(arr[j].name,arr[start].name) > 0 );
			
			if(i < j){
				swap(&arr[i],&arr[j]);
			}
			
		}while(i <= j);
	
	    swap(&arr[start],&arr[j]);
	    sort(start,j-1);
	    sort(j+1,end);
	}
}

void read(){
	
	int n;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d\n",&n);
		
		for(int i=0;i<n;i++){
			fscanf(rd,"%d#%[^\n]\n",&arr[i].num,&arr[i].name);
		}
		
		sort(0,n-1);
		
		for(int i=0;i<n;i++){
			printf("%d %s\n",arr[i].num,arr[i].name);
		}
	}
	
	fclose(rd);
}

int main(){
	read();
    return 0;
}
    
