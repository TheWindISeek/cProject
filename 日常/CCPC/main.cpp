#include <iostream>
using namespace std;

int main () {
    string s;
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin, s);
    //cin >> s;

    int n = s.length();
    int temp = 0;
    int maxn = 0;

    int st[26] = {0};  // 记录出现了哪些字符
    for(char c:s)
        st[c-'a'] = 1;

    for(int i = 0; i < 26; ++i) {
        char maxc = 'a'+i;  // 外层位置
        if(!st[maxc-'a'])   //没有这个字符
            continue;
        for(int j = i; j < 26; ++j) {   // 第二个字符
            //枚举最大字符和最小字符include
            char minc = 'a'+j;
            if(!st[minc-'a'])
                continue;
            temp = 0;
            int f = 0;
            int f1 = 0;
            for(int k = 0; k < n;++k) {
                if(s[k] == maxc) {
                    temp++;
                    t--;
                    f1 = 1;
                }
                if (s[k] == minc) {
                    temp--;
                    t++;
                    f = 1;
                }

                if(f && temp > maxn) {
                    maxn = temp;
                }
                if(f1 && t > minn) {
                    minn = t;
                }
                if(temp < 0) {
                    temp = 0;
                    f = 0;
                }
                if(t < 0) {
                    t = 0;
                    f1 = 0;
                }
            }
            temp = 0;
            f = 0;
            f1 = 0;
            for(int k = n-1; k >= 0;--k) {
                if(s[k] == maxc) {
                    temp++;
                    t--;
                    f1 = 1;
                }
                if (s[k] == minc) {
                    temp--;
                    t++;
                    f = 1;
                }

                if(f && temp > maxn) {
                    maxn = temp;
                }
                if(f1 && t > minn) {
                    minn = t;
                }
                if(temp < 0) {
                    temp = 0;
                    f = 0;
                }
                if(t < 0) {
                    t = 0;
                    f1 = 0;
                }
            }
            //cout << maxc << ' ' << minc << ' ' << maxn << endl;
        }
    }
    cout << maxn;
    return 0;
}



/*

#include <iostream>
using namespace std;

int main () {
    string s;
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin, s);
    //cin >> s;

    int n = s.length();
    int temp = 0;
    int maxn = 0;

    int st[26] = {0};  // 记录出现了哪些字符
    for(char c:s)
        st[c-'a'] = 1;

    for(int i = 0; i < 26; ++i) {
        char maxc = 'a'+i;  // 外层位置
        if(!st[maxc-'a'])   //没有这个字符
            continue;
        for(int j = 0; j < 26; ++j) {   // 第二个字符
            //枚举最大字符和最小字符include
            char minc = 'a'+j;
            if(!st[minc-'a'])
                continue;
            temp = 0;
            int f = 0;
            for(int k = 0; k < n;++k) {
                if(s[k] == maxc) {
                    temp++;
                }
                if (s[k] == minc) {
                    temp--;
                    f = 1;
                }

                if(f && temp > maxn) {
                    maxn = temp;
                }
                if(temp < 0) {
                    temp = 0;
                    f = 0;
                }
            }
            temp = 0;
            f = 0;
            for(int k = n-1; k >= 0;--k) {
                if(s[k] == maxc) {
                    temp++;
                }
                if (s[k] == minc) {
                    temp--;
                    f = 1;
                }

                if(f && temp > maxn) {
                    maxn = temp;
                }
                if(temp < 0) {
                    temp = 0;
                    f = 0;
                }
            }
            //cout << maxc << ' ' << minc << ' ' << maxn << endl;
        }
    }
    cout << maxn;
    return 0;
}

*/
