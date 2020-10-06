#include <stdio.h>

int main(){
int no[10],total;

scanf("%d %d %d %d", &no[0], &no[4], &no[8], &no[2]);
total =  no[0]+no[4]+no[8];

no[1] = total-no[0]-no[2];
no[5] = total-no[2]-no[8];
no[7] = total-no[1]-no[4];
no[3] = total-no[4]-no[5];
no[6] = total-no[7]-no[8];

printf("%d %d %d\n",no[0], no[1], no[2]);
printf("%d %d %d\n",no[3], no[4], no[5]);
printf("%d %d %d\n",no[6], no[7], no[8]);


    return 0;
}
    
