#include <stdio.h>
#include <string.h>
#define LONG_C 80
int SearchString(char s[], char d[]);
int main()
{
	char s[LONG_C];
	char d[LONG_C];
	int ret;
	printf("Input a string:");
	gets(s);
	printf("Input another string:");
	gets(d);
	ret = SearchString(s, d);
	if(ret != -1)
	{
		printf("Searching results:%d\n", ret);
	}
	else
	{
		printf("Not found!\n");
	}
	return 0;
}
int SearchString(char s[], char d[])
{
	int lenth1, lenth2;
	int i=0, r=0, find;
	lenth1 = strlen(s);
	lenth2 = strlen(d);
	for(i=0;i<lenth1;i++)
	{
		if(s[i]==d[0])
		{
			find = 1;
			for(r=1;r<lenth2;r++)
			{
				if(s[i+r]!=d[r])
				{
					find = 0;
				}
			}
			if(find)
				return (i+1);
		}
	}
	return -1;
}
