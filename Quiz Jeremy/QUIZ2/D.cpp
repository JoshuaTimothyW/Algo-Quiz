#include <stdio.h>

struct Message{
	char msg;
	int index;
}msg[101];

void swap(struct Message *x,struct Message *y){ 
	struct Message temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort(int n){ 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if( msg[j].index > msg[j+1].index ){
				swap(&msg[j],&msg[j+1]); 
			} 	
		} 
	} 
}

int main(){
	
	int n,index;
	
	scanf("%d",&n); getchar();
	
	index=0;
	
	do{
		scanf("%c",&msg[index].msg);
		index++;
	}while(index < n);
	
	
	for(int i=0;i<n;i++){
		scanf("%d",&msg[i].index);
	}
	
	sort(n);
	
	for(int i=0;i<n;i++){
		printf("%c",msg[i].msg,msg[i].index);
	}
	printf("\n");
	
    return 0;
}
    
