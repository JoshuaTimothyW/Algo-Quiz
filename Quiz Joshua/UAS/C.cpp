#include <stdio.h>
#define get getchar();

struct Event{
	int tahun;
	int bulan;
	int tanggal;
	char s[1001];
}event[101];

int T,count=0;

int same_year(int year1, int year2){
	if(year1 == year2) return 1; 
	else return 0;
}

int same_month(int month1, int month2){
	if(month1 == month2) return 1;
	else return 0;
}

int valid_swap(int index1, int index2){
	if(event[index1].tahun < event[index2].tahun){
		return 1;	
	}else if( same_year(event[index1].tahun,event[index2].tahun) && event[index1].bulan < event[index2].bulan ){
		return 1;
	}else if( same_year(event[index1].tahun,event[index2].tahun) && same_month(event[index1].bulan, event[index2].bulan) && event[index1].tanggal < event[index2].tanggal ){
		return 1;	
	}
	
	return 0;
}

void swap(struct Event *x,struct Event *y){ 
	struct Event temp = *x; 
	*x = *y; 
	*y = temp; 
} 

void bublesort(struct Event event[], int n){ 

	for(int i=0;i<n;i++){ 
		for(int j=n-1;j>i;j--){
			if( valid_swap(j,j-1) ){
				swap(&event[j],&event[j-1]);
			}
		}
	}
}

int main(){
	
	scanf("%d",&T); get
	
	for(int i=0;i<T;i++){
		scanf("%d",&event[count].tahun); get
		scanf("%d",&event[count].bulan); get
		scanf("%d",&event[count].tanggal); get
		scanf("%[^\n]",event[count].s);	get	
		count++;
	}
	
	bublesort(event,count);
	
	for(int i=0;i<count;i++){
		printf("%.2d-%.2d-%d %s\n",event[i].tanggal,event[i].bulan,event[i].tahun,event[i].s);
	}
	
	return 0;
}
