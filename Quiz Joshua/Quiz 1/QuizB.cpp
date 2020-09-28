#include <stdio.h>
#include <string.h>

int cnt[1000010];
int main() {
 int l, t, n;
 int tc;
 
 scanf("%d",&tc);

 for(t = 1 ; t <= tc ; t++){
 for(int i = 1 ; i<= 1000000 ; i++)
 {
  cnt[i] = 0;
 }

 int n , x;
 scanf("%d",&n);

 for(int i = 0 ; i < n ; i++)
 {
  scanf("%d",&x);
  cnt[x]++;
 }

 printf("Case #%d:\n",t);
 for(int i = 1 ; i<= 1000000 ; i++)
 {
  if(cnt[i] > 0)
  {
 
  printf("%d %d\n",i,cnt[i]);
  }
 }
}
return 0;
}
