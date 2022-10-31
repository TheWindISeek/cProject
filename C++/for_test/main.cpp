#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int z;
    int s[3]= {1,2,3};
    int k;
    int a = 0;
    int b;
    printf("%p\n",&z);
    printf("%p\n",&s[2]);
    printf("%p\n",&s[1]);
    printf("%p\n",s);

    printf("%p\n",&k);
    printf("%p\n",&a);
    printf("%p\n",&b);

    int *p = &s[2];
    int *pp;
    char c;
    long l;
    double d;
    printf("%p\n",&p);
    printf("%p\n",&pp);
    printf("%p\n",&c);
    printf("%p\n",&l);
    printf("%p\n",&d);
printf("\n%d\n",sizeof(p));
printf("\n%d\n",sizeof(pp));

    p++;
    printf("\n%p\n",p);
    p++;
    printf("%p\n",p);

    printf("%d\n",k);
    printf("%d",a);
    return 0;
}
