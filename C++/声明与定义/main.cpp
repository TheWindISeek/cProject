#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
/*
//�����붨����أ����ڶ���������������ɲο���������ض���������
extern int q;//����
int q;//����
extern int z=1;//���壬��Ȼ��extern��������Ȼ�Ƕ���*/
int main()
{
//������أ����ñ�������һ�������޷����
    int i=0;
    int &ik=i;
    int *p=&ik;
    int &w=*p;
    int *ip=nullptr;
    cout<<ip<<endl;
  //rΪָ��pi������
   /* int *pi;
    int* &r=pi;
    r=&i;
    *r=4;
    cout<<i<<endl;*/
    //���������ʵ��ͬ������NULL��Ԥ���������nullptr������ֵ��C++���ʹ��nullptr
  //  int *ptr=NULL;
   // int *ptr=nullptr;
    cout<<w<<endl;

    //ָ��Ҳ��������Ϊ�����жϣ����Ϊ0������nullptr���Ǽ�false��else true
    //if(!p)
    cout<<p<<endl;//��ַĬ��16���������ǰ����ǰ����0x
    //�Ƿ��ᱨ��
    //int &i=10;
    int &k=ik;
    int a=ik;
    cout<<i<<endl;
    cout<<k<<endl;
    cout<<a<<endl;
    ik++;
    //i=0;
    //ik=10;
    cout<<i<<endl;
    cout<<k<<endl;
    cout<<a<<endl;
     cout << "Hello world!" << endl;
    return 0;
}
