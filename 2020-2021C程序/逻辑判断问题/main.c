#include <stdio.h>

int main()
{
    short A, B, C, D, L1, L2, L3, L4;

    for (A = 0; A <= 1; A++)
        for (B = 0; B <= 1; B++)
            for (C = 0; C <= 1; C++)
                for (D = 0; D <= 1; D++)
                {
                    L1 = (B + C + D == 1); //"�ﷸ��B��C��D����֮�С�"
                    L2 = (!B && C);        //"��û����������C͵�ġ�"
                    L3 = (A + D == 1);     //"��A��D�м���һ�����ﷸ��"
                    L4 = L2;               //"B˵������ʵ"
                    if (L1 + L2 + L3 + L4 == 2
                            && A + B + C + D == 1)
                        //������ֻ������˵���滰�������ﷸֻ��һ��
                    {
                        printf("%d,%d,%d,%d\n", A, B, C, D);
                        if (A)
                            printf("A˵����ȷ.\n");
                        if (B)
                            printf("B˵����ȷ.\n");
                        if (C)
                            printf("C˵����ȷ.\n");
                        if (D)
                            printf("D˵����ȷ.\n");
                    }
                }

    return 0;
}
