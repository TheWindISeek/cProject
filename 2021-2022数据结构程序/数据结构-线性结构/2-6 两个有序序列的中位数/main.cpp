#include <stdio.h>
#include <stdlib.h>
//����������һ��ʵ�鼯�Ĵ�
//����������ȫû�ı� ����˼·�� ��ֱ��ʹ�������Լ��Ĵ��뽻��ȥ��
int main()
{
    int N;
    scanf("%d",&N);
    int a[N];
    int b[N];

    for(int i = 0; i< N;i++){
        scanf(" %d",&a[i]);
    }
    for(int i = 0;i< N;i++){
        scanf(" %d",&b[i]);
    }
    int k = 0;
    int mid[N+1];
    for(int i = 0,j = 0; i<N&&j<N;){
        if(a[i]>=b[j]){
            mid[k++] = b[j];
            j++;
        }
        else
        {
            mid[k++] = a[i];
            i++;
        }
        if(k == N+1)
            break;
    }
    printf("%d",mid[N-1]);
    return 0;
}
