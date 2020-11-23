#include <stdio.h>
#define ll long long int


void swap(char *a, char *b){
	char temp = *b;
	*b = *a;
	*a = temp;
}

void list_digit(char arr[],int curr,int max){
	if(curr == max){
		printf("%s\n",arr);
		count++;
	}
	
	
	for(int i=curr;i<=max;i++){
		swap(&arr[curr],&arr[i]);
		list_digit(arr,curr+1,max);
		swap(&arr[curr],&arr[i]);
	}
}

int main(){
	
	int T,N;
	
	scanf("%d",&T);
	
	for(int i=1;i<=T;i++){
		scanf("%d",&N);
		
		char digits[10];
		char temp = '1';
	
		for(int j=0;j<N;j++){
			digits[j] = temp;
			temp++;
		}
		
		printf("Case #%d:\n",i);
		list_digit(digits,0,N-1);
	}

    return 0;
}
    
