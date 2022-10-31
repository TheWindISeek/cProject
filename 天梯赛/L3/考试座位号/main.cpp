#include <map>
#include <iostream>
#include <utility>
using namespace std;
typedef pair<string,int> ps;

int main ()
{
    int n;
    string name;
    int first,second;
    map<int,ps> m;
    cin >> n;
    while(n--)
    {
        cin >> name >> first >> second;
         ps p(name,second);
        m[first] = p;
    }
    cin >> n;
    while(n--)
    {
        cin >> first;
        cout << m[first].first << " "<<m[first].second<<endl;
    }
    return 0;
}
