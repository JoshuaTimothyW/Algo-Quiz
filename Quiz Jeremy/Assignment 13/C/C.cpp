#include <stdio.h>
#include <string.h>

struct Student{
	char nim[11];
	char name[21];
}arr[101];

char target[11];

int search(int n){
	
	int l=0,r=n,mid=0;
	
	while(l < r){
		
		mid = (l+r)/2;
		
		if( strcmp(arr[mid].nim,target) == 0 ) return mid;
		 
        if ( strcmp(target,arr[mid].nim) < 0 ) { 
            r = mid;
      	}else { 
            l = mid + 1;
        }     
	}
	
	return -1;
}

void read(){
	
	int n,t,index;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d\n",&n);
		
		for(int i=0;i<n;i++){
			fscanf(rd,"%s %[^\n]\n",&arr[i].nim,&arr[i].name);
		}
		
		fscanf(rd,"%d\n",&t);
		
		for(int i=1;i<=t;i++){
			fscanf(rd,"%s\n",target);
			index = search(n);
			
			if( index == -1){
				printf("Case #%d: N/A\n",i);
			}else{
				printf("Case #%d: %s\n",i,arr[index].name);
			}
		}
	}
	
	fclose(rd);
}

int main(){

	read();

    return 0;
}
    
