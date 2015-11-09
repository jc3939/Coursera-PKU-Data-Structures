#include <stdio.h>
#include <string.h>
#include <math.h>
long long int a[21];
long long int chan[21];
int main()
{
    int i,j,n,m,t,x;
    long long int s;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    if(n==1)
    {
        printf("1\n");
    }
    else if(n==2)
    {
        printf("2\n");
    }
    else
    {
        a[3]=1;
        a[2]=1;
        for(i=4; i<=n; i++)
        {
            for(j=1; j<=20; j++)
            {
                chan[j]=a[j];
            }
            memset(a,0,sizeof(a));
            for(j=1;j<=20;j++)
            {
                if(chan[j]!=0)
                {
                    t=chan[j];
                    for(x=j+1;x>=2;x--)
                    {
                        a[x]+=t;
                    }
                }
            }
        }
        for(i=1,s=0; i<=20; i++)
        {
            s+=i*a[i];
        }
        printf("%lld\n",s);
    }
    return 0;
}
