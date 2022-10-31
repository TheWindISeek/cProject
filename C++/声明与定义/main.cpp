#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
/*
//声明与定义相关，关于定义与声明的区别可参考函数的相关定义与声明
extern int q;//声明
int q;//定义
extern int z=1;//定义，虽然有extern，但其仍然是定义*/
int main()
{
//引用相关，引用本身并不是一个对象，无法解绑
    int i=0;
    int &ik=i;
    int *p=&ik;
    int &w=*p;
    int *ip=nullptr;
    cout<<ip<<endl;
  //r为指针pi的引用
   /* int *pi;
    int* &r=pi;
    r=&i;
    *r=4;
    cout<<i<<endl;*/
    //下面二者其实相同，但是NULL是预处理变量，nullptr是字面值。C++最好使用nullptr
  //  int *ptr=NULL;
   // int *ptr=nullptr;
    cout<<w<<endl;

    //指针也可用来做为条件判断，如果为0或者是nullptr就是假false，else true
    //if(!p)
    cout<<p<<endl;//地址默认16进制输出，前面有前导符0x
    //非法会报错
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
