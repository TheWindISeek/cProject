#include <stdio.h>
#include <stdlib.h>
/*
���������û�������������
���ԾͰ���򵥵�˫��ѭ����������
˳��洢��ǰ��Ϳ�����2
*/
/*
15
4 3 5 1 10 0 7 0 2 0 9 0 0 6 8
11 4
*/
void print(int t[]){
    int first,second;
    scanf("%d %d",&first,&second);
    first--;
    second--;
    if(t[first] == 0){
        printf("ERROR: T[%d] is NULL",first+1);
        return;
    }
    if(t[second] == 0){
        printf("ERROR: T[%d] is NULL",second+1);
        return;
    }
    ;
    int index = 0,i,j;
    //��ʼ�����ж�
    for(i = second; i >0 && !index;i=(i-1)/2){
        for(j = first; j >0 &&!index; j = (j-1)/2)
            if(i == j)
                index = i;
    }
    printf("%d %d",index+1,t[index]);
}
int main (){
    int n;
    scanf("%d",&n);
    int i;
    int t[n];
    for(i = 0; i < n;++i){
        scanf("%d",&t[i]);
    }
    print(t);
    return 0;
}
