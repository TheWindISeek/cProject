#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
/*
��Ŀ����
���ý�������ȥ���͸��Ӷ�
������� ��ȡ˫���α�
һ���α����ڱ�������
��һ���α�ȥ����ǰ��ĵط�
����������Ҫ��ɾ���ķ�Χ��
�Ͱ������ڵ�һ�� ��Ӧ�ļ�¼���ȼ�1
��󷵻ؼ�¼�ĳ��� ������
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
