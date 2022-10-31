#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define ERROR -1
/*
题目分析
KMP 是十分困难的
需要注意的是 C和CPP里面的字符串是按\0作为结束标志 和Pascal语言是不同的
改变在于下标的读取 其他都没什么 如果理解了书上的代码 写这个并不困难
也许不困难吧
*/
void Next (string a,int next [],int length){
    int j = 0,k = -1;
    next[0] = -1;
    while(j < length)
        if(k == -1 || a[j] == a[k])
            next[++j] = ++k;
        else
            k = next[k];//存在回溯
}
int KMP (string a,string t,int a_length,int t_length,int next[]){
    int i = 0 , j = 0;
    if(a_length < t_length)
        return ERROR;
    while(i < a_length && j < t_length)
        if(j == -1 || a[i] == t[j]){
            ++i;
            ++j;
        }else
            j = next[j];
    if(j == t_length)
        return i-t_length;
    else
        return ERROR;
}
int main (){
    string a;
    string t;
    int num;
    cin >> a;
    int a_length = a.size();
    scanf("%d",&num);
    while(num--){
        cin >> t;
        int t_length = t.size();
        int next[t_length];
        Next(t,next,t_length);
        int sign = KMP(a,t,a_length,t_length,next);
        if(sign == ERROR){
            printf("Not Found\n");
        }else{
            for(int i = sign; i <a_length;++i)
                printf("%c",a[i]);
            printf("\n");
        }
    }
    return 0;
}
