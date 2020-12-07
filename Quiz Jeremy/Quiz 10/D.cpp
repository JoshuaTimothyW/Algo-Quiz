#include <stdio.h>

struct Student{
	char id[11];
	char name[16];
	double score;
}list_student[50001];

int main(){
	
	int n,index;
	double mean,total;
	
	scanf("%d",&n); getchar();
	total=0;
	
	for(int i=0;i<n;i++){
		scanf("%[^\n]",&list_student[i].id); getchar();
		scanf("%[^\n]",&list_student[i].name); getchar();
		scanf("%lf",&list_student[i].score); getchar();
		total += list_student[i].score;
	}
	
	mean = total/n;
	
	for(int i=index;i<n;i++){
		if(list_student[i].score >= mean){
			printf("%s %s\n",list_student[i].id,list_student[i].name);
		}
	}
	
    return 0;
}
    
