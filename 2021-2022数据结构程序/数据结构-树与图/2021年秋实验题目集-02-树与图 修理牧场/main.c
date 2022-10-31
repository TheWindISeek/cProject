//哈夫曼编码的题
#include <stdio.h>
#include <stdlib.h>
#define N 10005
#define MAX 50*10005
/*
例如，要将长度为20的木头锯成长度为8、7和5的三段，
第一次锯木头花费20，将木头锯成12和8；
第二次锯木头花费12，将长度为12的木头锯成7和5，总花费为32。
如果第一次将木头锯成15和5，则第二次锯木头花费15，总花费为35
*/
/*
其实就是哈夫曼编码上不是叶结点的结点权值之和
*/
//这题之前没过的原因是这里 定义的太小 导致最后的结果根本算不出来 就是结点组成的那些信息 而题目给的数据又太小 没有测出来
//这个最大范围没好好考虑 别人的代码是直接排序的 所以没有最大范围的问题
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
