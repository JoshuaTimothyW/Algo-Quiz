#include <stdio.h>

int main(void) {

	char string[] = {'a','s','d','f','g','h','j','k','l'};
	int index=0;
	
	while(string[index] != '\0'){
		printf("%c",string[index]);
		index++;
	}
	
//	printf("the size\n %d", sizeof( long));
	
	return 0;
}
