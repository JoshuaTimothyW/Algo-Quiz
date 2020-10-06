#include <stdio.h>

int main(){
double T=3, A, B, C;
	scanf("%lf", &T);getchar();
for(int i=0;i<T;i++){
	scanf("%lf %lf", &A, &B);getchar();
	C = A*B/360;
	
	printf("%.2lf\n",C);
}
    return 0;
}
    
