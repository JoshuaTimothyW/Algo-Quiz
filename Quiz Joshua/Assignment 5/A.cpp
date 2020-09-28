#include <stdio.h>
#define get getchar();

struct Mahasiswa{
	char name[101];
	char nim[10];
	int age;
	char postal_code[7];
	char place_birth[101];
	char date_birth[101];
	char highschool[101];
	int number_sibling;
	int height;
	char bank_account[10];	
}mhs[100];

int count=0;

void input(){
	scanf("%[^\n]",mhs[count].name); get
	scanf("%[^\n]",mhs[count].nim); get
	scanf("%d",&mhs[count].age); get
	scanf("%[^\n]",mhs[count].postal_code); get
	scanf("%[^\n]",mhs[count].place_birth); get
	scanf("%[^\n]",mhs[count].date_birth); get
	scanf("%[^\n]",mhs[count].highschool); get
	scanf("%d",&mhs[count].number_sibling); get
	scanf("%d",&mhs[count].height); get
	scanf("%[^\n]",mhs[count].bank_account); get
	count++;
}

void output(){
	for(int i=0;i<count;i++){
		printf("Mahasiswa ke-%d:\n",(i+1));		
		printf("Nama: %s\n",mhs[i].name); 
		printf("NIM: %s\n",mhs[i].nim); 
		printf("Umur: %d\n",mhs[i].age); 
		printf("Kode Pos: %s\n",mhs[i].postal_code); 
		printf("Tempat Lahir: %s\n",mhs[i].place_birth); 
		printf("Tanggal Lahir: %s\n",mhs[i].date_birth); 
		printf("Almamater SMA: %s\n",mhs[i].highschool); 
		printf("Jumlah Saudara Kandung: %d\n",mhs[i].number_sibling); 
		printf("Tinggi Badan: %d\n",mhs[i].height); 
		printf("NOMOR REKENING: %s\n",mhs[i].bank_account); 
	}
}

int main(){
	
	int T;
	
	scanf("%d",&T); get
	
	for(int i=0;i<T;i++){
		input();
	}
	
	output();
	
	return 0;
}
