#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
//try 语句很有用，可以跨越函数，最后可以一起处理，提高可读性,catch会捕捉最近的throw，虽然感觉很怪，但是意思应该还是懂的
//另外，还需要提醒自己的一点是goto语句最好标签意思要明确，让别人知道这个语句是用来干嘛的，我的习惯是标签都是大写。
//另外多个throw 语句如果都能被同一级的catch捕捉的话，是看先后顺序，在自上而下的逻辑顺序
using namespace std;
void correct (void)
{
     throw runtime_error("看看你啊。如此聪明");
}
 void match (int &i,int &n)
{
    i--;
    n--;
    if(i==0&&n==0)
    {  throw "看看这个如何";
        correct();


    }
}
int main()
{

    int i,n;
    cin>>i>>n;

    try
    {
        match(i,n);
    }
    catch(runtime_error & err)
    {
        cout<<err.what()<<endl<<"试看今日的寰球，必是赤旗的世界"<<endl<<"如果你想再次输入，按y或n？"<<endl;
        /*char c;
        cout<<i<<n<<endl;
        cin>>c;
        if(c=='y')
            goto START;*/
    }
    catch(const char * str)
    {
        cout<<str<<endl;
    }
    return 0;
}
