#include <stdio.h>
#include <stdlib.h>

void merge(int* ,int* ,int ,int );//�������򷽷��������������й鲢,�����������ϲ���aָ�������
void mergesort(int* ,int);
//ע:��С��������1

int main()
{
    int a[] = {10,8,24,47,84,90,87,33,54,22,45,31,56,89,97,33,13,0,-1};
    //int a[] = {10,20};
printf("%d\n",sizeof(a)/sizeof(int));
    mergesort(a,(sizeof(a)/sizeof(int)));
printf("\n\n\n");
    for(int i = 0;i<(sizeof(a)/sizeof(int));++i)
    {
        printf("���%d���%d\n",a[i],i);
    }
    return 0;
}
void mergesort(int* array,int length)
{
    int* array_begins = calloc(length,sizeof (int));//���Ż�,����Ԥ���˵�ͬ���������鳤�ȵĿռ�



//��ʼ�������
    for(int i = 0;i<length;i++)
    {
        array_begins[i] = -1;
        printf("��ʼ����������%d  %d\n",array_begins[i],i);
    }





   int t = 0;//�ܵ����������
    array_begins[t++] = 0;
    printf("��������%d  %d\n",array_begins[t-1],t-1);



    for(int i = 1;i<length;++i)//i�Ǳ���λ��
    {
        if(array[i-1]>array[i]);//�Ƚ�ǰһ���͵�ǰ,���С����������,�����������ϸ�Ϊǰһ����������ֹλ��,��ǰΪ�¸����������
        {
            array_begins [t++] = i;//���õ�����������ƫ�Ƽ����б���������
            printf("��������%d  %d\n",array_begins[t-1],t-1);
        }
    }



    printf("\n���������ͳ��\n");



    int total = t;
    while(total>1)//����1�����ϵ������
    {
        printf("��ǰ���������%d\n",total);


        int selected_1 = 0,selected_2 = 0;
        int begin1,begin2;





        for(int j = 0;j<t;j++)
        {
            if( (!selected_1) && (array_begins[j] != -1) )//û��ѡ�е�һ��ѡ���һ��
            {
                printf("��ѡ�������1\n");
                begin1 = j;
                selected_1 = 1;
            }
            else if( (!selected_2) && (array_begins[j] != -1) )
            {
                printf("��ѡ�������2\n");
                begin2 = j;
                selected_2 = 1;
            }
            else if(selected_1&&selected_2&&(array_begins[j] != -1))//�ҵ���������������
            {
                printf("�ϲ������%d,%d\n",array_begins[begin2]-array_begins[begin1],array_begins[j]-array_begins[begin2]);

                merge(array+array_begins[begin1],array+array_begins[begin2],array_begins[begin2]-array_begins[begin1],array_begins[j]-array_begins[begin2]);//����,�ϲ���������,��ȥ���ڶ�������ı��

                array_begins[begin2] = -1;//�ɵĵڶ��������Ѿ����ϲ�,ȥ�����

                total--;//����������������-1;

                selected_1 = 0;
                selected_2 = 0;//����������������ѡ��״̬Ϊ��
            }
            if(selected_1&&selected_2&&(j == t-1 ))
            {
                printf("�ϲ������%d,%d\n",array_begins[begin2]-array_begins[begin1],length-array_begins[begin2]);

                merge(array+array_begins[begin1],array+array_begins[begin2],array_begins[begin2]-array_begins[begin1],length-array_begins[begin2]);//�ڶ������鳤��Ϊ�ܳ�-���2


                total--;
                selected_1 = 0;
                selected_2 = 0;//����������������ѡ��״̬Ϊ��
            }
            //���û�п���ѡ�����������Ļ���,�Ͳ��ٳ��Ժϲ�
        }
    }
    return;
}
void merge(int* a,int* b,int al,int bl)//ע:��С��������,Ĭ����������Ŀռ�����
{
    int * temp = calloc(al+bl,sizeof (int));
    int ac = 0,bc = 0,total = 0;
    while(ac < al|| bc < bl)
    {
        if(ac < al && bc < bl)
        {
            if(a[ac]<=b[bc])
            {
                temp[total++] = a[ac++];
            }
            else if(a[ac]>b[bc])
            {
                temp[total++] = b[bc++];
            }
        }
        else if( ac < al && bc >= bl)
        {
            temp[total++] = a[ac++];
        }
        else if(ac >= al&& bc < bl)
        {
            temp[total++] = b[bc++];
        }
    }
    //������������浽��ʱ����
    for(int i = 0;i<al+bl;i++)
    {
        a[i] = temp[i];
    }
    free(temp);
    return;
}
