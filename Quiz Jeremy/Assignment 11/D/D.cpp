#include <stdio.h>
#include <string.h>

char str[101];
char *word;

struct Dictionary{
	char src[51];
	char dst[51];
}dict[101];

void extract(int n){
	int index,space=0;
	word = strtok(str," ");
	
	while( word != NULL){
		if(space > 0){
			printf(" ");
		}
		
		index = -1;
		
		for(int i=0;i<n;i++){
			if( strcmp(dict[i].src,word) == 0 ){
				index = i;
				break;
			}
		}
		
		if( index == -1 ){
			printf("%s",word);
		}else{
			printf("%s",dict[index].dst);
		}
		
		word = strtok(NULL," ");
		space++;
	}
	printf("\n");
}

void read(){
	
	int t,n;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d\n",&t);
		
		for(int i=0;i<t;i++){
			fscanf(rd,"%[^#]#%[^\n]\n",&dict[i].src,&dict[i].dst);
		}
		
		fscanf(rd,"%d\n",&n);
		
		for(int i=1;i<=n;i++){
			fscanf(rd,"%[^\n]\n",&str);
			printf("Case #%d:\n",i);
			extract(t);
		}
	}
	
	fclose(rd);
}

int main(){
	read();	
	
    return 0;
}
    
