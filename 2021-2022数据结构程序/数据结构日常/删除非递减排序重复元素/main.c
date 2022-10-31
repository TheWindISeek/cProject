#include <stdio.h>
#include <stdlib.h>

int delete_same(int a[],int length){
int i = 1,k = 1;
int x = a[0];
for(;i< length;++i)
    if(x < a[i]){
        a[k++] = a[i];
        x = a[i];
    }

return k;
}
int main()
{
   int num;
   scanf("%d",&num);
   int a[num],length;
   for(int i = 0; i< num;++i)
scanf("%d",&a[i]);
   length  = delete_same(a,num);
   for(int i = 0; i< length;++i)
    printf("%4d",a[i]);
    return 0;
}
