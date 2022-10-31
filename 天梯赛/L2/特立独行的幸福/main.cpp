//怎么判断一个数不是别人转化而来的 也就是问一个完全平方数的和的特点
//第二个是判断需要多少次迭代
//第三是判断死循环的 也就是不是幸福数的数字 素数搜索的感觉
//程序分成两半 第一半处理是不是的问题 是的话需要标注一下 哪些可能的需要去计算
//如果一个数在循环中出现了一个比它大且在这个区间中的数 那么这个数不是下一阶段的目标 如果有比它小的 则那个小的不是这个阶段的目标
//如果 虽然有幸福树 但是不是特立独行的那个 可能吗？
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int isPrime(int x)
{
    if(x <= 3)
        return 1;
    for(int i = 2; i <= sqrt(x); i++)
        if(x%i == 0)
            return 0;
    return 1;
}
//最基础的样例没有通过
int main ()
{
    int x, y, n, tmp;
    int flag= 1,f[10001]= {0},one[10001]; //是否是SAD 判断是否有环 判断是否是特立独行的 是就是1 不是是0
    int cnt[10001]= {0},c; //第一个是每个迭代的次数 第二个是每次迭代计算用的
    scanf("%d%d",&x,&y);
    memset(one,1,sizeof(one));
    for(int i = x; i <= y; i++)
    {
        memset(f,0,sizeof(f));
        c = 0;
        n = i;
        while(1)//为该数判断特立独行
        {
            f[n] = 1;
            tmp = 0;
            while(n)//计算迭代数
            {
                tmp += (n%10)*(n%10);
                //printf("%d %d\n",n,tmp);
                n /= 10;
            }
            n = tmp;
            c++;//每次迭代步数加加
            if(f[tmp])//如果已经出现过了 死循环需要退出
            {
                one[i] = 0;
                break;
            }
            if(tmp == 1)//结束条件
            {
                flag = 0;//不必输出SAD
                break;
            }
            if(tmp >= x && tmp <= y)
                    one[tmp] = 0;
        }
        cnt[i] = c;
    }
    if(flag)
        printf("SAD");
    else
    {
        for(int i = x; i <= y; i++)
        {
            //cout << i<<" "<<one[i] <<" "<< cnt[i]<<endl;
            if(one[i])
            {
                if(isPrime(i))
                    cnt[i]*=2;
                printf("%d %d\n",i,cnt[i]);
            }
        }
    }
    return 0;
}
