#include <bits/stdc++.h>

using namespace std;
typedef struct node{
int x1,x2,y1,y2;
int id;
}node;
node a[12];
int main()
{
    int n,m;
    int x,y,x1,x2,y1,y2;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n;++i){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a[i].id = i;
        a[i].x1 = x1;
        a[i].x2 = x2;
        a[i].y1 = y1;
        a[i].y2 = y2;
    }
    while(m--){
        scanf("%d%d",&x,&y);
        int i;
        for(i = n; i > 0;--i){
            if(x >= a[i].x1 && x <= a[i].x2 && y >= a[i].y1 && y <= a[i].y2){
                break;
            }
        }
        if(i == 0){
            printf("IGNORED\n");
        }else{
            printf("%d\n",a[i].id);
            if(i != n){
                for(int j = i; j < n; ++j){
                    swap(a[j],a[j+1]);
                }
            }
        }
    }
    return 0;
}
