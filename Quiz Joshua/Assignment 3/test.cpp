#include<stdio.h>
// 	while( (getchar()) != '\n' ); is the alternative for fflush(stdin);


int main(){
	
	int x,y;
	scanf("%d %d",&x,&y);
	printf("%d",(x%y));
	
	return 0;
}
