#include <iostream>
#include<string>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    //�ҴӶ�������� ����һ�����Ե�û��
    //���Ǵ�һ������� ����ȫ����
    string a;
    string b;
    cin >> a >>b;
    stack<char> s;
    int want [100]= {0};
    int i,j,k;
int flag = 1;
    j = 0,k = 0;//2 ������е��α�
    int length  = a.size();
    for(i = 0; i<length; ++i)
    {
        if(a[i] == b[j])
        {
            want[k++]=3;
            j++;
        }
        else if (!(s.empty()) && s.top() == b[j])
        {
            s.pop();
            want[k++]=2;
            j++;
            i--;
        }
        else
        {
            s.push(a[i]);
            want[k++] = 1;

        }
    }

while(!(s.empty()) && j <length){
    if(s.top() == b[j]){
        s.pop();
        want[k++] = 2;
        j++;
    }else{
    flag = 0;
    break;
    }

}





    if(flag)
    {
        //���˳��
        for(int i = 0; i< k; i++)
        {
            if(want[i] == 1)
                printf("1->3");
            else if(want[i] == 2)
                printf("3->2");
            else if (want[i] == 3)
                printf("1->2");
            if(i<k-1)
                printf("\n");

        }
    }
    else
    {

        printf("Are you kidding me?");
    }
    return 0;
}
