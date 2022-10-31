
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  int x,y;
  int data;
  scanf("%d",&n);
  x = y = 0;
  for(int i = 0; i < n;i++)
  {
    scanf("%d",&data);
    if(data>=85)
        y++;
    if(data>=60)
        x++;
  }
  int q = x*100.0/n+0.5;
  int p = y*100.0/n+0.5;
  printf("%d%%\n%d%%",q,p);
  return 0;
}
