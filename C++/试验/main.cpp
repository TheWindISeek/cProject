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
    printf("%d,%d", i, *j);//C++�����0��1������C�������1��1���ؼ�������const�����⣬C��constֻ���ڱ��붨�壬�����вų�ʼ������C++�Ǳ�����Ѿ���ʼ���ˡ�

    cout << "Hello world!" << endl;*/
    return 0;
}
