
int LS (long num[],long x, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(num[i]==n) return i;
    }
    return -1;
}//需要设置标志变量
