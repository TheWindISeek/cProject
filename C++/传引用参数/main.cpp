#include <iostream>
#include "think.h"
using namespace std;
extern string::size_type find_char (const string &s,char c,string::size_type &occurs);
int main()
{
   string s("here comes the sun");
   char a;
   cin>>a;
   double k=1e5;
   decltype(s.size()) occurs;
   auto index = find_char (s,a,occurs);
   cout<<s<<' '<<a<<' '<<occurs<<' '<<index<<endl;
   cout<<fact(2)<<endl;
   cout<<myABS(k)<<endl;
    return 0;
}
int fact(int i)
{
    return i;
}
double myABS(double k)
{
    double a=k;
    return a;

}
string :: size_type find_char(const string &s, char c,string :: size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for( decltype (ret) i=0  ;i!= s.size(); ++i)
    {
        if(s[i] ==c )
        {
            if(ret == s.size())
             ret = i;
             ++occurs;
        }
    }
    return ret;
}

