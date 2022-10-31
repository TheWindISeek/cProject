#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*for(int i = 1; i <= 100000000; ++i){
        sqrt(1.0 * i);
    }
    cout << clock() << "ms" << endl;
    for(int i = 1; i <= 100000000; ++i){
        __builtin_sqrt(1.0*i);//用于快速开平方 8位
    }
    cout << clock() << "ms" << endl;
    for(int i = 1; i <= 100000000; ++i){
        __builtin_sqrtf(1.0 * i);//4位
    }
    cout << clock() << "ms" << endl;*/
    ios::sync_with_stdio(0);
    cin.tie(0);

    //返回括号内数的二进制表示形式中末尾0的个数
    cout << __builtin_ctz(64) <<endl;
    cout << __builtin_ctzll(64) <<endl;//long long 版本

    //返回括号内数的二进制表示形式中前导0的个数
    cout << __builtin_clz(63) <<endl;
    cout << __builtin_clzll(63) <<endl;//long long 版本

    //返回括号内数的二进制表示形式中1的个数
    cout << __builtin_popcount(4095) << endl;

    //返回括号内数的二进制表示形式中1的个数的奇偶性
    cout << __builtin_parity(1) <<endl;

    //返回括号内数的二进制表示形式中最后一个1在第几位 从后往前数
    cout << __builtin_ffs(84) << endl;
    return 0;
}
