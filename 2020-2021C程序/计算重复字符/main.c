#include <stdio.h>
#include <string.h>
#define LONG_C 80
int CountRepeatStr(char str[], int *tag);
int main()
{
	char str[LONG_C+1];
	int tag=0, ret;
	printf("Input a string:\n");
	gets(str);
	ret = CountRepeatStr(str, &tag);
	printf("%c:%d\n", str[tag], ret);
	return 0;
}
int CountRepeatStr(char str[], int *tag)
{
	int lenth=strlen(str);
	int i, count=1, max=1;
	for(i=0;i<lenth;i++)
	{
		if(str[i] == str[i+1])
		{
			count++;
			if(count>max)
			{
				max = count;
				*tag = i+1;
			}
		}
		else
		{
			count=1;
		}
	}
	return max;
}
