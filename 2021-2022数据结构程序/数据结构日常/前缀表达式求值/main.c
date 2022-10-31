#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
    char input[31];
    float num[31],first,second;//数字栈
    int n = 0;
    gets(input);
    //2+3*(7-4)+8/4
    //+ + 2 * 3 - 7 4 / 8 4
    for(int i = strlen(input)-1 ; i >= 0 ; --i)
    {
        switch(input[i])
        {
        case '+':
            first = num[--n];
            second = num[--n];
            num[n++] = second + first;
            break;
        case '-':
            first = num[--n];
            second = num[--n];
            num[n++] =  first- second;
            break;
        case '*':
            first = num[--n];
            second = num[--n];
            num[n++] = second * first;
            break;
        case '/':
            first = num[--n];
            second = num[--n];
            num[n++] =first / second ;
            break;
        case ' ':
            break;
        default:
        {
            //需要注意数字的读取
              int bit = 1,temp = 0;
              while(i >= 0 && input[i] >='0' && input[i] <='9'){
                  temp = temp*bit+(int)(input[i]-'0');
                  bit *= 10;
                  --i;
              }
              ++i;
             // printf("%c",input[i]);
              //printf("%f\n",(float)(input[i] - '0'));
            num[n++] = (float)(input[i] - '0');
        }
        }
    }
    printf("%.1f\n",num[0]);//结果保留小数点后一位
    return 0;
}
