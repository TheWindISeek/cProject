#include <bits/stdc++.h>

using namespace std;
void print_subset(int n,int k)
{
    for(int i = 0; i < (1<<n); i++) {
        int num = 0,kk = i;
        while(kk) {
            kk = kk & (kk-1);
            ++num;
        }
        if(num == k) {
            for(int j = 0; j < n; j++)
                if(i & (1 << j))
                    cout << j <<" ";
            cout << endl;
        }

    }
}
/*void print(int a[],int n)
{
    for(int i = 0; i < n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int a[1001];*/
/*int num;
int data[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
void perm(int begin,int end){
    int i;
    if(begin == end)
        num++;
    else{
        for(i = begin; i <= end;i++){
            swap(data[begin],data[i]);
            perm(begin+1,end);
            swap(data[i],data[begin]);
        }
    }
}*/
int main()
{
    /*// int a[10] = {0,1,5,6,9,3,8,2,4,7};
     //partial_sort(a,a+5);
     //stable_sort(a,a+10);
     //sort(a,a+10);*/
    /*int n,m;
    while(cin >>n>> m)
    {

        for(int i = 1; i <= n;i++)
        {
            a[i] = i;
        }
        int b = 1;
        do{
            if(b == m)
                break;
            ++b;
        }while(next_permutation(a+1,a+n+1));

        for(int i = 1; i < n;i++){
            cout <<a[i]<<" ";
        }
        cout << a[n]<<endl;
    }*/
    /*int data[4]={5,2,1,4};
    sort(data,data+4);
    do{
        for(int i = 0; i < 4;i++)
            cout << data[i] << " ";
        cout <<endl;
    }while(next_permutation(data,data+4));*/
    /*  clock_t start,end;

      start = clock();
      perm(0,11);
      end = clock();
      cout << (double)(end-start)/CLOCKS_PER_SEC <<endl;*/
   /* int n,k;
    cin >>n >> k;
    print_subset(n,k);*/
   cout <<sizeof(long long int)<<endl;
   cout << sizeof(long)<<' ' << sizeof(bool)<<' '<<endl;
   cout << sizeof(int)<<' '<<endl;
   cout << sizeof(long long)<<endl;
   bool visit[64];
   cout << sizeof(visit)<<endl;
    return 0;
}
