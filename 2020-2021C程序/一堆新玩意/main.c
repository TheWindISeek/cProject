#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#define ADD(a, b) \
((a) + (b))
/*
int main()
{
int ret = ADD(1, 2);
printf("%d\n", ret);

return 0;
}*/

/*
#define PRINT_CH(ch) printf(#ch" is %c\n", (ch));

int main()
{
PRINT_CH('a')
return 0;
}*/


/*
#define PRINT_D(intValue) printf(#intValue" is %lu\n", (intValue));
#define PRINT_CH(ch) printf(#ch" is %c\n", (ch));
#define PRINT_STR(str) printf(#str" is %s\n", (str));
int main (int argc, const char * argv[])
{
int n = 1071698617;
char *pn = (char *)&n;
int i;
FILE *fp = fopen("test.txt", "w");
if(!fp)
{
perror("fopen error");
return -1;
}
for(i = 0; i < sizeof(n); ++i)
{
fputc(*(pn + i), fp);
}
putw(10716898617,fp);
fclose(fp);

return 0;
}*/

/*
int main (int argc, const char * argv[])
{
char buf[32] = {0};
ssize_t ret;
int file = open("test", O_RDONLY);

if(file < 0)
{
perror("open file error");
return -1;
}
ret = read(file, buf, sizeof(buf));
if(ret > 0)
PRINT_STR(buf)

close(file);

return 0;
}*/
/*//fread函数的举例使用
#define PRINT_D(intValue) printf(#intValue" is %lu\n", (intValue));
#define PRINT_CH(ch) printf(#ch" is %c\n", (ch));
#define PRINT_STR(str) printf(#str" is %s\n", (str));

int main (int argc, const char * argv[])
{
char buf[3] = {0};
size_t ret = fread(buf, sizeof(buf) - 1, 1, stdin);
if(ret == 1)
{
PRINT_STR(buf)
}

return 0;
}*/
/*//fgets函数特性在缓冲区未满的时候将回车也读入，并将其表现在字符串中
#define PRINT_D(intValue) printf(#intValue" is %lu\n", (intValue));
#define PRINT_CH(ch) printf(#ch" is %c\n", (ch));
#define PRINT_STR(str) printf(#str" is %s\n", (str));

int main (int argc, const char * argv[])
{
char buf[3];
char *ret = fgets(buf, sizeof(buf), stdin);
if(ret)
{
PRINT_D(strlen(buf))
PRINT_STR(buf)
}

return 0;
}
/*
#define PRINT_CH(ch) printf(#ch" is %c\n", (ch));
#define PRINT_STR(str) printf(#str" is %s\n", (str));

int main (int argc, const char * argv[])
{
char ch = 'a';
char buf[4];
char *ret = gets(buf);
if(ret != NULL)
{
PRINT_STR(ret)
}
PRINT_CH(ch)

return 0;
}*/
/*
int main()
{

char a[8];

//setbuf(stdout,NULL);
a[0]=getchar();
a[1]=getchar();
a[2]=getchar();
a[3]=getchar();
a[4]=getchar();
a[5]=getchar();
a[6]=getchar();
printf("%s",a);
return 0;

}*/


/*int main()

{
char c;

//第一次调用getchar()函数

//程序执行时，您可以输入一串字符并按下回车键，按下回车键后该函数才返回

c=getchar();

//显示getchar()函数的返回值

printf("%c\n",c);

//暂停

system("PAUSE");

while((c=getchar())!='\n')

{
printf("%c",c);

}

//暂停

system("PAUSE");

return 0;

}*/
/*
int main ()
{
    char ch;
    int i;

    for(i=0;i<5;i++)
    {
        //ch =getche();
        ch=getch();
printf("%c",ch);
    }
    return 0;
}*/


/*
void main ()
{

   char *p=(char *)calloc(60,sizeof(char));
   if(p==NULL)
   {
       printf("error");
       exit(0);
   }
   printf("%s",p);
   free(p);
   p=NULL;
}*/
/*
//输入缓冲区实例演示
int main()
{
int i;
int ret;
while(1)
{
ret = scanf("%d", &i);
if(ret == 1)
printf("%d\n", i);
else
{
    rewind(stdin);//清空缓冲区
    //while((ch = getchar()) != EOF && ch != '\n')
    printf("input i error\n");
}

}
return 0;
}*/
/*
void main ()
{
    int i;
    scanf("%i",&i);//可以接受10进制，8进制，16进制格式对就行
    printf("%d",i);
}*/
/*
//先向这个文件输入了0xFF 其实应该是EOF（大部分情况下为-1）
int main (int argc, const char * argv[])
{
FILE *fp = fopen("test", "r");
if(fp)
{
char ch;

printf("open test ok\n");
while((ch = fgetc(fp)) != EOF)
{
printf("%d", ch);
}

printf("read test end\n");
fclose(fp);
}

return 0;
}*/








