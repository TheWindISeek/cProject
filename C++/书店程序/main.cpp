#include <iostream>

using namespace std;

int main()
{
    int sum =0,value = 0;
    //cin ��ͬ��scanf��ʹ��
    while(std::cin>> value )
    {
        sum+=value;
        cout<<"sum is :"<<sum<<endl;
    }
    //�����޷��ź��з��Ű���������ת��,�Լ����ܻ���ֵ�����
    unsigned u=10;
    int i=-42;
    cout<<i+i<<endl;
    cout<<u+i<<endl;
    //���󣬻������ѭ����������Ϊ�������޷��ŵ�����
    for(u=10;u>=0;u--)
    {
        cout<<u<<endl;
    }
    return 0;
}
