#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define ERROR -1
//��������Ҫ֪���ҵ�next������ôд
//Ȼ������Ҫ֪���ƶ���C����ַ���������ƶ� ������֮�� �Ҿͽ�����������
//�����Ҫ������j�Ƕ���
//��ʼ��next���� �����ֱ�Ϊ �ַ��� next���� �ַ�������
void Next (string a,int next [],int length){
    int j = 0,k = -1;
    next[0] = -1;
    while(j < length)
        if(k == -1 || a[j] == a[k])
            next[++j] = ++k;
        else
            k = next[k];//���ڻ���
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
