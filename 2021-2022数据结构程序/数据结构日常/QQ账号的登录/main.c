#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ACCOUNT_MAXSIZE 20
#define PASSWORD_MAXSIZE 18
#define HASH_SIZE 1000003
struct node
{
    char account[ACCOUNT_MAXSIZE+1];
    char password[PASSWORD_MAXSIZE+1];
    struct node * next;
};
typedef struct node* list;
int Hash(int key,int size)
{
    return key % size;
}
int insert(list h[],char account[],char password[])
{
    int p = Hash(atoi(account+5),HASH_SIZE);
    struct node * ptr = NULL;
    if(h[p] != NULL)
    {
        ptr = h[p];
        while(ptr)
        {
            if(strcmp(ptr->account,account) == 0)
                return -1;
            ptr = ptr->next;
        }
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        strcpy(temp->account,account);
        strcpy(temp->password,password);
        temp->next = NULL;
        ptr = temp;
        return p;
    }
    else
    {
        h[p] = (struct node *)malloc(sizeof(struct node));
        strcpy(h[p]->account,account);
        strcpy(h[p]->password,password);
        h[p]->next = NULL;
        return p;
    }
}
void NewAccountNumber(list h[])
{
    char account[ACCOUNT_MAXSIZE+1];
    char password[PASSWORD_MAXSIZE+1];
    scanf("%s",account);
    scanf("%s",password);
    int p = insert(h,account,password);
    if(p == -1)
        printf("ERROR: Exist\n");
    else
        printf("New: OK\n");
}
void Login(list h[])
{
    char account[ACCOUNT_MAXSIZE+1];
    char password[PASSWORD_MAXSIZE+1];
    scanf("%s",account);
    scanf("%s",password);
    int p = Hash(atoi(account+5),HASH_SIZE);
    struct node * ptr = NULL;
    if(h[p] == NULL)
        printf("ERROR: Not Exist\n");
    else//´æÔÚÊý¾Ý
    {
        ptr = h[p];
        while(ptr)
        {
            if(strcmp(ptr->account,account)==0)
            {
                if(strcmp(ptr->password,password))
                    printf("ERROR: Wrong PW\n");
                else
                    printf("Login: OK\n");
                return;
            }
            ptr = ptr ->next;
        }
        printf("ERROR: Not Exist\n");
        return;
    }
}
int main ()
{
    int n,i;
    char op;
    list h[100003] = {NULL};
    scanf("%d",&n);
    for(i = 0; i<n; ++i)
    {
        scanf("\n%c",&op);
        switch(op)
        {
        case 'L':
            Login(h);
            break;
        case 'N':
            NewAccountNumber(h);
            break;
        }
    }
    return 0;
}
