#include <stdio.h>
#include <stdlib.h>
#define N 105
#define INF 1000
int g[N][N];
int main (){
    int n,e;
    int i,j,k;
    int first,second, weight;
    for(i = 0; i < N;++i){
        for(j =0; j < N;++j){
            if(i == j)
                g[i][j] = 0;
            else
            g[i][j] = INF;
        }
    }

    scanf("%d %d",&n,&e);
    for(i = 0; i < e;++i){
        scanf("%d %d %d",&first,&second,&weight);
        first--;
        second--;
        g[first][second] = g[second][first] = weight;
    }

    for(k =0; k < n;k++)
        for(i = 0; i < n;+i)
            for(j =0; j < n;++j)
                if(g[i][j] > g[i][k]+g[k][j])
                    g[i][j] =g[j][i] = g[i][k]+g[k][j];
    int max;
    int index,min = INF;
    for(i =0; i < n;++i){
        for(j = 0; j <n;++j)
            if(max < g[i][j])
                max = g[i][j];
        if(max == INF)
        {
            printf("0\n");
            return;
        }
        if(min > max){
            min = max;
            index = i;
        }
    }
    printf("%d %d\n",index+1,min);
    return 0;
}
