#include <stdio.h>

struct Family{
	char father_name[31];
	char mother_name[31];
	int number_siblings;	
};

struct Student{
	char code[31];
	char name[31];
	char gender[15];
	struct Family fam;
};

struct Lecturer{
	char code[31];
	char name[31];
	char gender[15];
	int student_number;
	struct Student student[100];
}lecturer[100];

void input(){
	int T,K=0;
	
	scanf("%d",&T);
	getchar();
	
	for(int i=0;i<T;i++){
		scanf("%[^\n]",lecturer[i].code);
		getchar();
		scanf("%[^\n]",lecturer[i].name);
		getchar();
		scanf("%[^\n]",lecturer[i].gender);
		getchar();
		scanf("%d",&lecturer[i].student_number);	
		getchar();
		
		for(int j=0;j<lecturer[i].student_number;j++){
			scanf("%[^\n]",lecturer[i].student[j].code);
			getchar();
			scanf("%[^\n]",lecturer[i].student[j].name);
			getchar();
			scanf("%[^\n]",lecturer[i].student[j].gender);
			getchar();
			scanf("%[^\n]",lecturer[i].student[j].fam.father_name);	
			getchar();
			scanf("%[^\n]",lecturer[i].student[j].fam.mother_name);	
			getchar();
			scanf("%d",&lecturer[i].student[j].fam.number_siblings);	
			getchar();
		}
		
	}
	
	scanf("%d",&K);	
	getchar();
	
	K -= 1;
	
	printf("Kode Dosen: %s\n",lecturer[K].code);
	printf("Nama Dosen: %s\n",lecturer[K].name);
	printf("Gender Dosen: %s\n",lecturer[K].gender);
	printf("Jumlah Mahasiswa: %d\n",lecturer[K].student_number);
	
	for(int i=0;i<lecturer[K].student_number;i++){
		printf("Kode Mahasiswa: %s\n",lecturer[K].student[i].code);
		printf("Nama Mahasiswa: %s\n",lecturer[K].student[i].name);
		printf("Gender Mahasiswa: %s\n",lecturer[K].student[i].gender);
		printf("Nama Ayah: %s\n",lecturer[K].student[i].fam.father_name);
		printf("Nama Ibu: %s\n",lecturer[K].student[i].fam.mother_name);
		printf("Jumlah Saudara Kandung: %d\n",lecturer[K].student[i].fam.number_siblings);				
	}
	
	
}

int main(){
	input();
	
	return 0;
}
