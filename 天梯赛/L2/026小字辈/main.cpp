#include <iostream>
#include <vector>
using namespace std;
const int N = 100001;
int age[N];
vector<int> v[N];
void dfs(int root,int _age)
{
    age[root] = _age;
    for(int i:v[root])
        dfs(i,_age+1);
}
int main()
{
    int n;
    int root = 0,data;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&data);
        if(data!=-1)
            v[data].push_back(i);
        else
            root = i;
    }
    age[root] = 1;
    dfs(root,1);
    int max = 0;
    int flag = 1;
    for(int i = 1; i <= n; i++)
        if(max < age[i])
            max = age[i];
    printf("%d\n",max);
    for(int i = 1; i <= n; i++)
        if(age[i] == max)
        {
            if(flag)
                flag = 0;
            else
                printf(" ");
            printf("%d",i);
        }

    return 0;
}
