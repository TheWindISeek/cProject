#include <iostream>

using namespace std;
typedef string::size_type sz;
//��Ҫע����� һ����һ���βα���Ĭ��ʵ�ε���������˸�ֵ�����е��βζ���Ҫ���и�ֵ����������Ĭ��ʵ�Σ�ֻ��Ҫʡ�Բ����Ϳ��Ե�����
 string screen (sz ht = 24,sz wid =80,sz background = ' ')
 {
     return "you";

 }
 //�����ǰ��ʹ����Ĭ��ʵ�Σ�����ҲӦ����Ҫʹ��
 int key (int k,int z=0)
 {
     return 1;
 }
 //int amount (int k=0,int z);
 //������Ҫע���һ���ǲ����þֲ�����ȥ�޸�Ĭ��ʵ�ε�ֵ
 sz
 sz wd = 80;
 char def = ' ';
 sz ht();



 void f2 ()
 {

     def='*';
     sz wd = 100;

 }
int main()
{
    string window;
    //�����з������и�ֵ��Ҫע����ǣ�������ֵ���ǰ���󸲸ǣ����Բ���ǰ��ʲô����д��ֻ�򼸸�����
    //���Խ��齫�����޸ĵ�ʵ�ε�ֵ��ǰ�棬���ڽ����޸�
    window = screen();
    window = screen (66);
    window = screen (66,256);
    window = screen (66,256,'#');
    cout << "Hello world!" << endl;
    return 0;
}
