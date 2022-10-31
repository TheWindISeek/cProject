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
        //谨记迭代器的end函数是指向下一个，是空的，要引用需要减1再搞
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
/*写上述程序的时候出现了一个问题，就是没有办法去进行两次输入读取，原因是cin在检测到ctrl z+enter后会终止输入，导致后续的cin根本不去读取，由此出现问题*/
    return 0;
}
