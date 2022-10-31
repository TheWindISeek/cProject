#include<stdio.h>
#include<math.h>
int main()
{
    int a1, a2, a3, a4, a5, a6, i, j;
    long m3, m4, m5, m6;
    long n3, n4, n5, n6;
    static int t[9];
    static long s[9][10];
    for (a1 = 1; a1 <= 9; a1++)
        for (a2 = 0; a2 <= 9; a2++)
            for (a3 = 0; a3 <= 9; a3++)
            {
                m3 = a1 * 100 + a2 * 10 + a3;
                n3 = (long)(pow(a1, 3) + pow(a2, 3) + pow(a3, 3));
                if (m3 == n3)
                {
                    s[3][++t[3]] = m3;          //三位水仙花数
                }
                for (a4 = 0; a4 <= 9; a4++)
                {
                    m4 = m3 * 10 + a4;
                    n4 = (long)(pow(a1, 4) + pow(a2, 4) + pow(a3, 4) + pow(a4, 4));
                    if (m4 == n4)
                    {
                        s[4][++t[4]] = m4;    //四位玫瑰花数
                    }
                    for (a5 = 0; a5 <= 9; a5++)
                    {
                        m5 = m4 * 10 + a5;
                        n5 = (long)(pow(a1, 5) + pow(a2, 5) + pow(a3, 5) + pow(a4, 5) + pow(a5, 5));
                        if (m5 == n5)
                        {
                            s[5][++t[5]] = m5; //五位五角星数
                        }
                        for (a6 = 0; a6 <= 9; a6++)
                        {
                            m6 = m5 * 10 + a6;
                            n6 = (long)(pow(a1, 6) + pow(a2, 6) + pow(a3, 6) + pow(a4, 6) + pow(a5, 6) + pow(a6, 6));
                            if (m6 == n6)
                            {
                                s[6][++t[6]] = m6; //六位六合数
                            }
                        }
                    }
                }
            }
    for (i = 3; i <= 6; i++)
    {
        printf("%d位自幂数有:", i);
        for (j = 1; j <= t[i]; j++)
        {
            printf("%ld\t", s[i][j]);
        }
        printf("\n");
    }

    return 0;

}
