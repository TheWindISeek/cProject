//���鼯��Ӧ��
#include <stdio.h>
#include <stdlib.h>
/*
�˵Ĺ�ϵ
��Ϊ���ѵ�����Ҳ������
�ȼ۹�ϵ ��ȡ���鼯 �Ҿ�����΢�������������ȡ���ݻ᲻������ظ�Ԫ�ص����
*/
/*
������������ ���ǲ�ȡ���ƶ�̬���µķ�ʽ����ǰ���������һ�����ĸ���һ����ʱ�������ָ����һ���Ľ��
*/
/*
����������������� ��ôȥȷ������ ��ôȥ�ж��ǲ�����ͬһ����*/
int tree[10010];
int visit[10010];
//���ݸ�����keyֵ
int find(int key){
    if(key != tree[key])
    return tree[key] = find(tree[key]);
    return key;
}
void Union(int x,int y){
    int root1 = find(x);
    int root2 = find(y);
    if(root1 != root2)
        tree[root1] = root2;
}
int main (){
    //��ȡ���ݽ������鼯 �����
    //�������������ж��ж��ٸ�Ȧ�� �������� ���ж��ٸ�С��0
    //���ݲ�ѯ �����Ӧ find
    int i,n,k,data,first,sum = 0,ans=0,N;
    //��ʼ��
    for(i = 0; i < 10010;++i){
        tree[i] = i;
        visit[i] = 0;
    }
    scanf("%d",&n);
    N=n;
    while(n--){
        scanf("%d %d",&k,&first);
        if(!visit[first])
        {
            visit[first] = 1;
            sum++;
        }
        for(i=1; i < k;++i){
            scanf("%d",&data);
            if(!visit[data])
            {
                visit[data] = 1;
                sum++;
            }
            Union(first,data);
        }
    }
    for(i = 1; i < 10010;++i){
        if(visit[i] && i == find(i))
            ans++;
    }
    printf("%d %d\n",sum,ans);
    scanf("%d",&k);
    while(k--){
        scanf("%d %d",&first,&data);
        if(find(first) == find(data))
            printf("Y\n");
        else
            printf("N\n");
    }
    for(int i =1; i <= sum;++i)
    {
        printf("%d:%d\t\n",i,tree[i]);
    }
    return 0;
}
