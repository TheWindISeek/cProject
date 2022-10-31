#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
const int N = 225;
/*
0��n-1���
4 4
51 100 1000
36 110 300
6 14 32
5 18 40
0 1 2 3
m��ǰ����ѯ�Ĺ���
���
�ȸ������� �ټ���ð��:  �����ǰ�ʲô������
1�����Ž��ư�
2�����Ž��ư�
3�������˾����ư�
4�������˾����ư�
*/
/*�������������ڵ��뷨�� �Ȱ����ַ�ʽ�������� ��4��1 Ȼ��ȥ������������ ͬʱע�����ĸ�����ʽ*/
typedef struct country
{
    int gold;//���Ƹ���
    int all;//���еĽ��Ƶĸ���
    int num;//�����˵�����
    int choose;//��ʲô����
    int rank;//���������µ�����
} Country;
Country c[N];
//�о�Ӧ����ʹ�ñ�����Ĵ���ʽ

//���ڵ�ǰ�Ĺ��� ���������������ʽ
inline bool
gold_cmp (int x,int y)
{
    return c[x].gold > c[y].gold;
}
inline bool
gold_equal (int x,int y)
{
    return c[x].gold == c[y].gold;
}
inline bool
ave_num_cmp(int x,int y)
{
    return c[x].all * c[y].num > c[y].all * c[x].num;
}
inline bool
ave_num_equal(int x,int y)
{
    return (c[x].all * c[y].num) == (c[y].all * c[x].num);
}
inline bool
ave_gold_cmp(int x,int y)
{
    return c[x].gold * c[y].num > c[y].gold * c[x].num;
}
inline bool
ave_gold_equal(int x,int y)
{
    return c[x].gold * c[y].num == c[y].gold * c[x].num;
}
inline bool
all_cmp (int x,int y)
{
    return c[x].all > c[y].all;
}
inline bool
all_equal (int x,int y)
{
    return c[x].all == c[y].all;
}
void sort_rank(int n,bool(*cmp)(int,int),bool(*equal)(int,int),int choose)
{
    int table[N],i,rank[N];
    for(i = 0; i < n; i++){
        table[i] = i;
        rank[i] = i;
    }
    sort(table,table+n,cmp);
    rank[0] = 1;
    for(i = 1 ; i < n; i ++)
    {
        if((*equal)(table[i],table[i-1]))
            rank[i] = rank[i-1];
    }
    cout << choose<<endl;
    for(i = 0; i < n; i++)
        cout << rank[i]<<" ";
    cout << endl;
    for(i = 0; i < n; i++)
    {
        if(c[table[i]].rank >= rank[i])//����������ȫ��������� ��������i+1����Ҫ����֮ǰ�ĺ͵�ǰ�ǲ���һ�µ� �����һ�µ� ����Ҫ��������޸�
        {
            c[table[i]].rank = rank[i];
            c[table[i]].choose = choose;
        }
    }
}
int main ()
{
    int n,m,which,i;
    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> c[i].gold >> c[i].all >> c[i].num;
        c[i].rank = N+1;
        c[i].choose = 0;
    }
    sort_rank(n,ave_num_cmp,ave_num_equal,4);
    sort_rank(n,ave_gold_cmp,ave_gold_equal,3);
    sort_rank(n,all_cmp,all_equal,2);
    sort_rank(n,gold_cmp,gold_equal,1);
    int flag = 1;
    while(m--)
    {
        if(flag)
            flag = 0;
        else
            printf(" ");
        cin >> which;
        printf("%d:%d",c[which].rank,c[which].choose);
    }
    return 0;
}
