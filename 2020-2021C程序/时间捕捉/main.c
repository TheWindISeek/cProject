#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo=localtime(&rawtime);
    char *s;
    char *str;
    s=asctime(timeinfo);
   str=asctime(timeinfo);
    FILE *fp;
    if((fp=fopen("time.txt","r"))==NULL)
    {
        printf("打开失败");
        exit(0);
    }
   // fprintf(fp,"%s",s);
    fgets(s,sizeof(char)*25,fp);
    fgets(str,sizeof(char)*25,fp);
    fclose(fp);
    printf("%s",s);
    printf("\n%s",str);
    system("time/t");
    system("type D:\\CBproject\\学生选课系统之输入信息\\time.txt");

return 0;
}

