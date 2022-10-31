#include <iostream>

using namespace std;
typedef string::size_type sz;
//需要注意的是 一旦有一个形参被用默认实参的情况进行了赋值，所有的形参都需要进行赋值。如果想调用默认实参，只需要省略参数就可以调用了
 string screen (sz ht = 24,sz wid =80,sz background = ' ')
 {
     return "you";

 }
 //如果你前面使用了默认实参，后面也应该需要使用
 int key (int k,int z=0)
 {
     return 1;
 }
 //int amount (int k=0,int z);
 //另外需要注意的一点是不能用局部变量去修改默认实参的值
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
    //以下列方法进行赋值需要注意的是：给出的值会从前往后覆盖，所以不能前面什么都不写，只打几个逗号
    //所以建议将经常修改的实参的值放前面，便于进行修改
    window = screen();
    window = screen (66);
    window = screen (66,256);
    window = screen (66,256,'#');
    cout << "Hello world!" << endl;
    return 0;
}
