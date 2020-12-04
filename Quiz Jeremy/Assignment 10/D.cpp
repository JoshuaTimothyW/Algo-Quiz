#include <stdio.h>

struct Group{
	char name[11];
	int group;
}list_group[201];

void swap(struct Group *x,struct Group *y){ 
	struct Group temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort(int n){ 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if(list_group[j].group > list_group[j+1].group){
				swap(&list_group[j],&list_group[j+1]); 
			} 	
		} 
	} 
}

int main(){
	
	int t,n,curr,index;
	int arr[21];
	
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		for(int j=0;j<21;j++){
			arr[j] = 0;
		}
		
		scanf("%d",&n);
		
		for(int j=0;j<n;j++){
			scanf("%s %d",&list_group[j].name,&list_group[j].group); getchar();
			arr[list_group[j].group] += 1;
		}
		
		sort(n);
		
		printf("Case #%d:\n",i);
		
		index=0;
		
		while(index < n){
			curr=list_group[index].group;
			
			printf("Group %d(%d):\n",curr,arr[curr]);
			
			while( list_group[index].group == curr && index < n ){
				printf("%s\n",list_group[index].name);
				index++;
			}
		}
		
	}
	
    return 0;
}
    
