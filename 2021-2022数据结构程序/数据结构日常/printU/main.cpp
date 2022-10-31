#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string s;
    cin >> s;
    int length = s.length();
    int n1,n2,n3,k,temp,index,i,j;
    n1 = n3 = k = 1;
    for(n2 = length-1; n2 >= 3; n2--)
    {
        for(temp = n2; temp >= 1; temp--)
            if(2*temp-2+n2 == length)
                break;
        if(temp > k)
        {
            k = temp;
            index = n2;
        }
    }
    n1 = n3 =k;
    n2 = index;
    for(i = 0; i < k; i++)
    {
        if(i)
            printf("\n");
        printf("%c",s[i]);
            if(i < k-1)
            {
                for(j = 0; j < n2-2; j++)
                    printf(" ");
            }
            else
            {

                for(j = 1; j <= n2-2; j++)
                    printf("%c",s[i+j]);
            }
        printf("%c",s[length-1-i]);
    }
    return 0;
}
