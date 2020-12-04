#include <stdio.h>

struct Employee{
	char name[21];
	char gender[21];
	char division[21];
}list_employee[101];

int count=0;


void add(){
	
	struct Employee temp;
	
	scanf("%[^\n]",temp.name); getchar();
	scanf("%[^\n]",temp.gender); getchar();
	scanf("%[^\n]",temp.division); getchar();
	count++;
	
	if(count > 1){
		for(int i=count;i>0;i--){
			list_employee[i] = list_employee[i-1];
		}
	}
	
	list_employee[0] = temp;
}

void change(int index1, int index2){
	if(){
		
	}
}

void display(){
	for(int i=0;i<count;i++){
		printf("%s\n",list_employee[i].name);
	}
}

int main(){
	
	int n,query,index1,index2;
	
	count=0;
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&query); getchar();
		
		if(query == 1){
			add();
		}else if(query == 2){
			scanf("%d %d",&index1,&index2);
			printf("update\n");
		}else if(query == 3){
			scanf("%d",&index1);
			printf("resign\n");
		}else if(query == 4){
			scanf("%d",&index1);
			printf("retire\n");
		}
	}
	
	display();

    return 0;
}
    
