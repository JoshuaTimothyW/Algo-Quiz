#include<stdio.h>
#include<stdlib.h>

int hitungChar(int n)
{
	int temp = n, n2 = 1, x;
	for(x = 1; x < temp; x++)
	{
		n = (2 * n2) + 1;
		n2 = n;
	}
	return n;
}

int main()
{
   int T, x, z, j, k, *N;
   scanf("%d", &T);   
   N = (int*)malloc(T * sizeof(int));   
   for(x = 0; x < T; x++)
   {
       scanf("%d", &N[x]);
   }
   for(z = 0; z < T; z++)   
   {  
       int a = N[z];
       char* temp1, * temp2;
       int aa = hitungChar(a);
       temp1 = (char*)malloc(aa * sizeof(char));    
       temp2 = (char*)malloc(aa * sizeof(char));
       for(x = 0; x < aa; x++)   
       {
           temp1[x] = NULL;
           temp2[x] = NULL;
       }
       temp1[0] = 'A';
       char karakter = 'A';   
       for(x = 1; x < a; x++)
       {
           int size = *(&temp1 + 1) - temp1;
           karakter++;
           for(j = 0; temp1[j] != '\0'; j++)   
           {
               temp2[j] = temp1[j];  
           }
           temp1[j] = karakter;   
           for(k = 0; temp2[k] != '\0'; k++)       
           {  
               j++;
               temp1[j] = temp2[k];
           }
       }
       printf("Case #%d: %s\n",z + 1, temp1);  
   }
   return 0;
}



