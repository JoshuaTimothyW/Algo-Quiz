#include <stdio.h>
#include <string.h>

struct Plant{
	char name[50];
	char tree[50];
}plant[101];

char s[50];

int search(int n){
	for(int i=0;i<n;i++){
		if( strcmp(s,plant[i].name) == 0 ){
			return i;
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
			fscanf(rd,"%[^#]#%[^\n]\n",&plant[i].name,&plant[i].tree);
		}
		
		fscanf(rd,"%d\n",&t);
		
		for(int i=1;i<=t;i++){
			fscanf(rd,"%[^\n]\n",&s);
			index = search(n);
			printf("Case #%d: ",i);
			
			if(index == -1){
				printf("N/A");
			}else{
				printf("%s",plant[index].tree);
			}
			printf("\n");
		}
	}
	
	fclose(rd);
}

int main(){
	read();
    return 0;
}
    
