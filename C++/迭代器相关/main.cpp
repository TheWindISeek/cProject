#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int main()
{



 int k;
 vector<int> num;

 while(cin>>k)
 {
 num.push_back(k);
 }

for(decltype(num.size()) i=0;i!=num.size()-1;i++)
{
      cout<<num[i]+num[i+1]<<endl;
}
 cout<<endl;
    for(decltype(num.size()) i=0;i!=num.size()/2;i++)
    {
        cout<<num[i]+num[num.size()-i-1]<<' ';
    }
        cout<<endl;

        for(auto i=num.begin();i!=num.end()-1;i++)
        {
            auto k=i;
            cout<<*i  + *(++k)<<'='<<*i<<'+'<<*k<<endl;
        }
        cout<<endl;
        //���ǵ�������end������ָ����һ�����ǿյģ�Ҫ������Ҫ��1�ٸ�
        for(auto i=num.begin(),k=num.end()-1;i!=num.begin()+(num.end()-num.begin())/2;i++,k--)
        {

            cout<<*i<<'+'<<*k<<'='<<*i+*k<<endl;
        }

vector<unsigned> scores(11,0);
unsigned grade;
while(cin>>grade)
{
    if(grade<=100)
        ++*(scores.begin()+grade/10);
}
for(auto &i:scores)
{
    cout<<i<<endl;
}
/*д���������ʱ�������һ�����⣬����û�а취ȥ�������������ȡ��ԭ����cin�ڼ�⵽ctrl z+enter�����ֹ���룬���º�����cin������ȥ��ȡ���ɴ˳�������*/
    return 0;
}
