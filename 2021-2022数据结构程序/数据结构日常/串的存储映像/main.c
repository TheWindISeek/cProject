#include <stdio.h>
#include <stdlib.h>
/*
串名的存储映像是串名-串值内存分配对照表 也称为索引表
常见的索引表有以下几种
*/
//带串长度的索引表
/*用一个去存放长度 */
typedef struct
{
    char name[MAXNAME]; /*串名*/
    int length; /*串长*/
    char *stradr; /*起始地址*/
} LNode;


//末尾指针的索引表
/*
从头到尾这样进行访问
*/
typedef struct
{
    char name[MAXNAME]; /*串名*/
    char *stradr,*enadr; /*起始地址，末尾地址*/
} ENode;


//带特征位的索引表
/*当一个串的存储空间不超过一个指针的存储空间时
可以直接将该串存在索引表项的指针域
这样既节约了存储空间，又提高查找速度
但需要添加一个特征位tag以指出指针域存放的是指针还是串
*/
typedef struct
{
    char name[MAXNAME];
    int tag; /*特征位*/
    union /*起始地址或串值*/
    {
        char *stradr;
        char value[4];
    } uval;
} TNode;

/*按照字母 数字 其他字符进行分类*/
int isCh(char c)//该字符是否为字母
{

    if(c >= 'a' && c <='z'||c >= 'A' && c <='Z')
        return 1;
    else
        return 0;
}
int isNum(char c)//该字符是否为数字
{

    if(c >= '0' && c <='9')
        return 1;
    else
        return 0;
}
void process(char r[],int n)
{
    int low = 0,high = n-1;
    while(low < high)
    {
        char k;
        while(low < high && isCh(r[low]))
            low++;
        while(low < high && !isNum(r[high]))
            high--;
        if(low < high)
        {
            k = r[low];
            r[low] = r[high];
            r[high] = k;
        }
    }
    ++low;
    high = n-1;
    while(low < high)
    {
        char k;
        while(low < high && isNum(r[low]))
            low++;
        while(low < high && !isNum(r[high]))
            high--;
        if(low < high)
        {
            k = r[low];
            r[low] = r[high];
            r[high] = k;
        }
    }
}
typedef struct{
int data[MAXSIZE];
int last;
}list;
void move(list* l,int m,int n)//m <= n
{
    int i,x;
    for(i = 1; i <= m ;++i){
        x = l ->data[0];
        for(k = 1;k <= l ->last;++k)
            l->data[k-1] = l->data[k];
        l ->data[l->last] = x;
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
