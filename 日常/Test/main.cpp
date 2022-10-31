#include <bits/stdc++.h>
using namespace std;
#define N 20
using namespace std;
int st[26];
string param[26];
bool vis[26];
int main()
{
    string s;
    cin >> s;
    int len = s.size();
    for(int i = 0; i <= len-1; ++i){
        if(i+1 < len && s[i+1] == ':'){
            st[s[i++]-'a'] = 2;
        }else{
            st[s[i]-'a'] = 1;
        }
    }
    char ch;
    int n,Case = 0;
    cin >> n;
    while(n--){
        cin >> s;
        ch = getchar();
        for(int i = 0; i <= 25; ++i){
            param[i].clear();
            vis[i] = 0;
        }
        if(ch == '\n') goto Nex;
        s.clear();
        while(ch = getchar(),ch != '\n' && ch != EOF){
            s.push_back(ch);
        }
        s.push_back(' ');
        len = s.size();
        for(int i = 0; i < len; ++i){
            int t = s[i+1] - 'a';
            if(i+2 >= len || s[i] != '-' ||s[i+2] != ' '||
               s[i+1] >'z' || s[i+1] < 'a' || !st[t]){
                goto Nex;
            }
            vis[t] = 1;
            if(st[t] == 1){
                i+=2;
            }else{
                i+=3;
                if(i < len) param[t].clear();
                while(i < len && s[i] != ' '){
                    if(s[i] != '-' && (s[i] > 'z'||s[i] < 'a')&&
                       !isdigit(s[i])){
                        param[t].clear();
                        goto Nex;
                       }
                       param[t].push_back(s[i++]);
                }
            }
        }
        Nex:;
        printf("Case %d: ",++Case);
        for(int i = 0; i <= 25; ++i){
            if(vis[i]){
                printf("-%c ",i+'a');
                if(st[i] == 2) cout << param[i] << ' ';
            }
        }
        cout <<endl;
    }
    return 0;
}
