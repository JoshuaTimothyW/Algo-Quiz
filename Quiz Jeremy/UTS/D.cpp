#include <stdio.h>

int main(){
	
	int time_red,time_black,total,red,black,second;
	int prev_red,prev_black,t;
	
	scanf("%d",&t);
	
	for(int num=1;num<=t;num++){
		scanf("%d %d %d",&total,&red,&black);
		
		time_black = 3;
		time_red = 4;
		second=0;
		
		while(red+black <= total){
			second++;
			
			prev_black = black;
			prev_red = red;
	
			if(second == time_black){
				black -= (int)(4*black/5);
				time_black += 3;
			}else{
				black *= 3;
			}
			
			if(second == time_red){
				red -= (int)(red/3);
				time_red += 4;
			}else{
				red *= 2;
			}
			
		}
		
		printf("%d",second-1);
		
		if(prev_red > prev_black){
			printf(" Red ");
		}else if(prev_red < prev_black){
			printf(" Black ");
		}else{
			printf(" None ");
		}
		
		if(prev_red-prev_black < 0){
			printf("%d",-1*(prev_red-prev_black));
		}else{
			printf("%d",prev_red-prev_black);
		}
		printf("\n");	
	}

    return 0;
}
    
