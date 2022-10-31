#include <bits/stdc++.h>
using namespace std;
int main()
{//我在这里稍微解释一下为什么是3n加一
    //首先假设某一状态 我们最大已经可以称到了n 那么我们可以通过合适的选择在后面选择一个恰当的数 而由于有前面的东西作为铺垫 所以这个数周围的+-n的范围都是可以称出来的 所以这时能称得出来最大的距离就是之前的长度n加上两边的长度2*n再加上后续选择的那个数
  int n;
  scanf("%d",&n);
  int i = 1,c=1;
  while(1)
  {
    if(c >= n)
    break;
    i++;
    c = c*3+1;
  }
  printf("%d",i);
  return 0;
}
