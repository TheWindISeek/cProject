#include <stdio.h>
int *p;
int SC (void);//���볤��
int SR (int a,int b[]);//�������ݺ���Ҫ��ķ�Χ
int SWAP (int,int,int b[],int num[]);  //ѡ������
void SK(int a,int b[]);
void main ()
{
    int a=SC();
    int b[a];
    if(SR(a,b))
      SK(a,b);
}
int SC(void)
{
    int a;
    do
    {
        printf("�����볤��\n");
        scanf("%d",&a);
    }
    while (a<=0);
    return a;
}
int SR(int a,int b[])
{
    int i=0;
    printf("����������(�Կո�Ϊ�ֽ�)\n");
   do{
     scanf(" %d",&b[i]);
     i++;
   }while (i<a);
}
void SK (int a,int b[])
{
    int q,w;
    printf("����������Ҫ���ݵķ�Χ(�������� ����1/2)\n");
AS:
    fflush(stdin);
    scanf("%d/%d",&q,&w);
    if(q<=0||w<=0||q>a||w>a)
    {
        printf("����������\n");
        goto AS;
    }
    int min = q<w?q:w;
    int max = q>w?q:w;
    int num[a];
    int k = SWAP(min-1,max,b,num);
    for(int k=0;k<*p;k++)
    {printf("��%dλ�ϵ����\n",num[k]+1);
    printf("ֵΪ%d\n",b[num[k]]);}
    printf("����Ϊ�źõ�����\n");
    if(SWAP(0,a,b,num))
        for(int k=0; k<a; k++)
            printf("��%d��%2d\n",k+1,b[k]);
}
int SWAP (int min,int max,int b[],int num[])
{
    int i,j,k,temp;
   static int c=0;
   int a=0;
   p=&a;
    for(i=min; i<max-1; i++)
    {
        k=i;
        for(j=i+1; j<max; j++)
        {
            if(b[j]>b[k])
                k=j;
        }
        for(j=i+1; j<max; j++)
            if(b[k]==b[j])
        {
            num[0]=j;
            num++;
            a++;
        }
        if(c<1)
        {
            c++;
            return k;
        }
        if(k!=i)
        {
            temp = b[k];
            b[k]=b[i];
            b[i]=temp;
        }
    }
    return 1;
}
