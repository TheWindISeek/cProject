#include <stdio.h>
#include <stdlib.h>
//这是我另外一个实验集的答案
//鉴于这题完全没改变 而且思路简单 就直接使用了我自己的代码交上去了
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
