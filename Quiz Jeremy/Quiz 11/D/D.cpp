#include <stdio.h>
#include <string.h>

int count,n;
int arr[11];

char str[100];
char *word;

void check(){
	if(strstr(str,"#") != NULL){
		arr[n] = count;
		n++;
		count=0;
		return;
	}
	
	word = strtok(str," ");
   
	while( word != NULL ) {
		count++;
		word = strtok(NULL," ");
	}
	
}

void read(){
	
	int x,mark;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		n=0;
		mark=0;
		
		fscanf(rd,"%d\n",&x);
		
		while(!feof(rd)){
			fscanf(rd,"%[^\n]\n",&str);
			check();
		}
		
		for(int i=0;i<n;i++){
			if(arr[i] < x){
				printf("page %d: %d word(s)\n",i+1,arr[i]);
				mark++;
			}
		}
		
		if(mark < 1){
			printf("The essay is correct\n");
		}
	}
	
	fclose(rd);
}

int main(){
	read();
	
    return 0;
}
    
