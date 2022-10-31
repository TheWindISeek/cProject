#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
/*的确是很有意思的一道题目*/
using namespace std;
struct cmp
{
    bool operator()(string a,string b)
    {
        return a+b > b+a;
    }
};
int main()
{
    int n,i;
    scanf("%d",&n);
    priority_queue<string,vector<string>,cmp> q;
    string temp;
    for(i = 0; i < n; i++)
    {
        cin >> temp;
        q.push(temp);
    }
    temp = "";
    while(!q.empty())
    {
        temp = temp+q.top();
        q.pop();
    }
    for(i = 0; i <temp.size()&&temp[i] == '0';i++);
    if(i == temp.size())
        printf("0");
    else
        printf("%s",temp.c_str()+i);
    return 0;
}
