#include <stdio.h>
#define flush fflush(stdin);

int main(){
	
	int arr[2000], N;
	int curr=0;
	
	scanf("%d",&N); flush
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<N;i++){
		curr += arr[i];
		
		if(curr > 39){
			curr = curr%40;
		}
		
		if(curr == 12){
			curr = 28;
		}else if(curr == 30){
			curr = 10;
		}else if(curr == 35){
			curr = 7;
		}
	}
	
	printf("%d",curr);
	
	printf("\n");
	return 0;
}
