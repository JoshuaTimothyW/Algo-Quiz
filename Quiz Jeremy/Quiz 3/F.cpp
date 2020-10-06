#include <stdio.h>
#include <math.h>

int main(){
double P, L, T, r, d1, d2, total;
scanf("%lf %lf %lf", &P, &L, &T);


d1 = sqrt((P*P)+(L*L));
d2 = sqrt((d1*d1)+(T*T));

total = 3.14159265359*d2*d2;

printf("%.2lf\n", total);
    return 0;
}
    
