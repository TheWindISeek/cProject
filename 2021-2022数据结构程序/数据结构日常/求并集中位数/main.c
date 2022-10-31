#include <stdio.h>
#include <stdlib.h>
/*
5
1 3 5 7 9
2 3 4 5 6
4
6
-100 -10 1 1 1 1
-50 0 2 3 4 5
1
*/


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
    //这里有问题
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
    printf("\n%d",mid[N-1]);
    //printf("Hello world!\n");
    return 0;
}
