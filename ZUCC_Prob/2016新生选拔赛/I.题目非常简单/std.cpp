#include<cstdio>
#define mod 100000007
int mul(long long  a,long long b)
{
    long long  r=1,base=a;
    while(b!=0)
    {
        if(b%2)
            r=(r%mod*base%mod)%mod;
        base=(base%mod*base%mod)%mod;
        b/=2;
    }
    return r;
}
long long fact(long long a, long long n)
{
	long long num1 = mul(a,n+1);
	long long num2 = (n*a-n-1) % mod;
	return (num1*num2 + a) %mod;
}
int main (void)
{
	int t, kase = 0;
	scanf("%d",&t);
	while(t--)
	{
		long long n,m;
		scanf("%lld%lld",&n,&m);
		long long sum=0;
		for(long long i=1;i<=n;i++)
		{
			sum += fact(i,m);
			sum %= mod;
		}
		printf("Case #%d: %lld\n",++kase, sum);
	}
    return 0;
} 
