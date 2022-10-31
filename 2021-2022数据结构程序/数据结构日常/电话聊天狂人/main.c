#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 1000000
//每个结点的信息
typedef struct node
{
    char s[12];
    int c;
    struct node * next;
} Node;
//封装一下方便使用
typedef Node* list;
typedef Node* Position;
typedef struct TbNode * HashTable;
//hash表的定义
struct TbNode
{
    int tablesize;
    list heads;
};
//找出大于n的最小质数
int nextPrime(int n)
{
    int i, p = (n%2) ? n+2: n+1;
    while(p <= N)
    {
        for(i = (int)sqrt(p); i > 2; i--)
            if(!(p%i))
                break;
        if(i == 2)
            break;
        else
            p += 2;
    }
    return p;
}
//创建hash表
HashTable creatHash(int tablesize)
{
    HashTable h;
    int i;
    h = (HashTable)malloc(sizeof(struct TbNode));
    h->tablesize = nextPrime(tablesize);
    h->heads = (list)malloc(sizeof(struct node)*h->tablesize);
    for(i = 0; i < h->tablesize; i++)
    {
        h->heads[i].s[0] = '\0';
        h->heads[i].next = NULL;
        h->heads[i].c= 0;
    }
    return h;
}
//根据键值返回对应的值
int Hash(int key,int p)
{
    return key%p;
}
//查找对应键值对应的位置
Position
Find(HashTable h, char* key)
{
    int pos;
    Position p;

    pos = Hash(atoi(key+6),h->tablesize);

    p = h -> heads[pos].next;

    while(p && strcmp(p->s,key))
        p = p->next;
    return p;
}
//输出
void
ScanAndOutput(HashTable H)
{
    int i,max=0,cnt = 0;
    char minphone[12];
    list ptr;
    minphone[0] = '\0';
    for(i = 0; i <H->tablesize; ++i)
    {
        ptr = H->heads[i].next;
        while(ptr)
        {
            if( ptr->c > max)
            {
                max = ptr->c;
                strcpy(minphone,ptr->s);
                cnt = 1;
            }
            else if(ptr->c == max)
            {
                cnt++;
                if(strcmp(minphone,ptr->s) > 0)
                    strcpy(minphone,ptr->s);
            }
            ptr = ptr -> next;
        }
    }
    printf("%s %d",minphone,max);
    if(cnt > 1) printf(" %d",cnt);
    printf("\n");
}
//插入新的元素
void
insert(HashTable h,char* key)
{
    Position p,newcell;
    int pos;

    p = Find(h,key);
    if(!p)
    {
        newcell = (Position)malloc(sizeof(struct node));
        strcpy(newcell->s,key);
        newcell->c = 1;
        pos = Hash(atoi(key+6),h->tablesize);
        newcell->next = h->heads[pos].next;
        h->heads[pos].next = newcell;
        return;
    }
    else
    {
        p->c++;
        return;
    }
}
int main ()
{
    int k,i;
    scanf("%d",&k);
    char key[12];
    HashTable hash =   creatHash(2*k);¶ÁÈ¡Êý¾Ý
    for(i=0; i<k; ++i)
    {
        scanf("%s",key);
        insert(hash,key);
        scanf("%s",key);
        insert(hash,key);
    }
    ScanAndOutput( hash);
    //DestroyTable(hash);
    return 0;
}
