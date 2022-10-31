#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int w[n];
    for(int i = 0; i < n;i++)
    {
        scanf("%d",&w[i]);
    }
    set<int> s;
    for(int i = 0; i < n;i++)
    {
        for(int j = i+1; j < n;j++)
        {
            for(int k = j+1;k < n;k++)
            {
                s.insert(w[i]);
                if(w[j]!= w[i])
                s.insert(abs(w[j]-w[i]));
                s.insert(abs(w[i]+w[j]));
            }
        }
    }
    for(int x: s)
        cout <<x <<endl;
    printf("%d",s.size());
    return 0;
}
