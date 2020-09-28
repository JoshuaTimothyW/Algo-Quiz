#include <stdio.h>

int main(){
	
	int d,s,t,max,mid,min;
	
	scanf("%d %d %d",&d,&s,&t);
	
	max = (d > s) ? d : s;
	max = (max > t) ? max : t;
		
	min = (d < s) ? d : s;
	min = (min < t) ? min : t;
	
	mid = (d+s+t)-max-min;
	
	if(max == d){
		printf("Daging");
	}else if(max == s){
		printf("Sayur");
	}else if(max == t){
		printf("Telur");
	}
	printf("\n");
	
	if(mid == d){
		printf("Daging");
	}else if(mid == s){
		printf("Sayur");
	}else if(mid == t){
		printf("Telur");
	}
	printf("\n");
	
	if(min == d){
		printf("Daging");
	}else if(min == s){
		printf("Sayur");
	}else if(min == t){
		printf("Telur");
	}
	
	printf("\n");
	return 0;
}
