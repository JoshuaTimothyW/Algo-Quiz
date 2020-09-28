#include <stdio.h>
#include <string.h>

int main() 
{
	int T, N, c;
 	char str[100010];
 	scanf("%d",&c);
 
 for(T = 1 ; T <= c ; T++){

	int upper = 0;
	scanf("%s %d",str,&N);
 
	for(int i = 0 ; i < N ; i++){
	  	if(i == 0 ){
	 
			if(str[i] >= 'A' && str[i] <='Z'){
				upper++;
			}
	  	
		  continue;
		}
	
	 	if(upper %2 == 1){
	 		printf("%d\n",upper);
	 		
		  	if(str[i] >= 'A' && str[i] <='Z'){
			   str[i] -= 'A';
			   str[i] += 'a';
			}else{
			   str[i] -='a';
			   str[i] +='A';
			}
		}
	 
		if(str[i] >= 'A' && str[i] <='Z'){
		  upper++;
		}
		
		printf("String loop-%d : %s\n",i,str);
	}

	printf("Case #%d: ",T);
	printf("%s\n", str);
 }
 return 0;
}

