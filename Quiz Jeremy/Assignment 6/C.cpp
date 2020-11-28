#include <stdio.h>
#define ui long long unsigned int

ui arr[1502];

int main(){
	
	ui t,k,n;
	ui sum1, sum2,factor,diff;
	
	scanf("%llu",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%llu %llu",&k,&n);
		factor=n;
		sum1=sum2=diff=0;
		for(int j=1;j<=k;j++){
			scanf("%llu",&arr[j]);
			if(j == factor){
				sum1+=arr[j];
				factor+=n;
			}else{
				sum2+=arr[j];
			}
		}
		
		diff = sum2-sum1;
		
		if(diff < 0){
			diff *= -1;
		}
		
		printf("Case #%d: %llu\n",i,diff);
	}
	
	
    return 0;
}
    
