#include <iostream>

using namespace std;
//���� �����ǶԵ� ����ȥ�����Ե������
int main()
{
    long long x;
    scanf("%lld",&x);
    x/=1000;//����
    x%=(60*60*24);
    printf("%lld\n",x);
    int hh,mm,ss;
    hh = x/3600;
    ss = x%60;
    mm = x/60%60;
    printf("%02d:%02d:%02d",hh,mm,ss);
    return 0;
}
