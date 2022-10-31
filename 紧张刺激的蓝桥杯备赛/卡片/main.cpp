#include <stdio.h>
int main(void)
{
  int i,t,sum=0;
  for(i=1;;i++)
  {
    for(t=i;t!=0;t/=10)
      if(t%10==1)
        sum++;
    if(sum>=2021)
      goto end;
  }
  end:printf("%d",i);
  return 0;
}
