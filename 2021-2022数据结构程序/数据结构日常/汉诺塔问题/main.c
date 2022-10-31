#include <stdio.h>
void Hanoi(int n, char a, char b, char c);//函数功能：用递归方法将n个圆盘借助于柱子c从源柱子a移动到目标柱子b上
void Move(int n, char a, char b);// 函数功能： 将第n个圆盘从源柱子a移到目标柱子b上
int sum = 0;
int main()
{
    int n;
    printf("Input the number of disks:");
    scanf("%d", &n);
    printf("Steps of moving %d disks from A to B by means of C:\n", n);
    Hanoi(n, 'A', 'B','C'); //调用递归函数Hanoi()将n个圆盘借助于C由A移动到B
   //printf("%d",sum);
    return 0;
}
void Hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        Move(n, a, b); // 将第n个圆盘由a移到b
    }
    else
    {
        Hanoi(n - 1, a, c, b); //递归调用Hanoi()，将第n-1个圆盘借助于b由a移动到c
        Move(n, a, b); //第n个圆盘由a移到b
        Hanoi(n - 1, c, b, a); //递归调用Hanoi()，将第n-1个圆盘借助于a由c移动到b
    }
}
void Move(int n, char a, char b)
{
    sum++;
    printf("Move %d: from %c to %c\n", n, a, b);
}
