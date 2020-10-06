#include <stdio.h>

int main(){
double P, L, T, LS, LP, total;
scanf("%lf %lf %lf", &P, &L, &T);
LS = L*T/2;
LP = P*L;
total = (2*LS)+(3*LP);

printf("%.3lf\n", total);
    return 0;
}
    
