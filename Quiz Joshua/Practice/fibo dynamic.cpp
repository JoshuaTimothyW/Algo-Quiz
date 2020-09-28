#include<stdio.h> 
#define NIL -1 
#define MAX 100000
#define big long long unsigned
  
big f[MAX],total=0; 

big fib(int n) 
{ 
    // Base cases 
    if (n == 0) 
        return 0; 
    if (n == 1 || n == 2) 
        return (f[n] = 1); 
  
    // If fib(n) is already computed 
    if (f[n]) 
        return f[n]; 
  
    int k = (n & 1)? (n+1)/2 : n/2; 
  
    // Applying above formula [Note value n&1 is 1 
    // if n is odd, else 0]. 
    f[n] = (n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1)) 
           : (2*fib(k-1) + fib(k))*fib(k); 
  
    return f[n]; 
} 
  
// Computes value of first Fibonacci numbers 
big calculateSum(big n) 
{ 
    return fib(n+2) - 1; 
} 
  
void display(){
	for(int i=0;i<8;i++){
		printf(" %llu",f[i]);
	}
}  
  
int main () 
{ 

  big n = 0;   
//  
  scanf("%llu",&n);
  printf("%llu",calculateSum(n));
//  _initialize();
//  printf("Fibonacci number is %llu", fib(n));
  
//  printf("\nTotal: %llu",total);
//  display(); 
  return 0; 
} 
