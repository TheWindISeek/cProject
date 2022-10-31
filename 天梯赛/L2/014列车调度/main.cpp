#include <set>
#include <cstdio>
using namespace std;
/*
this problem need careful thinking.
first i just use the simply brute algorithm.
then i had two sample which can not to pass because the time is over flow.
and then i thought maybe this is because the code have logic bug.
after i tested many times, i turned off all kinds of this thought.
then i turned to the key of this problem.
the key is the order those train ran.
the only inspiring result of my previous algorithm is the problem result does n't related to the input stream.
result is merely about the bigger number before the current number should be replaced by the current.
then all those number like this is the id of a serial of set.
so the number of the set stored those number is the result.
*/
int main()
{
    set<int> s;
    int n,data;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&data);
        if(s.upper_bound(data)!=s.end())
            s.erase(s.upper_bound(data));
        s.insert(data);
    }
    printf("%d",(int)s.size());
    return 0;
}
