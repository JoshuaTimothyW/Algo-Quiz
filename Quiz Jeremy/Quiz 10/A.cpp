#include <stdio.h>

struct Student{
	char name[101];
	char nim[10];
	int age;
	char postal[7];
	char pob[101];
	char dob[101];
	char school[101];
	int sibling;
	int height;
	char bank[10];
};

int main(){
	
	int n;
	struct Student list_student;
	
	scanf("%d",&n); getchar();
	
	for(int i=0;i<n;i++){
		scanf("%[^\n]",&list_student.name); getchar();
		scanf("%[^\n]",&list_student.nim); getchar();
		scanf("%d",&list_student.age); getchar();
		scanf("%[^\n]",&list_student.postal); getchar();
		scanf("%[^\n]",&list_student.pob); getchar();
		scanf("%[^\n]",&list_student.dob); getchar();
		scanf("%[^\n]",&list_student.school); getchar();
		scanf("%d",&list_student.sibling); getchar();
		scanf("%d",&list_student.height); getchar();
		scanf("%[^\n]",&list_student.bank); getchar();
		
		printf("Mahasiswa ke-%d:\n",i+1);
		printf("Nama: %s\n",list_student.name); 
		printf("NIM: %s\n",list_student.nim); 
		printf("Umur: %d\n",list_student.age); 
		printf("Kode Pos: %s\n",list_student.postal); 
		printf("Tempat Lahir: %s\n",list_student.pob); 
		printf("Tanggal Lahir: %s\n",list_student.dob); 
		printf("Almamater SMA: %s\n",list_student.school); 
		printf("Jumlah Saudara Kandung: %d\n",list_student.sibling); 
		printf("Tinggi Badan: %d\n",list_student.height); 
		printf("NOMOR REKENING: %s\n",list_student.bank);
	}
	
	
    return 0;
}
    
