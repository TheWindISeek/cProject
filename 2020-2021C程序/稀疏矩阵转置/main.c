/*快速矩阵转置利用两个数组：
copt[n+1]：表示每列的第一个非零元素在三元组表的位置
num[n+1]：表示每列的非零元素的个数

其中：
copt[1]=1;
copt[i]=copt[i-1]+num[i-1] (i>=2）*/
                            //似乎不是C语言，能理解就行
                            //2021/9/20 cpp的头文件
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define M 500
typedef struct
{
    int x;    //非零元素行
    int y;    //非零元素列
    int v;   //非零元素本身的值
}node;         //即非零元素所对应的三元组
typedef struct
{
    int nu;   //矩阵的行
    int mu;   //矩阵的列
    int tu;   //矩阵非零元素的个数
    node data[2000];            //居然要这么大的数组，太粗心了
}matrix;       //整个矩阵的所有三元组所组成的结构
matrix A;
matrix B;
int copt[M];
int num[M];
void trans_A()
{
    B.mu=A.nu;
    B.nu=A.mu;
    B.tu=A.tu;
    if(B.tu>0)
    {
        for(int i=1; i<=A.mu; i++)
            num[i]=0;          //num数组初始化
        for(int i=1; i<=A.tu; i++)
        {
            int j=A.data[i].y;
            num[j]++;        //计算每列的非零元素的值
        }
        copt[1]=1;
        for(int i=2; i<=A.mu; i++)
            copt[i]=copt[i-1]+num[i-1];        //套用公式
        for(int i=1; i<=A.tu; i++)        //不难发现每行非零元素都是按列的大小从小到大排序
        {
            int j=A.data[i].y;
            int k=copt[j];
            B.data[k].x=A.data[i].y;
            B.data[k].y=A.data[i].x;
            B.data[k].v=A.data[i].v;
            copt[j]++;          //该列第一个非零元素的位置+1
        }
    }
}
int main()
{
    int r,c;
    int t=1;
    int num;
    scanf("%d%d",&r,&c);
    A.nu=r;
    A.mu=c;
    A.tu=0;
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            scanf("%d",&num);
            if(num!=0)
            {
                A.data[t].x=i;
                A.data[t].y=j;
                A.data[t].v=num;
                t++;
                A.tu++;
            }
        }
    }
    trans_A();
    t=1;
    int sum=0;
    for(int i=1; i<=c; i++)
    {
        for(int j=1; j<=r; j++)
        {
            if(B.data[t].x==i&&B.data[t].y==j)
            {
                printf("%d ",B.data[t].v);
                t++;
            }
            else
                printf("0 ");
            sum++;
            if(sum%r==0)
                printf("\n");
        }
    }
    return 0;
}

