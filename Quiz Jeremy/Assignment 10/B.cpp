#include <stdio.h>
#include <string.h>

struct Name{
	char name[100];
	int visited;
}list_name[1000];

int count_duplicate(int n){
	int dup,count=0;
	
	for(int i=0;i<n;i++){
		dup=0;
		
		if( list_name[i].visited == 0 ){
			for(int j=i+1;j<n;j++){
				if( strcmp(list_name[i].name,list_name[j].name) == 0 ){
					dup++;
					list_name[j].visited = 1;		
				}
			}
			
			list_name[i].visited = 1;
		}
		
		if(dup > 0){
			count++;
		}
	}
	
	return count;
}

int main(){
	
	int n;
	
	scanf("%d",&n); getchar();
	
	for(int i=0;i<n;i++){
		scanf("%[^\n]",list_name[i].name); getchar();
		list_name[i].visited=0;
	}
	
	printf("You have %d duplicate name(s).\n",count_duplicate(n));
	
    return 0;
}
    
