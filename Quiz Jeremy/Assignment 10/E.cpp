#include <stdio.h>
#define ll long long int

struct Command{
	int hack;
	int start;
	int end;
}command[151];

struct Salary{
	ll sal1;
	ll sal2;
	ll sal3;
};

struct Employee{
	char name[30];
	struct Salary sal;
}list_employee[151];

void swap(int index1,int index2){ 
	struct Salary temp = list_employee[index1].sal; 
	list_employee[index1].sal = list_employee[index2].sal; 
	list_employee[index2].sal = temp; 
}

void shift(int index){
	ll temp = list_employee[index].sal.sal3;
	list_employee[index].sal.sal3 = list_employee[index].sal.sal2;
	list_employee[index].sal.sal2 = list_employee[index].sal.sal1;
	list_employee[index].sal.sal1 = temp;
}

void hack1(int start, int end){
	while(start < end){
		swap(start,end);
		start++;
		end--;
	}
}

void hack2(int start, int end){
	while(start <= end){
		shift(start);
		start++;
	}
}

void display(ll n){
	for(int i=0;i<n;i++){
		printf("%s %lld %lld %lld\n",list_employee[i].name,list_employee[i].sal.sal1,list_employee[i].sal.sal2,list_employee[i].sal.sal3);
	}
}

int main(){
	
	int t,n,q,hack,start,end;
	
	scanf("%d",&t); 
	
	for(int i=1;i<=t;i++){
		scanf("%d %d",&n,&q); 
		
		for(int j=0;j<n;j++){
			scanf("%s %lld %lld %lld"
			,&list_employee[j].name
			,&list_employee[j].sal.sal1
			,&list_employee[j].sal.sal2
			,&list_employee[j].sal.sal3
			); getchar();
		}
		
		for(int j=0;j<q;j++){
			scanf("%d %d %d",&command[j].hack,&command[j].start,&command[j].end); 
		}
		
		for(int j=q-1;j>=0;j--){
			if(command[j].hack == 1){
				hack1(command[j].start-1,command[j].end-1);
			}else{
				hack2(command[j].start-1,command[j].end-1);
			}
		}
		
		printf("Case #%d:\n",i);
		for(int i=0;i<n;i++){
			printf("%s %lld\n",list_employee[i].name,list_employee[i].sal.sal3);
		}
	}
	
    return 0;
}
    
