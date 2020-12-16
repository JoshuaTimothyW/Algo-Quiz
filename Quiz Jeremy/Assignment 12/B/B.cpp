#include <stdio.h>
#include <string.h>

struct Video{
	char title[1001];
	char artist[1001];
	int view;
}video[101];

void swap(struct Video *x,struct Video *y){ 
	struct Video temp = *x; 
	*x = *y; 
	*y = temp; 
}

void check(int index1, int index2){
	if( video[index1].view < video[index2].view ){
		swap(&video[index1],&video[index2]); 
		return;
	}
	
	if( video[index1].view == video[index2].view  && strcmp(video[index1].title,video[index2].title) > 0 ){
		swap(&video[index1],&video[index2]); 
		return;			
	} 
} 

void sort(int n){ 
	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			check(j,j+1);	
		} 
	} 
}

void display(int n){
	for(int i=0;i<n;i++){
		printf("%s by %s - %d\n",video[i].title,video[i].artist,video[i].view);
	} 
}

void read(){
	
	int n=0;
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		while(!feof(rd)){
			fscanf(rd,"%[^#]#%[^#]#%d\n",&video[n].title,&video[n].artist,&video[n].view);
			n++;
		}
		sort(n);
		display(n);
	}
	
	fclose(rd);
}

int main(){
	read();
    return 0;
}
    
