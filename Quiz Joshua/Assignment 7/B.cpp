#include <stdio.h>
#define get getchar();

long long arr[100001];
long long N,K,count=0;
long long X,Y;
char query;

long long binary_search(long long n,long long target){
	
	long long l=0,r=n,mid=0;
	
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


void swap(long long *x,long long *y){ 
	long long temp = *x; 
	*x = *y; 
	*y = temp; 
} 

void quick_sort(long long arr[],long long l,long long r) 
{ 
	long long j,k; 
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

void query_data(long long data){
	quick_sort(arr,0,count-1);
	
	long long num=0;
	
	for(long long i=0;arr[i]<=data;i++){
		num++;
	}
	
	printf("%lld\n",num);
}

void insert(long long data){
	long long index = binary_search(count-1,data);
	
	if(index == -1){
		arr[count] = data;
		count++;	
	}
}

void alter(long long data1, long long data2){
	long long index1 = binary_search(count-1,data1);
	long long index2 = binary_search(count-1,data2);
	
	if(index1 != -1 && index2 == -1){
		arr[index1] = data2;	
	}
}

void del(long long data){
	long long index = binary_search(count-1,data);
	
	if(index != -1){
		for(long long i=index;i<count;i++){
			arr[i] = arr[i+1];
		}
		
		count--;
	}
}

void display(){
	printf("Array: ");
	for(int i=0;i<count;i++){
		printf("%lld ",arr[i]);
	}
	printf("\n");
}

void input(){
	
	scanf("%lld %lld",&N,&K); get
	
	for(long long i=0;i<N;i++){
		scanf("%lld",&arr[i]); get
		count++;
	}
	
	
	for(long long i=0;i<K;i++){
		scanf("%c %lld",&query,&X); get
		
		if(query == 'A'){
			scanf("%lld",&Y); get
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
