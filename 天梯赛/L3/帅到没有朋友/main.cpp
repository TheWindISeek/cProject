#include <cstdio>
#include <set>
using namespace std;
int main ()
{
    int n,k,data,sum(0);
    set<int> s,st;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);
        for(int j = 0; j < k;j++)
        {
            scanf("%d",&data);
            if(k > 1)
                s.insert(data);
        }
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&data);
        if(!s.count(data)&&!st.count(data))//��s��û����st��Ҳû��
        {
            if(sum)
                printf(" %05d",data);
            else
                printf("%05d",data);
            sum++;
            st.insert(data);
        }
    }
    if(!sum)
        printf("No one is handsome");
    return 0;
}
