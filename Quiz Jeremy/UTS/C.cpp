#include <stdio.h>

int main(){
	
	int hour,minute,second,t;
	int distance,velocity,weight,time,turn,fishing_index,decrement;
	int fishing_line[] = {450,900,1320,3200,4500};
	
	scanf("%d",&t);
	for(int num=1;num<=t;num++){
		scanf("%d %d %d %d %d %d",&fishing_index,&weight,&distance,&velocity,&decrement,&time);
	
		if(weight > fishing_line[fishing_index-1]){
			printf("Case #%d: Line broke up\n",num);
			continue;
		}
		
		second=0;
		turn=0;
		
		while(distance > 0){
			for(int i=0;i<time;i++){
				second++;
				
				if(turn == 0){
					distance += velocity;		
				}else{
					distance -= 5;
					velocity -= decrement;
				}
				
				if(velocity < 0){
					velocity = 0;
				}
				
				if(distance < 1){
					break;
				}
			}
			
			turn = !turn;
		}
		
		hour = second/3600;
		second %= 3600;
		
		minute = second/60;
		second %= 60;
		
		printf("Case #%d: %02d:%02d:%02d\n",num,hour,minute,second);	
	}
	
    return 0;
}
    
