#include <stdio.h>
#include <stdlib.h>
//动态规划问题
//最优子结构
//重叠子问题
/*
子问题具有重复 使得用分治的思想处理困难 但是这同样也是一个好处 便于自底向上进行操作
而第二个也是很有意思的 最优子结构 它是建立在这样一个前提下的 需要说明的是不是所有的问题都满足这样一个性质的
最典型的就是寻路 我感觉做不到
回到动态规划 原问题要达到最优 子问题一定是最优
那么我子问题达到最优 就能 让原问题达到最优
这个时候重叠子问题就是最好的 因为重复就可以去简化 就像kmp那样
*/
#define MAX 50
#define inf 99999999
int p[MAX+1];             //存储各个矩阵的列数以及第一个矩阵的行数（作为第0个矩阵的列数）
int m[MAX][MAX];          //m[i][j]存储子问题的最优解
int s[MAX][MAX];           //s[i][j]存储子问题的最佳分割点
int n;                    //矩阵个数
 void matrix()
{

    int i,j,k;
    for(i=0;i<n;i++)
        m[i][i]=0;                  //最小子问题仅含有一个矩阵 ，对角线全为0

    for(i=2;i<=n;i++)
        for(j=0;j<n-i+1;j++)
        {
            m[j][j+i-1]=inf;
            for(k=0;k<i-1;k++)
            {                                    //k代表分割点
                if(m[j][j+i-1]>m[j][j+k]+m[j+k+1][j+i-1]+p[j]*p[j+k+1]*p[j+i])
                {
                    m[j][j+i-1]=m[j][j+k]+m[j+k+1][j+i-1]+p[j]*p[j+k+1]*p[j+i];
                    s[j][j+i-1]=k;                           //记录分割点
                }
            }
        }
}

 void printmatrix(int leftindex,int rightindex)//递归打印输出
{
    if(leftindex==rightindex)
		printf("%d",leftindex+1);
    else{
       printf("(");
        printmatrix(leftindex,leftindex+s[leftindex][rightindex]);
        printmatrix(leftindex+s[leftindex][rightindex]+1,rightindex);
        printf(")");

    }
}
int main()
{
    int i;
    printf("请输入矩阵相乘的矩阵个数");
    scanf("%d",&n);
 printf("请依次输入矩阵的行和烈（如A*B，A=20*30，B=30*40，即输入20 30 40)\n" );
    for(i=0;i<n+1;i++)
    {
        scanf("%d",&p[i]);
    }
    matrix();
    printf("矩阵连乘最小次数: %d\n",m[0][n-1]);
    printmatrix(0,n-1);
	system("pause");
    return 0;
}
