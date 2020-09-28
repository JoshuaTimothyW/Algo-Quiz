#include <stdio.h>
#include <string.h>
  
void swap (char* a, char* b) 
{ 
    char t = *a; 
    *a = *b; 
    *b = t; 
}

int findCeil (char str[], char first, int k, int h) { 
    int ceilIndex = k; 
    for (int i = k+1; i <= h; i++) 
      if (str[i] > first && str[i] < str[ceilIndex]) 
            ceilIndex = i; 
  
    return ceilIndex;
}
void reverse(char str[], int k, int h) 
{ 

   while (k < h) 
   { 
       swap(&str[k], &str[h]); 
       k++; 
       h--; 
   } 
}

void permute ( char str[] ) 
{ 
    int size = strlen(str); 
  
    bool Finished = false; 
    while ( !Finished ) 
    { 
        printf ("%s\n", str); 
  
      
        int i; 
        for ( i = size - 2; i >= 0; --i ) 
           if (str[i] < str[i+1]) 
              break; 
        if ( i == -1 ) 
            Finished = true; 
        else
        {          
            int ceilIndex = findCeil( str, str[i], i + 1, size - 1 ); 
            swap( &str[i], &str[ceilIndex] ); 
            reverse( str, i + 1, size - 1 ); 
        } 
    } 
} 


int main()
{
   int t;
   int j=1;
   scanf("%d",&t);
   
   while(t--)
   {   
       char a[]="1";
       char b[]="12";
       char c[]="123";
       char d[]="1234";
       char e[]="12345";
       char f[]="123456";
       char g[]="1234567";
       int nm;
       
       scanf("%d",&nm);
       printf("Case #%d:\n",j++);
   
       if(nm==1){
           int n = strlen(a);
           permute(a);
       }
       if(nm==2){
           int n = strlen(b);
           permute(b);
       }
       if(nm==3){
           int n = strlen(c);
           permute(c);
       }
       if(nm==4){
           int n = strlen(d);
          permute(d);
       }
       if(nm==5){
           int n = strlen(e);
          permute(e);
       }
       if(nm==6){
           int n = strlen(f);
          permute(f);
       }
       if(nm==7){
           int n = strlen(g);
          permute(g);
       }
   }
   return 0;
}
