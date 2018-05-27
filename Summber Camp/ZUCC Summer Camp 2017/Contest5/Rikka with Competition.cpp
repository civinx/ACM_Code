#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int a[100005];
int main()
{
    int i,j,n,m,t,z;
    scanf("%d",&t);
    for(z=1;z<=t;z++)
    {
        scanf("%d%d",&n,&m);
    
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    int sum=1;
    for(i=1;i<n;i++)
    {
        if(a[i]-a[i+1]<=m)
        {
            sum++;
        }
        else 
        break;
    }
    printf("%d\n",sum);
    }
    return 0;
}