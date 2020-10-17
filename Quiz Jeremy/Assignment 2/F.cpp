#include <stdio.h>
int main(){
char A,B,C,D,E,F,G,H,I;

scanf("%c %c %c",&A,&B,&C); getchar();
scanf("%c %c %c",&D,&E,&F); getchar();
scanf("%c %c %c",&G,&H,&I); getchar();

printf("  %c\n", A);
printf(" %c %c\n", D, B);
printf("%c %c %c\n", G, E, C);
printf(" %c %c\n", H, F);
printf("  %c\n", I);

return 0;
}
