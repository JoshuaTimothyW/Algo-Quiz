#include <stdio.h>

int main(){
	long long int T, S, B[26],index,total;
	char A[100000];
	
	scanf("%lld", &T);
	
	for(int i=0;i<T;i++){

		scanf("%s",A); getchar();
		
		total = 0;

		for(int j=0;j<26;j++){
			B[j] = 0;
		}
		
		index=0;
		while(A[index] != NULL){
			B[A[index] - 97]++;
			index++;
		}
		
		for(int j=0;j<26;j++){
			if(B[j] > 0){
				total++;
			}
		}
		
		printf("Case #%lld: ",i+1);
		if(total % 2 == 0){
			printf("Yay\n");	
		}else{
			printf("Ewwww\n");
		}
	}
	
	
	
	
    	return 0;
}
    
