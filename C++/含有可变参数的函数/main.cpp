#include <iostream>

using namespace std;
//C++�������ת��
//static_cast<����> (�������߱��ʽ)   �����ھ����������ת��
//const_cast<> () �����ڶԳ���ת��Ϊ�ǳ���������ת��
//reinterpret_cast <> () ��Σ�յ�һ�֣������
//C�������ת��
//(����) ���� ���� (����)




//��ӡ�ַ���
void error_msg (initializer_list<string> il)
{
    for(auto beg= il.begin();beg!=il.end();++beg)
    {
        cout<<*beg<<endl;
    }
}
//����������
int sum_int (initializer_list<int > ok)
{
    long sum=0;
    for(auto beg=ok.begin();beg!=ok.end();++beg)
    {
        sum+=*beg;
    }
    return static_cast<int> (sum);
}
int main()
{
    error_msg({"hello","my","friend"});

    cout<<  sum_int({1,2,3,4})<<endl;
    return 0;
}
