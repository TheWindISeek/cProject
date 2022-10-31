#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int  N = 15;
    int num[15] = {1,4,1,2,3,4,5,6,1,7,5,0,4,9,8,1};
    int arr[15];
    int c = 0;
    int flag = 1;
    for(int i = 0; i <N; i++)
    {
        flag = 1;
        for(int j = i+1 ; j<N; j++)
            if(num[j] == num[i])
                flag = 0;
        if(flag)
            arr[c++] = num[i];
    }
    for(int i = 0 ;i <c;i++)
        printf("%4d",arr[i] );
    return 0;
}
