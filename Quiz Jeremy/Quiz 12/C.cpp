#include <stdio.h>
#include <string.h>

struct Data{
	char name[101];
}data[101];

void swap(struct Data *x,struct Data *y){ 
	struct Data temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort(int n){ 
	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if( strcmp(data[j].name,data[j+1].name) > 0 ){
				swap(&data[j],&data[j+1]); 
			}
		} 
	} 
}

int main(){
	
	int t,n,k;
	scanf("%d",&t); getchar();
	
	for(int i=1;i<=t;i++){
		scanf("%d %d",&n,&k); getchar();
	
		for(int j=0;j<n;j++){
			scanf("%s",&data[j].name); getchar();
		}	
		
		sort(n);
		
		printf("Case #%d: %s\n",i,data[k-1].name);
	}
	
    return 0;
}

