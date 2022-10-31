#include <stdio.h>

int main()
{
    short A, B, C, D, L1, L2, L3, L4;

    for (A = 0; A <= 1; A++)
        for (B = 0; B <= 1; B++)
            for (C = 0; C <= 1; C++)
                for (D = 0; D <= 1; D++)
                {
                    L1 = (B + C + D == 1); //"罪犯在B、C、D三人之中。"
                    L2 = (!B && C);        //"我没有作案，是C偷的。"
                    L3 = (A + D == 1);     //"在A和D中间有一个是罪犯。"
                    L4 = L2;               //"B说的是事实"
                    if (L1 + L2 + L3 + L4 == 2
                            && A + B + C + D == 1)
                        //四人中只有两人说了真话，并且罪犯只有一个
                    {
                        printf("%d,%d,%d,%d\n", A, B, C, D);
                        if (A)
                            printf("A说得正确.\n");
                        if (B)
                            printf("B说得正确.\n");
                        if (C)
                            printf("C说得正确.\n");
                        if (D)
                            printf("D说得正确.\n");
                    }
                }

    return 0;
}
