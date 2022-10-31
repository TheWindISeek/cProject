/*���پ���ת�������������飺
copt[n+1]����ʾÿ�еĵ�һ������Ԫ������Ԫ����λ��
num[n+1]����ʾÿ�еķ���Ԫ�صĸ���

���У�
copt[1]=1;
copt[i]=copt[i-1]+num[i-1] (i>=2��*/
                            //�ƺ�����C���ԣ���������
                            //2021/9/20 cpp��ͷ�ļ�
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define M 500
typedef struct
{
    int x;    //����Ԫ����
    int y;    //����Ԫ����
    int v;   //����Ԫ�ر����ֵ
}node;         //������Ԫ������Ӧ����Ԫ��
typedef struct
{
    int nu;   //�������
    int mu;   //�������
    int tu;   //�������Ԫ�صĸ���
    node data[2000];            //��ȻҪ��ô������飬̫������
}matrix;       //���������������Ԫ������ɵĽṹ
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
            num[i]=0;          //num�����ʼ��
        for(int i=1; i<=A.tu; i++)
        {
            int j=A.data[i].y;
            num[j]++;        //����ÿ�еķ���Ԫ�ص�ֵ
        }
        copt[1]=1;
        for(int i=2; i<=A.mu; i++)
            copt[i]=copt[i-1]+num[i-1];        //���ù�ʽ
        for(int i=1; i<=A.tu; i++)        //���ѷ���ÿ�з���Ԫ�ض��ǰ��еĴ�С��С��������
        {
            int j=A.data[i].y;
            int k=copt[j];
            B.data[k].x=A.data[i].y;
            B.data[k].y=A.data[i].x;
            B.data[k].v=A.data[i].v;
            copt[j]++;          //���е�һ������Ԫ�ص�λ��+1
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

