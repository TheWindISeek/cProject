#include <stdio.h>
#include <stdlib.h>

int main()
{
    //����һ��˫��������������⣬����Ĺؼ����ڿ�������ĽǶ�
    //����Ҵ�A���� ��ô����ܼ� �����ж���΢�е������
    //��B���������㲻��A�������Ҫ�� ��������������
    /*�ҵľ��� ��A���� ���ñ���֮��Ĺ�ϵȥ���������� �ؼ�����˫�ر���
    ���Ӧ���������߼�����ֿ�
    ���Ǻ���Ҫ��һ�㣬Ӧ����ʶ�����
    */
    int maxsize;
    scanf("%d",&maxsize);

    int number[maxsize];
        for(int i = 0;i < maxsize;i++)
        scanf("%d",&number[i]);
        for(int i = 0;i< maxsize;i++){
            printf("%d\n",number[i]);
        }
    int a[maxsize];
    int b[maxsize];
    int m,n;
int print[maxsize];
    m = 0,n = 0;
    for(int i = 0;i < maxsize;i++){
        if(number[i]%2!=0)
             a[m++]=number[i];
             else
                b[n++]=number[i];

    }
    int i,j,k;

    i = 0,j =0,k=0;
    for(;i<m&& j< n;i++){
        print[k++]=a[i];
        if(i %2 !=0)
        print[k++]=b[j++];
    }
if(i == m){
    for(;j<n;)
        print[k++]=b[j++];

}else{
while ( i < m)
    print[k++]=a[i++];

}
for(int i = 0; i< maxsize-1;i++){
    printf("%d ",print[i]);
}
printf("%d",print[maxsize-1]);
    return 0;
}
