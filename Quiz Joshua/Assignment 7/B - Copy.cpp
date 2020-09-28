#include <stdio.h>
#define get getchar();

unsigned long long arr[100001];
int N,K,count=0;
unsigned long long X,Y;
char query;

int binary_search(int n,unsigned long long target){
	
	int l=0,r=n,mid=0;
	
	if(target == arr[0]){
		return 0;
	}else if(target == arr[count-1]){
		return count-1;
	}
	
	while(l < r){
		
		mid = (l+r)/2;
		
		if(arr[mid] == target) return mid;
		 
        if (target < arr[mid]) { 
            r = mid;
      	}else { 
            l = mid + 1;
        }     
	}
	
	return -1;
}


void swap(unsigned long long *x,unsigned long long *y){ 
	unsigned long long temp = *x; 
	*x = *y; 
	*y = temp; 
} 

void quick_sort(unsigned long long arr[],int l,int r) 
{ 
	int j,k; 
	if(l < r){
		j = l;
		k = r + 1;
		do{ 
			do{ j=j+1; } while(arr[j] < arr[l]); 
			do{ k=k-1; } while(arr[k] > arr[l]); 
			if(j < k) swap(&arr[j],&arr[k]); 
		}while(j <= k); 
		
		swap(&arr[l],&arr[k]); 
		quick_sort(arr,l,k-1); 
		quick_sort(arr,k+1,r); 
	}
}

void query_data(unsigned long long data){
	quick_sort(arr,0,count-1);
	printf("%d\n",binary_search(count-1,data)+1);
}

void insert(unsigned long long data){
	arr[count] = data;
	count++;
}

void alter(unsigned long long data1, unsigned long long data2){
	int index = binary_search(count-1,data1);
	arr[index] = data2;
}

void del(unsigned long long data){
	int index = binary_search(count-1,data);
	
	for(int i=index;i<count;i++){
		arr[i] = arr[i+1];
	}
	
	count--;
}

void display(){
	printf("Array: ");
	for(int i=0;i<count;i++){
		printf("%llu ",arr[i]);
	}
	printf("\n");
}

void input(){
	
	scanf("%d %d",&N,&K); get
	
	for(int i=0;i<N;i++){
		scanf("%llu",&arr[i]); get
		count++;
	}
	
	
	for(int i=0;i<K;i++){
		scanf("%c %llu",&query,&X); get
		
		if(query == 'A'){
			scanf("%llu",&Y); get
		}
		
		switch(query){
			case 'Q':
				query_data(X);
				break;
			case 'I':
				insert(X);
				break;
			case 'A':
				alter(X,Y);
				break;
			case 'D':
				del(X);
				break;
		}
	}
}

int main(){
	
	input();
	
	return 0;
}
