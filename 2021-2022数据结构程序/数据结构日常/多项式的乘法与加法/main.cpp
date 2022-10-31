#include <iostream>
#include <vector>

using namespace std;
typedef struct unknown {
    int exp;
    int cof;
}X;
//判断是否可加让上一级程序去做
void add(X& x1,X& x2,X&x){
    x.cof = x1.cof + x2.cof;
    x.exp = x1.exp;
    if(x.cof == 0)
        x.exp = 0;
}
void show(vector<X>&v){
    //若结果为0 输出0 0
    if((int)v.size() == 0){
        printf("0 0");
        return;
    }
    //乘法数组的打印
    for(int i = 0; i < (int)v.size() ;++i){
        if(i !=0)
        printf(" %d %d",v[i].cof,v[i].exp);
        else{
             printf("%d %d",v[i].cof,v[i].exp);
        }
    }
}
int main (){
    int m,n;//读取两个的长度
    vector<X> v1,v2;//存储数据的数组
    vector<X> mu,pu;//结果数组
    scanf("%d",&m);
    int exp,cof;
    for(int i = 0;i<m;++i){
        scanf("%d",&cof);
        scanf("%d",&exp);
        X x;
        x.cof = cof;
        x.exp = exp;
        v1.push_back(x);
    }
    scanf("%d",&n);
     for(int i = 0;i<n;++i){
        scanf("%d",&cof);
        scanf("%d",&exp);
        X x;
        x.cof = cof;
        x.exp = exp;
        v2.push_back(x);
    }
    //以下为乘法操作
    //现在的想法是利用散列表模拟 指数作为下标 系数作为值
   //一开始的就选择错误了数据结构 应该就使用散列表的
   //首先是遍历两个数组，将结果填入一个数组中 鉴于是
    int a[2001]={0};
    int mark[2001]={0};
    int index;
    for(int i = 0; i < m;++i){
        for(int j = 0; j< n;++j){
            index = v1[i].exp+v2[j].exp;
            a[index] += v1[i].cof*v2[j].cof;
            ++mark[index];
        }
    }
    for(int i = 2000; i >= 0;--i){
        if(mark[i]){
         X x;
         x.cof = a[i];
         x.exp = i;
         mu.push_back(x);
        }
    }
    //以下为加法操作
    int i,j;
    i = j =0;
    while(i<m&&j<n){
    if(v1[i].exp == v2[j].exp)
    {//可以进行加法
        X x;
        add(v1[i],v2[j],x);
        pu.push_back(x);
        ++i;
        ++j;
    }else if (v1[i].exp > v2[j].exp){
        pu.push_back(v1[i]);
        ++i;
    }else if (v1[i].exp < v2[j].exp){
        pu.push_back(v2[j]);
        ++j;
    }
}
    if(i == m){//因为第一个遍历完退出，将第二个全部输入就行了
        while(j<n)
            pu.push_back(v2[j++]);
    }else if ( j == n){//同上
        while(i<m)pu.push_back(v1[i++]);
    }

    show(mu);
    printf("\n");
    show(pu);
    return 0;
}
/*同类项合并抵消
系数与指数取上限 结果有零多项式
输入有零多项式和常数多项式*/
