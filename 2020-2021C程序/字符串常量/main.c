#include <stdio.h>

int main(void){
/*
    printf("%p\n", "hello");
    printf("%p\n", "hello" + 1);
    printf("%c\n", *("hello" + 1));
    printf("%c\n", "hello"[4]);*/

	char *str1 = "abcde";//�ַ�������
	char str2[] = "abcde";//�ַ����飬��\0������Ҳ���ַ���
	//str1[0] = 'x';//д����
	str2[0] = 'x';
	printf("%s\n",str1);
	printf("%s\n",str2);

    return 0;
}
