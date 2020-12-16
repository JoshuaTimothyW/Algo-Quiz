#include <stdio.h>
#include <string.h>

struct Member{
	char name[51];
	int number;
}member[51];

void swap(struct Member *x,struct Member *y){ 
	struct Member temp = *x; 
	*x = *y; 
	*y = temp; 
}

void check(int index1, int index2){
	if( member[index1].number < member[index2].number ){
		swap(&member[index1],&member[index2]); 
		return;
	}
	
	if( member[index1].number == member[index2].number &&  strcmp(member[index1].name,member[index2].name) > 0 ){
		swap(&member[index1],&member[index2]);
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
		printf("%s - %d\n",member[i].name,member[i].number);
	}
}

int main(){
	
	int t,n;
	
	scanf("%d",&t); getchar();
	
	for(int i=1;i<=t;i++){
		scanf("%d",&n); getchar();
		
		for(int j=0;j<n;j++){
			scanf("%[^#]#%d",&member[j].name,&member[j].number); getchar();
		}
		
		printf("Case #%d:\n",i);
		sort(n);
		display(n);		
	}
	
    return 0;
}
    
