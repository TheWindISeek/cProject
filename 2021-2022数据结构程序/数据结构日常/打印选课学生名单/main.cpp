#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 40001;
const int K = 2501;
bool cmp(string &x,string &y)
{
    return x < y;
}
int main()
{
    vector<string> classes[K];
    int n,k,c,code,max = 0,flag = 1;
    int size[K]= {0};
    int i,j;
    string s;
    scanf("%d %d",&n,&k);
    for(i = 0; i < n; i++)
    {
        cin >> s;
        scanf("%d",&c);
        while(c--)
        {
            scanf("%d",&code);
            classes[code].push_back(s);
        }
    }
    for(i = 1; i <= k; i++)
    {
        size[i] = (int)classes[i].size();
        if(max < size[i])
            max = size[i];
    }
    string num[max];
    for(i = 1; i <= k; i++)
    {
        if(flag)
            flag = 0;
        else
            printf("\n");
        printf("%d %d",i,size[i]);
        for(j = 0; j < size[i]; j++)
            num[j] = classes[i][j];
        sort(num,num+size[i],cmp);
        for(j = 0; j < size[i]; j++)
        {
            printf("\n");
            cout << num[j];
        }

    }
    return 0;
}
