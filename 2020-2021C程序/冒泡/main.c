#include<stdio.h>
int main()
{
    int n,i;
    int j,k;
    int arr[100];
    printf("��������ĳ���");//��ʾ��Ϣ
    scanf("%d",&n);
    for(i=0; i<n; i++) //Ϊ���鸳ֵ
    {
        scanf("%d",&arr[i]);
    }
    int temp, i, j;
    for (i = 0; i < n-1; i++)  //����9�αȽ�
    {
        for (j = 0; j < n - i - 1; j++)//��ÿ���н���10-i-1�αȽ�
        {
            if (a[j] > a[j + 1])      //���������򣬽�����<
            {
                temp = a[j + 1];      //�������ڵ�����Ԫ��
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("�������Ϊ:\n");  //��������Ľ��
    for(i=0; i<n; i++) //��ӡ����
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}

