#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define ERROR -1
//首先我需要知道我的next数组怎么写
//然后我需要知道移动在C风格字符串下如何移动 这样完之后 我就解决了这个问题
//最后需要看的是j是多少
//初始化next数组 参数分别为 字符串 next数组 字符串长度
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
    while(i < a_length && j < t_length){
        if(j == -1 || a[i] == t[j]){
            ++i;
            ++j;
        }else
            j = next[j];
    }
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
