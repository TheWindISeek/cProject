#include <stdio.h>
//ȫ�Ǹ��� �����һ��Ԫ�غ����һ��Ԫ�� ����Ϊ 0
//����ж��������ͬ �����С���Ǹ�
int main ()
{
    int n;
    scanf("%d", &n);//��������Ҫ����now��Ӧ���Ǹ�begin �Ǹ���ֵ��������Щ����������
    int max = 0,now = 0,begin,end,temp = 0;
    int data[n],mark = 0;
    for(int i = 0; i < n ; ++i)
    {
        scanf("%d", &data[i]);
        if(data[i] >= 0)
            mark++;
    }
    if(mark)
    {
        for(int i = 0; i < n ; ++i)
        {
            now += data[i];
            if(now < 0)
            {
                now = 0;
                if( i+1 < n )
                    temp = i+1;
            }
            if(max < now)
            {
                begin = temp;
                max = now;
                end = i;
            }
        }
        if(max == 0)
            printf("0 0 0");
        else
            printf("%d %d %d",max,data[begin],data[end]);
    }
    else
        printf("%d %d %d",max,data[0],data[n-1]);
    return 0;
}
