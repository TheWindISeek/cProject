#include <stdio.h>

int main(void){
/*
    printf("%p\n", "hello");
    printf("%p\n", "hello" + 1);
    printf("%c\n", *("hello" + 1));
    printf("%c\n", "hello"[4]);*/

	char *str1 = "abcde";//字符串常量
	char str2[] = "abcde";//字符数组，有\0，所以也是字符串
	//str1[0] = 'x';//写错误
	str2[0] = 'x';
	printf("%s\n",str1);
	printf("%s\n",str2);

    return 0;
}
