#include <stdio.h>

struct Student{
	char id[21];
	char name[101];
	int age;
}list_student[1001];

int main(){

	int n,q,index;
	
	scanf("%d",&n); getchar();
	
	for(int i=0;i<n;i++){
		scanf("%[^\n]",list_student[i].id); getchar();
		scanf("%[^\n]",list_student[i].name); getchar();
		scanf("%d",&list_student[i].age); getchar();
	}
	
	scanf("%d",&q); getchar();
	for(int i=0;i<q;i++){
		scanf("%d",&index);
		index--;
		printf("Query #%d:\n",i+1);
		printf("ID: %s\n",list_student[index].id);
		printf("Name: %s\n",list_student[index].name);
		printf("Age: %d\n",list_student[index].age);
	}

    return 0;
}
    
