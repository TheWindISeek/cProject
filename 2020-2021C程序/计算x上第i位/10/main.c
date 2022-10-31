#include <math.h>
int y (int x,int i)
{
    int y;
    y = x/(int)(pow(10,i-1)+0.5)%10;
    return y;
}
