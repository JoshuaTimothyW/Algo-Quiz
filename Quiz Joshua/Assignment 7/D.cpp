#include <stdio.h>
#include <string.h>

#define get getchar();

char str[1000];

void empty(){
	for(int i=0;i<strlen(str);i++){
		str[i] = NULL;
	}
}

void transform(){
	
	printf("%d",str[0]);
	
	for(int i=1;i<strlen(str);i++){
		printf("-%d",str[i]);
	}
	printf("\n");
}

int main(){
	
	int T;
	
	scanf("%d",&T); get
	
	for(int i=0;i<T;i++){
		scanf("%[^\n]",str); get
		printf("Case %d: ",(i+1));
		transform();
		empty();
	}
	
	return 0;
}
