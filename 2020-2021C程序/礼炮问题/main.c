
#include<stdio.h>
int main()
{
   int i=0,a=5,b=6,c=7,n=21,count=0;
    for(i=0;i<=100;i++)       //¼ÆËã5sµÄ´óÅÚ·¶Î§ÄÚµÄÌýµ½ÏìÉù
    {
         if(i%a==0||i%b==0||i%c==0)
         count++;
    }
    for(i=100;i<=120;i++)     // ¼ÆËã6sµÄ´óÅÚ·¶Î§ÄÚµÄÌýµ½ÏìÉù
    {
         if(i%b==0||i%c==0)
         count++;
    }
    for(i=120;i<=140;i++)     // ¼ÆËã7sµÄ´óÅÚ·¶Î§ÄÚµÄÌýµ½ÏìÉù
    {
         if(i%c==0)
         count++;
    }
    printf("n=%d",count);
    return 0;
}
