#include <stdio.h>
#include <string.h>
#define N 80
void Inverse(char str[]);
int main()
{
    char a[N];
    printf("Input a string:\n");
    gets(a);
    Inverse(a);
    printf("Inversed results:\n");
    puts(a);
    return 0;
}

void Inverse(char str[])
{
    int   len, i, j;
    char  temp;
    len = strlen(str);
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
