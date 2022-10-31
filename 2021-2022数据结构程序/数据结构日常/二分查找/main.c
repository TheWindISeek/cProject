#include <stdio.h>
int binarySearch (int a[],int data,int n){
    int begin = 0,end = n-1;
    int mid = (end-begin)/2+begin;
    while(begin <= end){
        if(data < a[mid])
        {
            end = mid-1;
            mid = (end-begin)/2+begin;
        }
        else if(data > a[mid]){
            begin = mid +1;
            mid = (end-begin)/2+begin;
        }else
            return mid;
    }
    return -1;
}
int main (){
    int i,n,m,flag = 1,data;
    scanf("%d %d",&n,&m);
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);
    while(m--)
    {
        scanf("%d",&data);
        int p = binarySearch(a,data,n);
        if(flag)
            flag = 0;
        else
            printf(" ");
        printf("%d",p);
    }
    return 0;
}
