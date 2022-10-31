#define inandout

#include <stdio.h>
#define one 900
int main()
{
    #ifdef inandout
    freopen("1.in","r",stdin);
    freopen("1.out","w+",stdout);
    #endif
    //*******************************************
    char a[4];
    int b;
    int a1,b1;
    int pai;
    scanf("%d%d",&a1,&b1);//先输入X/X
    pai=4*one/b1;//定义每拍几毫秒
    int T=0;
    printf("本曲谱以%d分音符为一拍每小节%d拍\n",b1,a1);
    while(scanf("%s",a),a[0]!='@')//输入音符x#高音，xb低音，\回车，@结束输入
    {
        if(a[0]=='\\')
        printf("\n");
        else
        {        T++;
            switch(a[0])
            {
                case '0':
                printf("0,");
                break;
                case '1':
                {
                    if(a[1]=='#')
                    printf("%d,",1046);
                    else if(a[1]=='b')
                    printf("%d,",262);
                    else
                    printf("%d,",523);
                    break;
                }
                case '2':
                {
                    if(a[1]=='#')
                    printf("%d,",1175);
                    else if(a[1]=='b')
                    printf("%d,",294);
                    else
                    printf("%d,",587);
                    break;
                }
                case '3':
                {
                    if(a[1]=='#')
                    printf("%d,",1318);
                    else if(a[1]=='b')
                    printf("%d,",330);
                    else
                    printf("%d,",659);
                    break;
                }
                case '4':
                {
                    if(a[1]=='#')
                    printf("%d,",1397);
                    else if(a[1]=='b')
                    printf("%d,",349);
                    else
                    printf("%d,",698);
                    break;
                }
                case '5':
                {
                    if(a[1]=='#')
                    printf("%d,",1568);
                    else if(a[1]=='b')
                    printf("%d,",392);
                    else
                    printf("%d,",784);
                    break;
                }
                case '6':
                {
                    if(a[1]=='#')
                    printf("%d,",1760);
                    else if(a[1]=='b')
                    printf("%d,",440);
                    else
                    printf("%d,",880);
                    break;
                }
                case '7':
                {
                    if(a[1]=='#')
                    printf("%d,",1976);
                    else if(a[1]=='b')
                    printf("%d,",494);
                    else
                    printf("%d,",988);
                    break;
                }
            }
        }

    }
    printf("\n共音符%d个\n\n",T);
    T=0;
    while(scanf("%d",&b)!=EOF)//按顺序输入每个音符拍数 下面每加一杠，数值乘2 如4分音符为1,8分为2,0为回车，若有连音只需按顺序输入音长 5 - -为111
    {
        if(b==0)
        printf("\n");
        else
        {
            T++;
            if(b>10)
            {
                int sum=0;
                while(b!=0)
                {
                    if(b%10!=0)
                    sum+=(pai/(b%10));
                    b/=10;
                }
                printf("%d,",sum);
            }
            else
            printf("%d,",pai/b);
        }
    }
    printf("\n共音长%d个\n\n",T);
    return 0;
}
