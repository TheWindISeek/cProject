#include <stdio.h>
#include <stdlib.h>

void merge(int* ,int* ,int ,int );//调用排序方法对两个有序表进行归并,把两个有序表合并到a指针的数组
void mergesort(int* ,int);
//注:从小到大排序1

int main()
{
    int a[] = {10,8,24,47,84,90,87,33,54,22,45,31,56,89,97,33,13,0,-1};
    //int a[] = {10,20};
printf("%d\n",sizeof(a)/sizeof(int));
    mergesort(a,(sizeof(a)/sizeof(int)));
printf("\n\n\n");
    for(int i = 0;i<(sizeof(a)/sizeof(int));++i)
    {
        printf("结果%d序号%d\n",a[i],i);
    }
    return 0;
}
void mergesort(int* array,int length)
{
    int* array_begins = calloc(length,sizeof (int));//需优化,额外预留了等同于整个数组长度的空间



//初始化有序表
    for(int i = 0;i<length;i++)
    {
        array_begins[i] = -1;
        printf("初始化有序表起点%d  %d\n",array_begins[i],i);
    }





   int t = 0;//总的有序表数量
    array_begins[t++] = 0;
    printf("有序表起点%d  %d\n",array_begins[t-1],t-1);



    for(int i = 1;i<length;++i)//i是遍历位置
    {
        if(array[i-1]>array[i]);//比较前一个和当前,如果小或相等则继续,如果大于则记上个为前一个有序表的终止位置,当前为下个有序表的起点
        {
            array_begins [t++] = i;//将得到的新有序表的偏移计入列表首数组中
            printf("有序表起点%d  %d\n",array_begins[t-1],t-1);
        }
    }



    printf("\n结束有序表统计\n");



    int total = t;
    while(total>1)//当有1个以上的有序表
    {
        printf("当前有序表总数%d\n",total);


        int selected_1 = 0,selected_2 = 0;
        int begin1,begin2;





        for(int j = 0;j<t;j++)
        {
            if( (!selected_1) && (array_begins[j] != -1) )//没有选中第一个选择第一个
            {
                printf("已选中有序表1\n");
                begin1 = j;
                selected_1 = 1;
            }
            else if( (!selected_2) && (array_begins[j] != -1) )
            {
                printf("已选中有序表2\n");
                begin2 = j;
                selected_2 = 1;
            }
            else if(selected_1&&selected_2&&(array_begins[j] != -1))//找到第三个数组的起点
            {
                printf("合并有序表%d,%d\n",array_begins[begin2]-array_begins[begin1],array_begins[j]-array_begins[begin2]);

                merge(array+array_begins[begin1],array+array_begins[begin2],array_begins[begin2]-array_begins[begin1],array_begins[j]-array_begins[begin2]);//排序,合并两个数组,并去除第二个数组的标记

                array_begins[begin2] = -1;//旧的第二个数组已经被合并,去掉标记

                total--;//总有序表数组的数量-1;

                selected_1 = 0;
                selected_2 = 0;//重置两个有序表起点选中状态为假
            }
            if(selected_1&&selected_2&&(j == t-1 ))
            {
                printf("合并有序表%d,%d\n",array_begins[begin2]-array_begins[begin1],length-array_begins[begin2]);

                merge(array+array_begins[begin1],array+array_begins[begin2],array_begins[begin2]-array_begins[begin1],length-array_begins[begin2]);//第二个数组长度为总长-标记2


                total--;
                selected_1 = 0;
                selected_2 = 0;//重置两个有序表起点选中状态为假
            }
            //如果没有可以选到两个有序表的机会,就不再尝试合并
        }
    }
    return;
}
void merge(int* a,int* b,int al,int bl)//注:从小到大排序,默认两个数组的空间相邻
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
    //将有序的数储存到临时数组
    for(int i = 0;i<al+bl;i++)
    {
        a[i] = temp[i];
    }
    free(temp);
    return;
}
