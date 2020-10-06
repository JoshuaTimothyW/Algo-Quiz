#include <stdio.h>

int main(){
	
	int A,B,C,D,sum1,sum2,sum3;

	scanf("(%d+%d)x(%d-%d)",&A,&B,&C,&D); getchar();
	sum1 = (A+B)*(C-D);
	
	scanf("(%d+%d)x(%d-%d)",&A,&B,&C,&D); getchar();
	sum2 = (A+B)*(C-D);
	
	scanf("(%d+%d)x(%d-%d)",&A,&B,&C,&D); getchar();
	sum3 = (A+B)*(C-D);
	
	printf("%d %d %d\n",sum1,sum2,sum3);

    return 0;
}
    
