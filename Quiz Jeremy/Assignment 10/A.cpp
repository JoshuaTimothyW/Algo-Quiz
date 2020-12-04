#include <stdio.h>

struct Student{
	int id;
	int date;
	int month;
	int year;
	char name[20];
	char address[20];
}list_student[100];

void swap(struct Student *x,struct Student *y){ 
	struct Student temp = *x; 
	*x = *y; 
	*y = temp; 
}

void sort(int n){ 

	for(int i=0;i<(n-1);i++){
		for(int j=0;j<(n-(i+1));j++){
			if(list_student[j].id > list_student[j+1].id){
				swap(&list_student[j],&list_student[j+1]); 
			} 	
		} 
	} 
}

int search(int id, int n){
	for(int i=0;i<n;i++){
		if(list_student[i].id == id){
			return i;
		}
	}
	
	return -1;
}

int main(){
	
	int n,q,id;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d %s %s"
		,&list_student[i].id
		,&list_student[i].date
		,&list_student[i].month
		,&list_student[i].year
		,&list_student[i].name
		,&list_student[i].address); getchar();
	}	
	
	sort(n);
	
	scanf("%d",&q);
	
	for(int i=0;i<q;i++){
		scanf("%d",&id);
		id = search(id,n);
		if( id > -1 ){
			printf("%d. %s was born on %d/%d/%d and live at %s"
			,list_student[id].id
			,list_student[id].name
			,list_student[id].date
			,list_student[id].month
			,list_student[id].year
			,list_student[id].address);
		}else{
			printf("No data found!");
		}
		printf("\n");
	}
	
    return 0;
}
    
