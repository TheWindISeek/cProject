#include <iostream>
#include <stack>
using namespace std;

typedef int datatype;
void conversion(int N, int r){
    stack<datatype> s;
    while(N){
        s.push(N%r);
        N = N/r;
    }
    while(!s.empty()){
        printf("%2d",s.top());
        s.pop();
    }
}
int main()
{
    conversion(42,3);
    return 0;
}
