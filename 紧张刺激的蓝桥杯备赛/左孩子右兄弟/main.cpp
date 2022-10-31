#include <bits/stdc++.h>
using namespace std;
#define N 100003
vector<int> g[N];
int dfs(int r)
{
  int size = 0;
  for(int x:g[r])
      size = max(size,dfs(x));
  return g[r].size()+size;
}
int main()
{
  int n;
  scanf("%d",&n);
  int f;
  for(int i = 2;  i <= n;i++)
  {
    scanf("%d",&f);
    g[f].push_back(i);
  }
  cout << dfs(1);
  return 0;
}
