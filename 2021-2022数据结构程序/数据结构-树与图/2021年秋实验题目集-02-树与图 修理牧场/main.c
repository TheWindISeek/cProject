//�������������
#include <stdio.h>
#include <stdlib.h>
#define N 10005
#define MAX 50*10005
/*
���磬Ҫ������Ϊ20��ľͷ��ɳ���Ϊ8��7��5�����Σ�
��һ�ξ�ľͷ����20����ľͷ���12��8��
�ڶ��ξ�ľͷ����12��������Ϊ12��ľͷ���7��5���ܻ���Ϊ32��
�����һ�ν�ľͷ���15��5����ڶ��ξ�ľͷ����15���ܻ���Ϊ35
*/
/*
��ʵ���ǹ����������ϲ���Ҷ���Ľ��Ȩֵ֮��
*/
//����֮ǰû����ԭ�������� �����̫С �������Ľ�������㲻���� ���ǽ����ɵ���Щ��Ϣ ����Ŀ����������̫С û�в����
//������Χû�úÿ��� ���˵Ĵ�����ֱ������� ����û�����Χ������
typedef struct Node{
    int weight;
    int visit;
}code;
int main (){
    int i,n,j;
    scanf("%d",&n);
    code huff[2*n-1];
    for(i = 0; i < 2*n-1;++i)
        huff[i].visit = 0;
    for(i = n; i < 2*n-1;++i)
        huff[i].weight = 0;
    for(i = 0; i < n;++i)
        scanf("%d",&huff[i].weight);
    int x1,x2,m1,m2;
      for (i = 0; i < n - 1; i++) {
        x1 = x2 = MAX;
        m1 = m2 = 0;
        for (j = 0; j < n + i; j++) {
            if (!huff[j].visit && huff[j].weight < x1) {

                //printf("%d:%d %d\n",j,huff[j].weight,huff[j].visit);
                x2 = x1;
                m2 = m1;
                x1 = huff[j].weight;
                m1 = j;
            }
            else if (!huff[j].visit && huff[j].weight < x2) {
                                //printf("%d:%d %d\n",j,huff[j].weight,huff[j].visit);
                x2 = huff[j].weight;
                m2 = j;
            }
        }
          huff[m1].visit = 1;
          huff[m2].visit = 1;
          //printf("%d %d\n",huff[m1].weight,huff[m2].weight);
          huff[n + i].weight = huff[m1].weight + huff[m2].weight;
    }
//     for(i = 0; i < 2*n-1;++i)
//                 printf("%d:%d %d\n",i,huff[i].weight,huff[i].visit);
    int sum = 0;
    for(i = n; i < 2*n-1;++i)
    {

        sum += huff[i].weight;
    }
    printf("%d",sum);
    return 0;
}
