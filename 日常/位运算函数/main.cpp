#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*for(int i = 1; i <= 100000000; ++i){
        sqrt(1.0 * i);
    }
    cout << clock() << "ms" << endl;
    for(int i = 1; i <= 100000000; ++i){
        __builtin_sqrt(1.0*i);//���ڿ��ٿ�ƽ�� 8λ
    }
    cout << clock() << "ms" << endl;
    for(int i = 1; i <= 100000000; ++i){
        __builtin_sqrtf(1.0 * i);//4λ
    }
    cout << clock() << "ms" << endl;*/
    ios::sync_with_stdio(0);
    cin.tie(0);

    //�������������Ķ����Ʊ�ʾ��ʽ��ĩβ0�ĸ���
    cout << __builtin_ctz(64) <<endl;
    cout << __builtin_ctzll(64) <<endl;//long long �汾

    //�������������Ķ����Ʊ�ʾ��ʽ��ǰ��0�ĸ���
    cout << __builtin_clz(63) <<endl;
    cout << __builtin_clzll(63) <<endl;//long long �汾

    //�������������Ķ����Ʊ�ʾ��ʽ��1�ĸ���
    cout << __builtin_popcount(4095) << endl;

    //�������������Ķ����Ʊ�ʾ��ʽ��1�ĸ�������ż��
    cout << __builtin_parity(1) <<endl;

    //�������������Ķ����Ʊ�ʾ��ʽ�����һ��1�ڵڼ�λ �Ӻ���ǰ��
    cout << __builtin_ffs(84) << endl;
    return 0;
}
