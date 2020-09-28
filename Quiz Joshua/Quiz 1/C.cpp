#include <stdio.h>

int main(){
	
	int T,N[1000];
	
	int hour,minute;
	
	scanf("%d",&T);
	
	for(int i=0;i<T;i++){
		scanf("%d",&N[i]);
	}
	
	for(int i=0;i<T;i++){
		hour = minute = 0;
		
		hour = N[i]/60;
		minute = N[i]%60;
		
		printf("Case #%d: %02d:%02d\n",i+1,hour,minute);
		
	}
	
	return 0;
}
