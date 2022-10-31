#include <stdio.h>

int main (){
    int array[2000000]={0};
    int count = 0;
    int mark;
    int temp;
    scanf ("%d",&mark);
    while (1){
        scanf("%d",&temp);
       if(temp >=0)
        array[count++] = temp;
        else
            break;
    }
      if(count - mark <0)
          printf("NULL");
    else
        printf("%d\n",array[count - mark]);


    return 0;
}
