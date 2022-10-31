#include<bits/stdc++.h>
using namespace std;
#define MAX 10001
struct DATA
{
    int id,fa,ma,num,area;
    int child[10];
} a[MAX];
struct node
{
    int id,people;
    double num,area;
    bool flag=false;
} b[MAX];

int father[MAX];
bool visit[MAX];
int cnt=0;

int find(int x)
{
    if(father[x] < 0)
        return x;
    return father[x] = find(father[x]);
}
void Union(int x,int y)
{
    int root1 = find(x);
    int root2 = find(y);
    if(root1 < root2)
    {
        father[root1] += father[root2];
        father[root2] = root1;
    }
    else if(root2 < root1)
    {
        father[root2]+=father[root1];
        father[root1] = root2;
    }
}
int cmp(node a,node b)
{
    if(a.area!=b.area)
        return a.area>b.area;
    return a.id<b.id;
}

int main()
{
    int n,id,fa,ma,k,child;
    cin>>n;
    for(int i=0; i< MAX; i++)
        father[i] = -1;
    for(int i=0; i<n; i++)
    {
        cin>>id>> fa >> ma >> k;;
        visit[id]=1;
        if(fa != -1)
        {
            Union(id,fa);
            visit[fa] = 1;
        }
        if(ma != -1)
        {
            Union(id,ma);
            visit[ma] = 1;
        }
        while(k--)
        {
            cin >> child;
            Union(id,child);
            visit[child] = 1;
        }
        cin>>a[id].num>>a[id].area;
    }
    for(int i=0; i<MAX; i++)
    {
        if(visit[i])
        {
        id=find(i);
        b[id].id=id;
        b[id].num += a[i].num;
        b[id].area += a[i].area;
        b[id].flag=1;
        b[id].people = -father[id];
        }
    }
    for(int i=0; i<MAX; i++)
        if(b[i].flag)
            cnt++;
    for(int i=0; i<MAX; i++)
    {
        if(b[i].flag)
        {
            b[i].num=1.0*b[i].num/b[i].people;
            b[i].area=1.0*b[i].area/b[i].people;
        }
    }
    sort(b,b+MAX,cmp);
    cout<<cnt<<endl;
    for(int i=0; i<cnt; i++)
        printf("%04d %d %.3f %.3f\n",b[i].id,b[i].people,b[i].num,b[i].area);
    return 0;
}
