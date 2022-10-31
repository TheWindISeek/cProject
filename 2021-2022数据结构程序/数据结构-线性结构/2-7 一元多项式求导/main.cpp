//以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数
//以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。
#include <iostream>
#include <cstdlib>
using namespace std;
int main (){
    //就是输入为0就可以结束了 这样的话就是不知道长度
    //如果非要存储，那么就是要利用链表之类的 或者使用到 输入一个输出一个 这个方法最简单
    //我选择采取第二个方法 如果是第一个方法 从代码量来说 肯定是大了不少的
    //那么就是编写代码的问题和输出规范的问题
    int exp,cof;
    scanf("%d %d",&cof,&exp);
    //首先读取一次 然后接下来进行判断
    if(exp)
     printf("%d %d",cof*exp,(exp-1));
    else{
         printf("0 0");
        return 0;
    }
   do{
       if(cin >> cof >> exp && exp){
          // if(cof * exp)
           printf(" %d %d",cof*exp,(exp-1));
       }else
           break;
   }while(1);
    return 0;
}
