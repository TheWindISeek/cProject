#include <iostream>
#include <vector>

using namespace std;
typedef struct unknown {
    int exp;
    int cof;
}X;
//�ж��Ƿ�ɼ�����һ������ȥ��
void add(X& x1,X& x2,X&x){
    x.cof = x1.cof + x2.cof;
    x.exp = x1.exp;
    if(x.cof == 0)
        x.exp = 0;
}
void show(vector<X>&v){
    //�����Ϊ0 ���0 0
    if((int)v.size() == 0){
        printf("0 0");
        return;
    }
    //�˷�����Ĵ�ӡ
    for(int i = 0; i < (int)v.size() ;++i){
        if(i !=0)
        printf(" %d %d",v[i].cof,v[i].exp);
        else{
             printf("%d %d",v[i].cof,v[i].exp);
        }
    }
}
int main (){
    int m,n;//��ȡ�����ĳ���
    vector<X> v1,v2;//�洢���ݵ�����
    vector<X> mu,pu;//�������
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
    //����Ϊ�˷�����
    //���ڵ��뷨������ɢ�б�ģ�� ָ����Ϊ�±� ϵ����Ϊֵ
   //һ��ʼ�ľ�ѡ����������ݽṹ Ӧ�þ�ʹ��ɢ�б��
   //�����Ǳ����������飬���������һ�������� ������
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
    //����Ϊ�ӷ�����
    int i,j;
    i = j =0;
    while(i<m&&j<n){
    if(v1[i].exp == v2[j].exp)
    {//���Խ��мӷ�
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
    if(i == m){//��Ϊ��һ���������˳������ڶ���ȫ�����������
        while(j<n)
            pu.push_back(v2[j++]);
    }else if ( j == n){//ͬ��
        while(i<m)pu.push_back(v1[i++]);
    }

    show(mu);
    printf("\n");
    show(pu);
    return 0;
}
/*ͬ����ϲ�����
ϵ����ָ��ȡ���� ����������ʽ
�����������ʽ�ͳ�������ʽ*/
