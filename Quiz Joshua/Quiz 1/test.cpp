#include <stdio.h>

int main(){
	
	char s[] = {"hEllOWOrld"};
	
	for(int k=0;s[k] != NULL;k++){
		if(s[k] >= 'a' && s[k] <= 'z'){
			s[k] -= 32;
		}else{
			s[k] += 32;
		}
		
		printf("%c",s[k]);
	}
	
	
	printf("\n");
	return 0;
}
