#include <stdlib.h>
#include<stdio.h>
#include <math.h>
#include <string.h>
#define maxLen 100
int SearchString(char a[], char b[])
{
    int i = 0, j = 0;
    int ans = 0;
    while (i < strlen(a) - strlen(b) + 1)
    {
        if (j == strlen(b))
        {
            ans = 1;
            return ans;
        }
        if (a[i + j] == b[j])
        {
            j++;
        }
        else
        {
            j = 0;
            i++;
        }
    }
    return -1;

}
int main()
{
    char a[maxLen];
    char b[maxLen];
    printf( "Input the first string:");
    gets(a);
    printf("Input the second string:");
    gets(b);
    if (SearchString(a,b)!=-1)
        printf( "Yes\n");
    else
        printf( "No\n");
    return 0;
}
