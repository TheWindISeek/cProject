#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
using s=vector<int>;

int sum;

typedef struct
{
	char name;
	s stack;
}stack;

void initStack(stack &a, stack &b, stack &c, int n)
{
	for (int i = n; i >= 1; -- i)
	{
		a.stack.push_back(i);
	}
	a.name = 'A';
	if (n & 1)//�����������ΪʲôҪ��������ż�� ���Ҫ�����Ľ������
        /*��������� ���һ���Ǵ�A���ƶ��������ƶ����Ǹ�������
        ż���Ļ�����ԭ��*/
	{
		b.name = 'C';
		c.name = 'B';
	}
	else
	{
		b.name = 'B';
		c.name = 'C';
	}


}

void move(stack &a, stack &b)		// ��a�е�ջ��Ԫ������b��
{
	sum ++;
	printf("%d : %c -> %c\n", a.stack.back(), a.name, b.name);
	b.stack.push_back(a.stack.back());
	a.stack.pop_back();
}

void moveOneToOne(stack &a, stack &b)	// �㷨�ĵڶ������Ƕ������������ջ��������һ��ջ��ջ��Ԫ���Ƶ���һ��ջ��
{
	// ����������ȫΪ�յ����ӵĵ��������ƶ������ǹ̶���
	if (a.stack.empty())	// a����յģ���Ȼֻ�ܰ�b��Ԫ���Ƶ�a��
	{
		move(b, a);
	}
	else if (b.stack.empty())	// b����յģ���Ȼֻ�ܰ�a��Ԫ���Ƶ�b��
	{
		move(a, b);
	}
	else if (a.stack.back() > b.stack.back()) // a��ջ��Ԫ���������b�ģ���Ȼֻ�ܰ�b��Ԫ���Ƶ�a��
	{
		move(b, a);
	}
	else	// b��ջ��Ԫ���������a�ģ���Ȼֻ�ܰ�a��Ԫ���Ƶ�b��
	{
		move(a, b);
	}
}

bool isEnd(stack &b, stack &c, int n)	// ����һ���������ˣ���ѭ������
{
	if ((int)b.stack.size() == n || (int)c.stack.size() == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void hanoi(int n, stack &A, stack &B, stack &C)
{
	for (int i = 0;!isEnd(B, C, n); ++ i)//��������Բ��ü������� �ܴ�����Ȼ�������� ���е������˾��Ѿ���ż������
	{
		if (i % 3 == 0)
		{
			move(A, B);
			if (isEnd(B, C, n))//�����м��
			{
				break;
			}
			moveOneToOne(A, C);//��һ�����õ�ʼ��Ϊ�м��Ǹ��ƶ�һ���Ĳ���
		}
		else if (i % 3 == 1)
		{
			move(B, C);
			if (isEnd(B, C, n))
			{
				break;
			}
			moveOneToOne(B, A);
		}
		else
		{
			move(C, A);
			if (isEnd(B, C, n))
			{
				break;
			}
			moveOneToOne(C, B);
		}
	}
	cout << "���ƶ���" << sum << "��" << endl;
}


int main()
{
	stack A, B, C;
	int n = 5;
	initStack(A, B, C, n);
	hanoi(n, A, B, C);
}
