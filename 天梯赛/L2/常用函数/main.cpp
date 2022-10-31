#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    set<int> s;
    s.insert(3);
    auto it = s.upper_bound(3);
    s.insert(it,3);
    deque<int> dq;
    dq.push_back(2);
    dq.push_front(3);
    dq.pop_back();
    cout << dq[0]<<endl;
    dq.pop_front();
    cout << dq.size()<<endl;
    cout<<0x7fffff<<endl;
    cout<<0x7fffffff<<endl;
    cout<<0x7fffffff+1<<endl;
    long long x = 0x7fffffffffffffff;
    cout<<x<<endl;
    return 0;
}
