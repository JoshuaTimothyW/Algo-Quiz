#include <stdio.h>
#include <string.h>
#define get getchar();

struct Employee{
	char name[21];
	char gender[21];
	char division[21];
	int active;
}emp[100];

int count=0;

int is_empty(){
	for(int i=0;i<count;i++){
		if(emp[i].active == -1){
			return i;
		}
	}
	
	return -1;
}

void display(){
	
	for(int i=0;i<count;i++){
		if(emp[i].active == 1){
			printf("%s\n",emp[i].name);
		}	
	}
}

void display_arr(){
	printf("==============\n\n\n");
	for(int i=0;i<count;i++){
		printf("No : %d\n",(i+1));
		printf("Nama : %s\n",emp[i].name);
		printf("Gender : %s\n",emp[i].gender);
		printf("Division : %s\n",emp[i].division);
		printf("Active : %d\n",emp[i].active);
		printf("==============\n\n\n");
			
	}
}

int same_name(char name[]){
	for(int i=0;i<count;i++){
		if(strcmp(name,emp[i].name) == 0){
			return 1;
		}
	}
	
	return 0;
}


void swap(char *x, char *y){
	char temp[21];
	
	strcpy(temp,x);
	strcpy(x,y);
	strcpy(y,temp);
}

void swap_active(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void add(){
	
	char name[21], gender[21], division[21];
	int index=0;
	
	scanf("%[^\n]",name); get
	scanf("%[^\n]",gender); get
	scanf("%[^\n]",division); get
	
	if(same_name(name) == 0){
		
		index = is_empty();
		
		int arr_retired[100];
		
		if(index == -1){
			for(int i=0;i<count;i++){
				if(emp[i].active == 0){
					arr_retired[i] = i;
				}
			}
			
			count++;
			index = count-1;
			
			
						
		}
		
		for(int i=count-1;i>=0;i--){
			if(emp[i].active == 1 || emp[i].active == -1){
				swap(emp[index].name,emp[i].name);
				swap(emp[index].gender,emp[i].gender);
				swap(emp[index].division,emp[i].division);
				swap_active(&emp[index].active,&emp[i].active);
				
				index = i;				
			}
		}
		
	
		
		strcpy(emp[0].name,name);
		strcpy(emp[0].gender,gender);
		strcpy(emp[0].division,division);
		emp[0].active = 1; 
	}

}


void change(){
	
	int index1, index2;
	
	scanf("%d %d",&index1,&index2); get
	
	if(emp[index1].active > 0 &&  emp[index2].active > 0){
		swap(emp[index1].name,emp[index2].name);
		swap(emp[index1].gender,emp[index2].gender);
		swap(emp[index1].division,emp[index2].division);
		swap_active(&emp[index1].active,&emp[index2].active);	
	}
	
}

void resign(){
	
	int index;
	
	scanf("%d",&index); get
	
	emp[index].active = -1;
}

void retire(){
	int index;
	
	scanf("%d",&index); get
	
	emp[index].active = 0;
}

int main(){
	
	int T,x;
	
	scanf("%d",&T); get
	
	for(int i=0;i<T;i++){
		scanf("%d",&x);	get
	
		switch(x){
			case 1:
				add();
				break;
			case 2:
				change();
				break;
			case 3:
				resign();
				break;
			case 4:
				retire();
				break;
		}
	}
	
	display_arr();
	
	return 0;
}
