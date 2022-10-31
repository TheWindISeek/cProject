#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    int n;
    while(T--) {
        scanf("%d", &n);
        float x = (n-1)/2.0;
        printf("%.2f",pow(2,x));
    }
    return 0;
}
