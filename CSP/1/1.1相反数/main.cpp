#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[501];
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",a+i);
    }
    sort(a,a+n);
    int count = 0;
    int left = 0, right = n-1;
    while(left < right){
        if(a[left] + a[right] == 0){
            ++count;
            ++left;
        }else if(a[left] + a[right] > 0){
            --right;
        }else{
            ++left;
        }
    }
    printf("%d\n",count);
    return 0;
}
