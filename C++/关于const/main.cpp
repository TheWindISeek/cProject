#include <iostream>

using namespace std;

int main()
{
    int i=0;
    const int &r1=i;
    const int &r2=42;
    const int &r3=r1*2;
    //ʵ������������ð󶨵���һ����ʱ������ȥ������ָ������һ�£�ȷʵ�ж�Ӧ�ĵ�ַ
    double dval = 3.14;
    const int &r5=dval;
    //��������ָ��ָ�����������ã�Ŀ���ǿ��������ڴ����Ƿ�ռ��λ�ã�Ҳ����˵��Ϊһ����������
    const int *p=&r2;
    const int *p2=&r3;
    //�����ǿ�������Ƿ񱻰󶨵�һ���ˣ������ԣ���û�У����ߵĵ�ַ������ͬ
    double *pd=&dval;
    const int *pi = &r5;
    cout<<pd<<endl;
    cout<<pi<<endl;
    cout<<p2<<endl;
    cout<<p<<endl;
    //�����ָ��������������const�ᱨ��ָ��ָ�������Ӧ�������Ļ�����һ��
    /*const double pi=3.14;
   double *ptr=&pi;*/
   /*����const��ָָ�������һ���������ײ�const��ָ��ָ��Ķ�����һ��������Ҳ����˵�����ָ�������˵��
   ����const top_level const ||�ײ�const low_level const,����������const�Ƕ�������ԣ�����const�Ǳ�ʾ����Ķ����ǳ��������κ��������Ͷ����á�
   �ײ�const��ָ���������ء���ָ�����ֿ��Զ��ָ�����������ǳ���ָ����Ƕ���const��ָ�볣���ǵײ�const����������Ҫ��ʼ��*/
    //int &r4=r1 *2;
    cout<<r1<<endl;
    cout<<r2<<endl;
    cout<<r3<<endl;
    cout<<r5<<endl;
    //cout<<r4<<endl;
    //�������ʽ.�������ʽ���ڱ���ʱ�����滻��������������ʱ�滻
    constexpr int mf = 20;
    constexpr int limit = mf +1;
    const int *p = nullptr;
    constexpr int *q=nullptr;
    //����ָ����ָ�룬ָ�볣���ǳ�����ָ��������˵�������͵ġ�����ָ����ָ�룬��˵����ָ��Ķ����ǳ�����
    cout << "Hello world!" << endl;

    return 0;
}
