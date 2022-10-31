#include <stdio.h>
#include <stdlib.h>
int cs ()
{
    union check
    {
        int i;
        char ch;
    }c;
    c.i=1;
    return (c.i==1);

}
int main()
{
    char a[5]={'a','b','c','d'};
    char (*p1)[5]=&a;
    char (*p2)[5]=(char(*)[5])a;

    printf("a=%p\n",a);
    printf("a=%c\n",a[0]);
    printf("p1=%c\n",**p1);
    printf("p2=%c\n",**p2);
    printf("p1+1=%c\n",**(p1+1));
    printf("p2+1=%c\n",**(p2+1));


    int a[4]={1,2,3,4};
    int*      ptr1=(int *)(&a+1);
    int*      ptr2=(int *)((int)a-2);
    printf("%x,%x",ptr1[-1],*ptr2);
    return 0;


    struct text
    { char *pc;
        int num;
    }*p;

    printf("%x,%x,%x,%x",p,p+0x1,(unsigned long)p+0x1,(unsigned int*)p+0x1);
}
