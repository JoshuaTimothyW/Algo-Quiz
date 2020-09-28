#include <stdio.h>

struct Film{
	int kode;
	char judul[60];
	int rank;
}film[110];

int count=0,T,N;

void search(int x){
	for(int i=0;i<count;i++){
		if(x == film[i].rank){
			printf("Kode: %d\n",film[i].kode);
			printf("Judul: %s\n",film[i].judul);
		}
	}
}

void read(){
	
	FILE *rd = fopen("testdata.in","r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		while(!feof(rd)){
			fscanf(rd,"%d\n",&T);
			
			for(int i=0;i<T;i++){
				fscanf(rd,"%d#%[^#]#%d\n",&film[count].kode,&film[count].judul,&film[count].rank);
				count++;
			}
			
			fscanf(rd,"%d\n",&T); 
			
			for(int i=0;i<T;i++){
				fscanf(rd,"%d\n",&N);
				printf("Case #%d:\n",i+1);
				search(N);
			}
		}
	}
	
	fclose(rd);
}

int main(){
	
	read();
	return 0;
}
