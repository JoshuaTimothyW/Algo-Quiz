#include <stdio.h>

int main(){
	
	int T;
	long long arr[100], temp, sum;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%lld",&arr[i]);
	}
	
	for(int i=0;i<T;i++){
		temp = arr[i];
		
		printf("Case #%d: %lld",i+1,temp);
		
		while(temp >= 10){
			sum=0;
			
			while(temp != 0){
				sum += temp%10;
				temp = temp/10;
			}
			printf(" %lld",sum);
			
			temp = sum;
		}
		
		printf("\n");
	}
	return 0;
}
