#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=10;
    int num[10]={7,1,2,4,5,3,6,8,9,0};
    int i,k,j,temp;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(num[j]>num[k])
                k = j;
        }
        if(k!=i)
        {
            temp = num[i];
            num[i]= num[k];
            num[k]=temp;
        }
    }
    for(i=0;i<n;i++)
        printf("%4d ",num[i]);
    return 0;
}
