#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool isMatch(string s,string p)
{
    int m = s.size(), n = p.size();
    bool dp[m+1][n+1];
    memset(dp,false,sizeof(dp));
    auto matches = [&](int i, int j)
    {
        if (i == 0)
            return false;
        if (p[j - 1] == '.')
            return true;
        return s[i - 1] == p[j - 1];
    };

    dp[0][0] = true;
    for(int i = 0; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(p[j-1] == '*')
            {
                dp[i][j] |= dp[i][j-2];
                if(matches(i,j-1))
                    dp[i][j] |= dp[i-1][j];
            }
            else
            {
                if(matches(i,j))
                    dp[i][j] = dp[i-1][j-1];
            }
    return dp[m][n];
}
int main()
{
    string s = "mississippi";
    string p = "mis*is*ip*.";
    /*
    "aaa"
    "a*a"



    1

    "aaa"
    "aaaa"
    0
    "ab"
    ".*c"
    */
    cout << isMatch(s,p);
    return 0;
}
