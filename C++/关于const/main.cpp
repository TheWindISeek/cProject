#include <iostream>

using namespace std;

int main()
{
    int i=0;
    const int &r1=i;
    const int &r2=42;
    const int &r3=r1*2;
    //实际上下面的引用绑定到了一个临时变量上去，我用指针检查了一下，确实有对应的地址
    double dval = 3.14;
    const int &r5=dval;
    //我用两个指针指向这两个引用，目的是看引用在内存中是否占据位置，也就是说作为一个量存在着
    const int *p=&r2;
    const int *p2=&r3;
    //以下是看这二者是否被绑定到一起了，很明显，并没有，二者的地址并不相同
    double *pd=&dval;
    const int *pi = &r5;
    cout<<pd<<endl;
    cout<<pi<<endl;
    cout<<p2<<endl;
    cout<<p<<endl;
    //下面的指针变量如果不加上const会报错，指针指向的类型应该与他的基类型一致
    /*const double pi=3.14;
   double *ptr=&pi;*/
   /*顶层const是指指针变量是一个常量，底层const是指其指向的对象是一个常量，也就是说着针对指针变量来说的
   顶层const top_level const ||底层const low_level const,更甚，顶层const是对自身而言，顶层const是表示任意的对象都是常量，对任何数据类型都适用。
   底层const与指针和引用相关。而指针这种可以多次指向的玩意如果是常量指针就是顶层const，指针常量是底层const，常量必须要初始化*/
    //int &r4=r1 *2;
    cout<<r1<<endl;
    cout<<r2<<endl;
    cout<<r3<<endl;
    cout<<r5<<endl;
    //cout<<r4<<endl;
    //常量表达式.常量表达式会在编译时进行替换，而不是在运行时替换
    constexpr int mf = 20;
    constexpr int limit = mf +1;
    const int *p = nullptr;
    constexpr int *q=nullptr;
    //常量指针是指针，指针常量是常量，指针是用来说明其类型的。常量指针是指针，是说明其指向的东西是常量。
    cout << "Hello world!" << endl;

    return 0;
}
