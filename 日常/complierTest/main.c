#include <stdio.h>
#include <stdlib.h>

int main()
{
    {
       char c = 'A';
        printf("%c\n",c);
    }
    {
        char c = 65;
        printf("%c\n",c);//һ��
    }
    {
        char c = 49;
        printf("%c\n",c);
    }
    {
        int i = 1;
        printf("%d\n",i);//һ��
    }
    {
        char c;
        scanf("%c",&c);
    }
    {
        int i;
        scanf("%d",&i);
        printf("%d",i+1);
    }
    return 0;
}
