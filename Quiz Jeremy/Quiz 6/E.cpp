#include <stdio.h>

int main(){
	long long int T, A, B, index;
	long long int num1[10],num2[10],num3[10];
	
	scanf("%lld", &T);
	
	for(int j=0;j<T;j++){
		scanf("%lld %lld", &A, &B);
		index=0;

		for(int i=0;i<10;i++){
			num1[i] = num2[i] = 0;			
		}		
		
		for(int i=9;A>0;i--){
			num1[i] = A%10;
			A/=10;
		}
		
		for(int i=9;B>0;i--){
			num2[i] = B%10;
			B/=10;
		}
		
		for(int i=0;i<10;i++){
			num3[i] = num1[i] + num2[i];
			if(num3[i] > 9){
				num3[i]-=10;
			}
			
		}
		
		if(num3[0] == 0){
			while( num3[index] < 1 && index < 9 ){
				index++;
			}
		}
		
		printf("Case #%d: ",j+1);
		for(int i=index;i<=9;i++){
			printf("%lld",num3[i]);
		}
		printf("\n");
		
	}
	
    return 0;
}
    
