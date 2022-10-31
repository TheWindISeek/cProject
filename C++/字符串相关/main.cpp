#include <iostream>

using namespace std;
using std::string;
int main()
{
    string word;
   /*
   string eof ("EOF");
    while(cin >>word)
        if(word==eof)
        break;
    else
    cout << word << endl;*/

   /*
   //输出一行字符串并判断其长度与指定数目的长度的关系
    while(getline (cin,word))
        //string::size_type是一种新类型
        if(word.size()>5)
        cout<<word<<endl;*/

    /*
     //读取一行，不包括换行
    while(getline(cin,word))
        if(!word.empty())
        cout<<word<<endl;*/


       /*
       //输出两个字符串里面长的那个
       string word1;
        string word2;
        cin>>word1>>word2;
        cout<<word1<<endl;
        cout<<word2<<endl;
  if(word1.size() > word2.size())
 {
     cout<<word1<<endl;
 }
 else
    cout<<word2<<endl;*/
    string words;
    int i=0,n;
    cout<<"请输入你将要输入多少个字符串"<<endl;
    cin>>n;
    for(;i<n;i++)
    {
        cin>>word;
        words=words+"|"+word;
    }
    cout<<words<<endl;
    return 0;
}
