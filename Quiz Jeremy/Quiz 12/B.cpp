#include <stdio.h>
#include <string.h>

struct Data{
	char name[51];
	int number;
}data[101];

void swap(struct Data *x,struct Data *y){ 
	struct Data temp = *x; 
	*x = *y; 
	*y = temp; 
}

void check(int index1, int index2){
	if( data[index1].number > data[index2].number ){
		swap(&data[index1],&data[index2]); 
		return;
	}
	
	if( data[index1].number == data[index2].number &&  strcmp(data[index1].name,data[index2].name) > 0 ){
		swap(&data[index1],&data[index2]);
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

int main(){
	
	int t,n;
	scanf("%d",&t); getchar();
	
	for(int i=1;i<=t;i++){
		scanf("%d",&n); getchar();
	
		for(int j=0;j<n;j++){
			scanf("%[^#]#%d",&data[j].name,&data[j].number); getchar();
		}	
		
		sort(n);
		
		printf("Case #%d:\n",i);
		
		for(int j=0;j<n;j++){
			printf("%s - %d\n",data[j].name,data[j].number);
		}
	}
	
    return 0;
}

