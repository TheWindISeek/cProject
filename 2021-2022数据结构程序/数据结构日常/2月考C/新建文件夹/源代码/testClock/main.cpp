#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
clock_t start,end;
int main()
{
    start=clock();      //程序开始计时
    int ans=0;
    for(int i=1; i<=1e8; i++)
        ans++;
    end=clock();        //程序结束用时
    double endtime=(double)(end-start)/CLOCKS_PER_SEC;
    cout<<"Total time:"<<endtime<<"s"<<endl;       //s为单位
    cout<<"Total time:"<<endtime*1000<<"ms"<<endl;  //ms为单位
    system("pause");
    return 0;
}
