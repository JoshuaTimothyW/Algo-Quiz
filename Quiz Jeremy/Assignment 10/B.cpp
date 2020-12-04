#include <stdio.h>
#include <string.h>

struct Name{
	char name[100];
}list_name[1000];

void swap(struct Name *x,struct Name *y){ 
	struct Name temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort(int n){
	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if( strcmp(list_name[j].name,list_name[j+1].name) > 0 ){
				swap(&list_name[j],&list_name[j+1]); 
			} 	
		} 
	} 
}

int count_duplicate(int n){
//	int count=0,dup;
//	int i,j;
//	
//	i = dup = 0;
	
	int count=0,index=1,curr=0,dup;
	
	while(index < n){
		dup=0;
		curr=index-1;
		
		while( strcmp(list_name[curr].name,list_name[index].name) == 0 && index < n ){
			printf("%s\n",list_name[index].name);
			index++;
			dup++;
		}
		
		if(dup > 0){
			count++;
		}else{
			index++;
		}
	}

//	while(i < n){
//		j=i+1;
//		
//		if( strcmp(list_name[j].name,list_name[i].name) == 0 ){
//			count++;
//			dup=1;
//			while(dup == 1){
//				if( strcmp(list_name[j].name,list_name[i].name) == 0 ){
//					j++;
//				}else{
//					dup=0;
//				}
//			}
//			i=j;
//		}else{
//			i++;
//		}
//	}
	
	return count;
}

void lower_all(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(list_name[i].name);j++){
			if(list_name[i].name[j] >= 65 && list_name[i].name[j] <= 90){
				list_name[i].name[j] += 32;
			}
		}
	}
}

int main(){
	
	int n;
	
	scanf("%d",&n); getchar();
	
	for(int i=0;i<n;i++){
		scanf("%[^\n]",list_name[i].name); getchar();
	}
	lower_all(n);
	sort(n);
	printf("You have %d duplicate name(s).\n",count_duplicate(n));
	
    return 0;
}
    
