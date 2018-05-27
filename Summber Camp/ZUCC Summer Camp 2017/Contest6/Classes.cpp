#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a[8];
    int i,j,n,m,t,z,sum,ans;
    scanf("%d",&t);
    for(z=1;z<=t;z++)
    {
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            sum=0;
            for(j=1;j<=7;j++)
            {
                scanf("%d",&a[j]);
            }
            sum=sum+a[7];
            for(j=1;j<=6;j++)
            {
                a[j]=a[j]-a[7];
                if(a[j]<0)
                break;
            }
            if(j<=6)
            {
                continue;
            }
            else 
            {
                sum=sum+a[4]+a[5]+a[6];
                a[1]=a[1]-a[4]-a[6];
                a[2]=a[2]-a[4]-a[5];
                a[3]=a[3]-a[5]-a[6];
                for(j=1;j<=3;j++)
                {
                    if(a[j]<0)
                    break;
                    else 
                    {
                        sum=sum+a[j];
                    } 
                }
                if(j<=3)
                {
                    continue;
                }
                else 
                {
                    ans=max(ans,sum); 
                }
            }
            
        }
        printf("%d\n",ans);
    }    
    return 0;
} 