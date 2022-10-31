#include <bits/stdc++.h>

using namespace std;
/*
albw:x
6
ls -a -l -a documents -b
ls
ls -w 10 -x -w 15
ls -a -b -c -d -e -l
ls -w -a -w 50
ls -a -w
*/
int main()
{
    string s;
    int n;
    map<char,int> m;
    cin >> s;
    for(int i = 0; i < (int)s.length(); ++i) {
        if(i+1 < (int)s.length() && s[i+1] == ':') {
            m[s[i]] = 2;
        } else {
            m[s[i]] = 1;
        }
    }
    cin >> n;
    int flag,count;
    char c;
    map<string,string> ans;
    string op(2,'a');
    string para;
    getchar();
    for(int i = 1; i <= n; ++i) {
        flag = 1;
        count = 0;
        ans.clear();
        while((c = getchar()) != '\n') {
            if(c == ' ') {
                ++count;
                c = getchar();
            }
            if(!count) {
                continue;
            }
            if(flag) {//前一个不带参数
                op[0] = c;
                c = getchar();
                op[1] = c;
                if(m[op[1]] == 2) { //当前需要参数
                    flag = 0;
                } else if(m[op[1]] == 1) {
                    flag = 1;
                    ans[op] = "!";
                } else {
                    while( (c = getchar()) != '\n') {}
                    break;
                }
            } else {//前一个带参数
                int f = 0;
                para = "";
                para.push_back(c);
                while((c=getchar()) != ' ' && c != '\n') {
                    para.push_back(c);
                    if(c != '-' && !(c >= '0'&& c <= '9')  && !(c>='a'&&c<='z')) {
                        while((c=getchar()) != '\n') {};
                        f = 1;
                        break;
                    }
                }
                if(f) {
                    break;
                }
                ans[op] = para;
                flag = 1;
                if(c == '\n'){
                    break;
                }
            }
        }
        printf("Case %d:",i);
        for(auto &s : ans) {
            if(s.second == "!") { //不带参数
                printf(" %s",s.first.c_str());
            } else {
                printf(" %s %s",s.first.c_str(),s.second.c_str());
            }
        }
        printf("\n");
    }
    return 0;
}
