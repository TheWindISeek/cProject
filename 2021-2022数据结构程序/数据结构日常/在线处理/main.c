#include<stdio.h>
#define MAXSIZE 100000
int end=-2,start=-2,flag=0,t=0;
int findmax(int a[],int k)
{
	int max=0,sum=0;
	for(int i=0;i<k;i++)
	{
		sum+=a[i];
		if(max<sum)
		{
			max=sum;
			end=i;
            start=flag;
		}
		else if(sum<0)
		{
			sum=0;
            flag=i+1;
		}

	}
	return max;
}
int main()
{
	int K,i,a[MAXSIZE],sum=0;
	scanf("%d",&K);
	for(i=0;i<K;i++)
	{
		scanf("%d",&a[i]);
        if(a[i]>=0)
        {
            t=1;
        }
	}
	sum=findmax(a,K);
	if(!t)
	{
		printf("0 %d %d",a[0],a[K-1]);
	}
	else
	{
		printf("%d %d %d",sum,a[start],a[end]);
	}
return 0;
}


