#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
//try �������ã����Կ�Խ������������һ������߿ɶ���,catch�Ჶ׽�����throw����Ȼ�о��ܹ֣�������˼Ӧ�û��Ƕ���
//���⣬����Ҫ�����Լ���һ����goto�����ñ�ǩ��˼Ҫ��ȷ���ñ���֪������������������ģ��ҵ�ϰ���Ǳ�ǩ���Ǵ�д��
//������throw ���������ܱ�ͬһ����catch��׽�Ļ����ǿ��Ⱥ�˳�������϶��µ��߼�˳��
using namespace std;
void correct (void)
{
     throw runtime_error("�����㰡����˴���");
}
 void match (int &i,int &n)
{
    i--;
    n--;
    if(i==0&&n==0)
    {  throw "����������";
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
        cout<<err.what()<<endl<<"�Կ����յ���򣬱��ǳ��������"<<endl<<"��������ٴ����룬��y��n��"<<endl;
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
