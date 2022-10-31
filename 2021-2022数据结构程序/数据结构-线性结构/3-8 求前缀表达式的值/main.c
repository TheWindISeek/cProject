#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
题目分析
该题为前缀表达式求值 前缀表达式与后缀表达式都是一体的 只不过对于前缀表达式我们是从后面开始进行扫描
整体利用的是栈 这一个数据结构 可以自己写 也可以用语言提供的
这道题的错误情况是 除数为0 我还考虑了符号数多于数字数 导致栈为空时还需要弹出元素 但是看来题目没有考查这个
还要就是符号数可能少于数字数 会导致栈中数据多于1 但看来题目也没有考查这个
栈的相关操作实现并不困难 不赘述
要是为了精简代码 可以考虑自己做一个函数去改正 但是我懒 凑合过得了
主题还是扫描数字会出现问题 需要考虑的情况有 数字带正号 负号 还有小数点的情况
读取数字需要一个数据去记录位 也就是 进制方面的考虑 然后需要一个去记录 结果
遇到负号 需要 让结果取反 正号 直接跳过就行了 小数点需要 将结果 更新为1/记录位的数据 *结果
最后扫描退出了 将数字压栈就行了 然后在扫描完所有的数据后 就可以输出结果了 结果此时就是栈顶元素
*/
//数字栈
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
    //先解决正确性的问题 再去解决错误的情况的处理的问题
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
                if(second == 0)//除数为零的情况
                {
                    printf("ERROR\n");
                    return 0;
                }
                push(s,first/second);
            break;
        case ' ':
            break;
        default:
                {//这种情况读取的应该为数字
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
             }else if (input[i] == '.')//就是有小数点的情况我没有考虑 考虑完了之后还要去对计算位的进行重置
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
    printf("%.1f\n",pop(s));//结果保留小数点后一位
    return 0;
}
