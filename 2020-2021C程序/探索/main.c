#include <stdio.h>
#include <stdlib.h>
float stu_ave(int *p,int n) //�����е�ַ����Ԫ�ظ���
{
  int i;
  float sum = 0;
  for(i = 0 ; i < n ; i++)
  sum += p[i];//p[i]  p��һ���е�ַ �Ѷ�ά����һ��һά�������Ծ���P[i] �����б���ÿ��Ԫ��
  return sum/n;
  }
int *stu_find(int (*p)[4],int num) //������һ���е�ַ����ָ��������գ�Ϊɶ������ָ���������Ϊ������
       // int  (*p)[4]; p++��ָ���ƶ�����[4]���൱�ڶ�ά������׵�ַa+1Ҳ����ת����һ�У������ؾ�������ָ������е�ַ
{
   return *(p+num);//������*�����н�����������ָ�뽵�����е�ַreturn��ָ�뺯��
}
void stu_print(int *p)//��ʾѡ����е���Ԫ�ص�ֵ
{
  int i;
  for(i = 0 ; i < 4; i++)//�г��ȵ�4
  printf("%d ",p[i]);
  printf("\n");
}
int main()
{
     int z;
    int s[3]= {1,2,3};
    int k;
    int a = 0;
    int b;
    printf("%p\n",&z);
    printf("%p\n",&s[2]);
    printf("%p\n",&s[1]);
    printf("%p\n",s);

    printf("%p\n",&k);
    printf("%p\n",&a);
    printf("%p\n",&b);

    int *p;
    int *pp;
    char c;
    long l;
    double d;
    printf("%p\n",&p);
    printf("%p\n",&pp);
    printf("%p\n",&c);
    printf("%p\n",&l);
    printf("%p\n",&d);
printf("\n%d\n",sizeof(*p));
printf("\n%d\n",sizeof(*pp));

    p++;
    printf("\n%p\n",p);
    p++;
    printf("%p\n",p);

    printf("%d\n",k);
    printf("%d",a);
    return 0;
  /*int num;
  int a[3][4] = {{89,98,34,21},{85,56,36,99},{34,86,59,73}};
  int *ret;
  printf("%f\n",stu_ave(*a,3*4));//ʵ�εĵ�ַҪ�ͺ������β�����ƥ�䣨���Ҫ����������е�ÿ��Ԫ��Ҫ���������Ԫ�ظ�����
  printf("Please enter the NO([0,2]):");
  scanf("%d",&num);*/
  /*if error*/
 /* ret = stu_find(a,num); //����ȥһ����ָ��(����ȥ�󷵻ص�ʱ��ή��)������ѡ��Ҫ��ʾ��ѧ���ɼ��������᷵��һ��ָ�벢����ret
  stu_print(ret);*/
  return 0;
}
