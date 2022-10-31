#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
/*
题目分析
利用交换操作去降低复杂度
整体就是 采取双重游标
一个游标用于遍历数组
另一个游标去放在前面的地方
如果这个不在要求删除的范围内
就把它放在第一个 对应的记录长度加1
最后返回记录的长度 就行了
*/
int Delete( int A[], int L, int minA, int maxA ){
    int k = 0,temp;
    for(int i = 0; i < L;++i){
if(A[i]<=minA || A[i]>=maxA){
    temp = A[k];
    A[k] = A[i];
    A[i] = temp;
    k++;
}
    }
    return k;
}
