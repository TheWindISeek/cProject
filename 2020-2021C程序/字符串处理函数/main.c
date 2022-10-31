#include <stdio.h>
#include <stdlib.h>
void mystrcpy1 (char dststr [],char srcstr [])//复制字符串
{

    int i=0;
    while(srcstr[i]!='\0')
    {
        dststr[i]=srcstr[i];
        i++;
    }
    dststr[i]='\0';
}
void mystrcpy2 (char *dststr,char * srcstr)
{
    while(*srcstr !='\0')
    {
        *dststr = *srcstr;
        srcstr ++;
        dststr ++;
    }
    *dststr = '\0';
}
unsigned int mystrlen1 (const char str[])//计算字符串长度
{
    int i;
    unsigned int len = 0;
    for(i=0;str[i]!='\0';i++)
    {
        len++;
    }
    return len;
}
unsigned int mystrlen2 ( const char *pstr)
{
    unsigned int len =0;
    for(;*pstr!='\0';pstr++)
    {
        len++;
    }
    return len;
}
char *mystrcat (char *dststr, char *srcstr)//连接字符串
{
    char *pstr = dststr;
    while(*dststr!='\0')
    {
        dststr++;
    }
    for(;*srcstr!='\0';dststr++,srcstr++)
    {
        *dststr = *srcstr;
    }
    *dststr = '\0';
    return pstr;
}
int mystrcmp1 (char *p1, char *p2)//比较两个字符串的大小，不是长度
{
    for(;*p1==*p2;p1++,p2++)
    {
        if(*p1=='\0')
            return 0;
    }
    return (*p1-*p2);
}
int mystrcmp2 (char s[],char t[])
{
    int i;
    for(i=0;s[i]==t[i];i++)
    {
        if(s[i]=='\0')
            return 0;
    }
    return (s[i]-t[i]);
}

int main()
{
    char ch1 []="I LOVE YOU";
    char ch2 []="I LOVE C++";

mystrcpy1(ch1,ch2);
printf("%u",mystrlen1(ch1));
 printf("%s\n",ch1);

    return 0;
}

