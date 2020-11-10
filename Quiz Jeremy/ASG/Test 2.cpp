#include <stdio.h>
#include <string.h>

int main(){
	
	char str[1000],index,max;
	
	scanf("%s %d",str,&index);
	
	max = strlen(str);
	printf("%s",str);
	
	for(int i=max-1-index;i>=0;i--){
		printf("%c",str[i]);
	}
	printf("\n");
	
    return 0;
}
    
