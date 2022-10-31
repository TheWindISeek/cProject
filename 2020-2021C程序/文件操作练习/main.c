
#include<stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    int n,m;
    if((fp=fopen("data.txt","r"))==NULL)
    {
        printf("´ò¿ªÊ§°Ü");
        exit(0);
    }
    fscanf(fp,"%d",&n);
    fscanf(fp,"%d",&m);
    fclose(fp);
    printf("%d\t%d",n,m);
    return 0;
}



