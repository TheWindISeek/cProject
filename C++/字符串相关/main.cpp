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
   //���һ���ַ������ж��䳤����ָ����Ŀ�ĳ��ȵĹ�ϵ
    while(getline (cin,word))
        //string::size_type��һ��������
        if(word.size()>5)
        cout<<word<<endl;*/

    /*
     //��ȡһ�У�����������
    while(getline(cin,word))
        if(!word.empty())
        cout<<word<<endl;*/


       /*
       //��������ַ������泤���Ǹ�
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
    cout<<"�������㽫Ҫ������ٸ��ַ���"<<endl;
    cin>>n;
    for(;i<n;i++)
    {
        cin>>word;
        words=words+"|"+word;
    }
    cout<<words<<endl;
    return 0;
}
