#include <stdio.h>
void Hanoi(int n, char a, char b, char c);//�������ܣ��õݹ鷽����n��Բ�̽���������c��Դ����a�ƶ���Ŀ������b��
void Move(int n, char a, char b);// �������ܣ� ����n��Բ�̴�Դ����a�Ƶ�Ŀ������b��
int sum = 0;
int main()
{
    int n;
    printf("Input the number of disks:");
    scanf("%d", &n);
    printf("Steps of moving %d disks from A to B by means of C:\n", n);
    Hanoi(n, 'A', 'B','C'); //���õݹ麯��Hanoi()��n��Բ�̽�����C��A�ƶ���B
   //printf("%d",sum);
    return 0;
}
void Hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        Move(n, a, b); // ����n��Բ����a�Ƶ�b
    }
    else
    {
        Hanoi(n - 1, a, c, b); //�ݹ����Hanoi()������n-1��Բ�̽�����b��a�ƶ���c
        Move(n, a, b); //��n��Բ����a�Ƶ�b
        Hanoi(n - 1, c, b, a); //�ݹ����Hanoi()������n-1��Բ�̽�����a��c�ƶ���b
    }
}
void Move(int n, char a, char b)
{
    sum++;
    printf("Move %d: from %c to %c\n", n, a, b);
}
