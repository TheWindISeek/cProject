#include <stdio.h>
#include <stdlib.h>
//������ж�˼·
//���ȼ�¼�仯�㣬һ�ֱ仯��ȥ�жϳ��ȣ�ѡ����ĳ��ȣ���ӡ�����Χ������
//�����Ҿ���ʹ����߽���ұ߽�õ㣬��Ϊ����ֵ�һ������©�������
int main ()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i< n; ++i)
    {
        scanf("%d",&a[i]);
    }
    int mark[n];
    int k = 1;
    mark[0] = -1;
    //��¼
    for(int i = 0; i < n ; ++i)
    {
        if(i+1 == n)
        {
            //
           // printf("��¼��%d ��¼ֵ%d ��Ӧ��ֵ%d\n",k,i,a[i]);
            mark[k++] = i;
            break;
        }
        if(a[i]>=a[i+1])
        {
            //printf("��¼��%d ��¼ֵ%d ��Ӧ��ֵ%d\n",k,i,a[i]);
            mark[k++] = i;
        }
    }
  //  printf("\n");
    //�۲��¼���
  /*  for(int i = 0; i< k; i++)
    {
        printf("%d �±� %4d ֵ %d",i,mark[i],a[mark[i]]);
        printf("\n");
    }*/
    int max = mark[1]-mark[0];
    int index = 0;
    //�����
    for(int i = 0; i<k-1 ; ++i)
    {
        if(mark[i+1]-mark[i]+1 > max)
        {
            max = mark[i+1]-mark[i]+1;
            index = i;
        }
    }
  //  printf("index:%d max:%d",index,max);
  //  printf("\n");
    //��ӡ�
        for(int i = mark[index]+1; i < mark[index] + max; ++i)
        {
            if(i == mark[index] + max-1)
            {
                printf("%d",a[i]);
            }
            else
                printf("%d ",a[i]);
        }

    return 0;
}
