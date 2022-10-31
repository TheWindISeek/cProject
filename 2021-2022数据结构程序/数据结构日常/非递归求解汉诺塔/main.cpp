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
	if (n & 1)//这里的问题是为什么要分奇数与偶数 这个要从最后的结果出发
        /*如果是奇数 则第一个是从A柱移动到借助移动的那根柱上面
        偶数的话就是原柱*/
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

void move(stack &a, stack &b)		// 将a中的栈顶元素移入b中
{
	sum ++;
	printf("%d : %c -> %c\n", a.stack.back(), a.name, b.name);
	b.stack.push_back(a.stack.back());
	a.stack.pop_back();
}

void moveOneToOne(stack &a, stack &b)	// 算法的第二步就是对于输入的两个栈，将其中一个栈的栈顶元素移到另一个栈中
{
	// 任意两个不全为空的柱子的单次盘子移动方法是固定的
	if (a.stack.empty())	// a如果空的，自然只能把b的元素移到a中
	{
		move(b, a);
	}
	else if (b.stack.empty())	// b如果空的，自然只能把a的元素移到b中
	{
		move(a, b);
	}
	else if (a.stack.back() > b.stack.back()) // a的栈顶元素如果大于b的，自然只能把b的元素移到a中
	{
		move(b, a);
	}
	else	// b的栈顶元素如果大于a的，自然只能把a的元素移到b中
	{
		move(a, b);
	}
}

bool isEnd(stack &b, stack &c, int n)	// 若有一根柱子满了，则循环结束
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
	for (int i = 0;!isEnd(B, C, n); ++ i)//这里面可以不用加条件的 总次数必然是奇数次 运行到这里了就已经是偶数次了
	{
		if (i % 3 == 0)
		{
			move(A, B);
			if (isEnd(B, C, n))//它到中间加
			{
				break;
			}
			moveOneToOne(A, C);//这一个作用的始终为中间那个移动一步的操作
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
	cout << "共移动了" << sum << "步" << endl;
}


int main()
{
	stack A, B, C;
	int n = 5;
	initStack(A, B, C, n);
	hanoi(n, A, B, C);
}
