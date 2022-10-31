#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
��Ŀ����
����Ϊǰ׺���ʽ��ֵ ǰ׺���ʽ���׺���ʽ����һ��� ֻ��������ǰ׺���ʽ�����ǴӺ��濪ʼ����ɨ��
�������õ���ջ ��һ�����ݽṹ �����Լ�д Ҳ�����������ṩ��
�����Ĵ�������� ����Ϊ0 �һ������˷��������������� ����ջΪ��ʱ����Ҫ����Ԫ�� ���ǿ�����Ŀû�п������
��Ҫ���Ƿ������������������� �ᵼ��ջ�����ݶ���1 ��������ĿҲû�п������
ջ����ز���ʵ�ֲ������� ��׸��
Ҫ��Ϊ�˾������ ���Կ����Լ���һ������ȥ���� �������� �պϹ�����
���⻹��ɨ�����ֻ�������� ��Ҫ���ǵ������ ���ִ����� ���� ����С��������
��ȡ������Ҫһ������ȥ��¼λ Ҳ���� ���Ʒ���Ŀ��� Ȼ����Ҫһ��ȥ��¼ ���
�������� ��Ҫ �ý��ȡ�� ���� ֱ������������ С������Ҫ ����� ����Ϊ1/��¼λ������ *���
���ɨ���˳��� ������ѹջ������ Ȼ����ɨ�������е����ݺ� �Ϳ����������� �����ʱ����ջ��Ԫ��
*/
//����ջ
typedef struct stack {
    float num[31];
    int top;
}*Stack;
Stack init(){
    Stack s = (Stack)malloc(sizeof(struct stack));
    s -> top = -1;
    return s;
}
void push(Stack s,float x){
    s->num[++s->top] = x;
    return;
}
float pop(Stack s){
    return s->num[s ->top--];
}
int isEmpty(Stack s){
    return (s->top == -1) ? 1 : 0;
}
int main ()
{
    char input[31];
    Stack s = init();
    float first, second;
    gets(input);
    int length = strlen(input);
    //printf("%d",length);
    //�Ƚ����ȷ�Ե����� ��ȥ������������Ĵ��������
   for(int i = length -1 ; i >= 0; --i)
    {
       //printf("%c",input[i]);
        switch(input[i])
        {
        case '+':
                first = pop(s);
                second = pop(s);
                push(s,first+second);
            break;
        case '-':
                first = pop(s);
                second = pop(s);
                push(s,first-second);
            break;
        case '*':
                first = pop(s);
                second = pop(s);
                push(s,first*second);
            break;
        case '/':
                first = pop(s);
                second = pop(s);
                if(second == 0)//����Ϊ������
                {
                    printf("ERROR\n");
                    return 0;
                }
                push(s,first/second);
            break;
        case ' ':
            break;
        default:
                {//���������ȡ��Ӧ��Ϊ����
           int bit = 1;
           float result = 0;
           while(i>=0&&((input[i]>='0'&&input[i] <='9')||input[i] == '-' || input[i] == '+' || input[i] == '.'))
           {
            if(input[i] == '-')
                result = -result;
             else if (input[i]>='0'&&input[i] <='9')
             {
                 result = bit*(float)(input[i]-'0')+result;
                 bit *= 10;
             }else if (input[i] == '.')//������С����������û�п��� ��������֮��Ҫȥ�Լ���λ�Ľ�������
             {
                 result = result * 1.0/bit;
                 bit = 1;
             }
             --i;
           }
           push(s,result);
        }
        }
    }
    printf("%.1f\n",pop(s));//�������С�����һλ
    return 0;
}
