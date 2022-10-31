#include <iostream>
#include <cstdio>
#include<cstdio>
using namespace std;


int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int max = b > c ? b : c;
    max = a > max ? a : max;

    if(max == a)
        printf("%d,%d,%d",a,b > c ? b : c,b < c ? b : c);
    else if( max == b)
        printf("%d,%d,%d",b,a > c ? a : c,a < c ? a : c);
    else if( max == c)
        printf("%d,%d,%d",c,b > a ? b : a,b < a ? b : a);
    /*const int i = 0;
    int *j = (int *) &i;
    *j = 1;
    printf("%d,%d", i, *j);//C++输出是0，1。而在C中输出是1，1。关键点在于const的问题，C中const只是在编译定义，在运行才初始化。而C++是编译就已经初始化了。

    cout << "Hello world!" << endl;*/
    return 0;
}
