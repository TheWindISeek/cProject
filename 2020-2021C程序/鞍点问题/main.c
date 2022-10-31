#include <stdio.h>
#include <stdlib.h>
#define M 100
#define N 100
void FindSaddlePoint(int a[][N], int m, int n);
int main(void)
{
    int m, n, a[M][N];
    printf("Input m,n:\n");
    scanf( "%d,%d", &m, &n);
    printf("Input matrix:\n");
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    FindSaddlePoint(a, m, n);
    return 0;
}
void FindSaddlePoint(int a[][N], int m, int n)
{
    int max, min, x, y, x1, y1;
    for(int i = 0; i < m; ++i)
    {
        max = a[i][0];
        x = i;
        y = 0;
        for(int j = 1; j < n; ++j)
        {
            if(a[i][j] > max)
            {
                max = a[i][j];
                x = i;
                y = j;
            }
        }
        min = a[0][y];
        x1 = 0;
        y1 = y;
        for(int r = 0; r < m; ++r)
        {
            if(a[r][y] < min)
            {
                min = a[r][y];
                x1 = r;
                y1 = y;
            }
        }
        if(x == x1 && y == y1)
        {
            printf("a[%d][%d] is %d\n", x, y, a[x][y]);
            return 0;
        }
    }
    printf("No saddle point!\n");
    return 0;
}
