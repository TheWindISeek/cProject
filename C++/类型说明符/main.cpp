#include <iostream>

using namespace std;

int main()
{
    //typedef˵����
    //�����������岢����ͬ��Ӧ���������� * ��ǰ�涨��Ķ�������Ӧ�ò𿪿���
    typedef char * pstring;
    const pstring cstr_ = 0;//ָ��char�ĳ���ָ��
    //�����˵�������char * const cstr_;��ͬ
       const char * cstr=0;//ָ��ָ���char�����ǳ���||ָ��const char��ָ��
const pstring *ps=nullptr;

//using˵����,�������͵ı�����Ŀǰ�һ�����ʹ��

//auto����˵����
//������ԣ�����Զ���const����������Եײ�const��������ö���const���������Լӣ�������Ա�������ɣ������Եײ�const����Ϊ����ֱ��˵�����ֽ׶����2021����
auto i=cstr;
int ci;
const int m=0;
auto &g=ci;
//ͬ���ģ�auto��Ȼ��ѭ���õ���ع��򣬲���const�޷��󶨵�����ֵ��ȥ�����������ᱨ��\
auto &h=42;
const auto &j=42;
//����Ҫע��һ�����auto�������е����ͻ�һ�£������һ�£���������ᱨ��ԭ����const int != int ѧ��constӦ����ʶ����һ�㡣����֮�����ͺ�constҲ���\
auto &n=i,*p2=&m;


//��Declared Type��Ҳ����decltype
const int y=0,&q=y;
decltype (y) x=0;
decltype (q) cq=y;
//����������ԭ����decltype�����Ὣ���ÿ�Ϊ���������͵����ͣ����ǿ������ã�Ҳ����Ҫ����ֵ��\
decltype (q) vc;
//��Ӧ����ʶ����decltype�Ľ���������������ͣ������ղ��õ������������������ʾʽ���յ�ֵ�����ֵ������������ͣ���ô�����Ҳ������������
int num = 13,*pint =&num,&r = num;
decltype (r+0) b;//bΪint���ͣ�ֻ�ж�rӦ�����������ͣ��������������0���ͱ�Ϊ��int ���ͣ����Զ�����ת����һ����
decltype (*pint) c=num;;//��ָ��Ľ����ã���Ӧ�����Ͳ�����ָ�����������Ӧ�����ͣ����Ƕ�Ӧ���͵����ã��ʴ˴��ᱨ����Ҫ��ʼ������initialized��
//������Ҫע���һ���������������������ˣ��������õ��������ͣ���ʱ��Ҫ��ʼ����˫������ʼ�������á�
/*
decltype ((i)) d;//����
decltype (i) b;//��ȷ
*/


    cout << "I LOVE C++!" << endl;
    return 0;
}
