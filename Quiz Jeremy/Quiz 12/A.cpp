#include <stdio.h>
#include <string.h>

struct Schedule{
	char course[11];
	int day;
}schedule[101];

void swap(struct Schedule *x,struct Schedule *y){ 
	struct Schedule temp = *x; 
	*x = *y; 
	*y = temp; 
}

void check(int index1, int index2){
	if( schedule[index1].day > schedule[index2].day ){
		swap(&schedule[index1],&schedule[index2]); 
		return;
	}
	
	if( schedule[index1].day == schedule[index2].day &&  strcmp(schedule[index1].course,schedule[index2].course) > 0 ){
		swap(&schedule[index1],&schedule[index2]);
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
	
	int n;
	scanf("%d",&n); getchar();
	
	for(int i=0;i<n;i++){
		scanf("%s %d",&schedule[i].course,&schedule[i].day); getchar();
	}	
	sort(n);
	for(int i=0;i<n;i++){
		printf("%s\n",schedule[i].course);
	}
	
    return 0;
}
    
