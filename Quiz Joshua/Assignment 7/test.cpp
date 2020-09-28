#include <stdio.h>
#define get getchar();

long long arr[100000];
int N,K;
long long X,Y;
char query;



void read(){
	
	FILE *rd = fopen("testdata.in", "r");
	
	if(!rd){
		printf("File Not Found!");
	}else{
		fscanf(rd,"%d %d\n",&N,&K);
		
		for(int i=0;i<N;i++){
			fscanf(rd,"%lld ",&arr[i]);
		}
		
		for(int i=0;i<N;i++){
			fscanf(rd,"%c",&query); get
			fscanf(rd,"%lld",&X); get
			if(query == 'A'){
				fscanf(rd,"%lld",&Y); get
			}
		}
	}
	
	fclose(rd);
	
//	printf("%d",(A+B));
}

void swap(long long *x,long long *y){ 
	long long temp = *x; 
	*x = *y; 
	*y = temp; 
} 

int partition (long long arr[], int low, int high) 
{ 
    long long pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(long long arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int main(){
	
//	read();
//	long long arr[] = {2000000,1000000,4000000,5000000,3000000};
//	quickSort(arr,0,5);
//	
//	for(int i=0;i<5;i++){
//		printf("%lld ",arr[i]);
//	}
	
	long long x = 90000000000;


//	scanf("%lld",&x);
	printf("%lld",x);

	return 0;
}
