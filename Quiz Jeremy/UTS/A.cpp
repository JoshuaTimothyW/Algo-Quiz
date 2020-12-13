#include <stdio.h>

int main(){
	
	double x,tourism_tax,clean_tax,total;

	for(int i=0;i<12;i++){
		scanf("%lf,",&x);
		total += x;
	}
	
	tourism_tax = (int)(total*0.07);
	clean_tax = (int)(total*0.05);
	total = total-tourism_tax-clean_tax;
	
	printf("%.2lf %.2lf %.2lf\n",tourism_tax,clean_tax,total);

    return 0;
}
    
