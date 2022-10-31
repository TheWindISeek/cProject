#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct Node
{
    int address;
    int data;
    int next_address;
};
typedef struct Node* List;

void swap(List * a,List * b) //交换两个结点的指针的指向
{
    List temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void print(List a[],int n)
{
    for(int i = 0; i<n ; i++)
    {
        if(i < n-1)
            printf("%05d %d %05d\n",a[i]->address,a[i]->data,a[i]->next_address);
        else
            printf("%05d %d -1\n",a[i]->address,a[i]->data);
    }

}

void change_address(List a[],int m)
{
    for(int i = 0; i<m; ++i)
    {
        if(i < m-1)
            a[i]->next_address=a[i+1]->address;
        else
            a[i]->next_address=-1;
    }
}
int main ()
{
    int N;//结点数
    int first;
    scanf("%d %d",&first,&N);
    //先读取所有信息
    List arr[N];
    int address[100001];
    int index[100001];
    for(int i = 0; i< N; ++i)
    {
        arr[i] = (List)malloc (sizeof(struct Node));
        scanf("%d %d %d",&(arr[i]->address),&(arr[i]->data),&(arr[i]->next_address));
        index[arr[i]->address] = i;
        address[arr[i]->address] = arr[i]->next_address;
    }

    int find = first;
    List a[N];
    int n = 0;//防止存在无用结点
    for(; find != -1 ; n++)
    {
        a[n] = arr[index[find]];
        find = address[find];
    }
    /*//原先的是j<n-1 段错误
    //现在的是 find != -1 答案错误
    for(int j = 0; j < n-1;++j){
        for(int i = j;i < n;++i){
            if(a[i]->address==find){
                find=a[i]->next_address;
                swap(&a[j],&a[i]);
                break;
            }
    }
    }*/
    /*  for(int i = 0,j=0; j<n-1; ++i)
      {
          if(a[i]->address==find)//找到目标地址
          {
            //  printf("此时的下标%d 对应的地址%05d 它的下一个地址%05d 与之交换的下标%d\n",i,find,a[i]->next_address,j);
              find=a[i]->next_address;
              swap(&a[j],&a[i]);
            //  print(a,n);
              i = j;
              j++;
          }
      }*/
    //记录所有绝对值
    int hash[10001]= {0};
    for(int i = 0; i< n; ++i)
    {
        hash[abs(a[i]->data)]++;
    }
    //分开数据
    List delete[n],pre[n];
    int k = 0,m=0;
    for(int i = 0; i < n; ++i)
    {
        if  ( hash[abs(a[i]->data)])
        {
            pre[k++] = a[i];
            hash[abs(a[i]->data)]=0;
        }
        else
        {
            delete[m++]=a[i];
        }
    }
    //先排好，再处理地址数据
    change_address(delete,m);
    change_address(pre,k);
    // printf("\n");
    print(pre,k);
    print(delete,m);
    return 0;
}
