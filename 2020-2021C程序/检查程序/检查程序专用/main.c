#include <stdio.h>
int main (){
    int i,j,n = 1000,sum = 0;
for(i=0; i<n; i++)
  for(j=i; j>0; j/=2)
     sum++;
     printf("%d",sum);
return 0;
}
