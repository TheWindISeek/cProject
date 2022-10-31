#include <iostream>
using namespace std;
using ll = long long int;
int main()
{
  // 请在此输入您的代码
  ll max = 1000000007;
  ll result = 0;
  ll m = 999999999;
  for(ll i = 1; i <= max;i++)
  {
    if((i*2021)%max == m)
    {
      result = i;
      break;
    }
  }
  printf("%lld",result);
  return 0;
}
