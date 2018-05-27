#include<cstdio>
#include<iostream>
//#include<cmath>
#include<math.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
double eps=1e-13;
const double pi=3.14159265358979;
class arr
{
	public:
		int x,y,r;
}a[3];
int sqr(int x)
{
	return x*x;
}
double dis(arr a,arr b)
{
	return sqrt(1.0*sqr(a.x-b.x)+(sqr(a.y-b.y)));
}
double work()
{
	//if (a[1].r>a[2].r) swap(a[1],a[2]);
	if (a[1].r+dis(a[1],a[2])<=a[2].r)
	return pi*(sqr(a[2].r));
	if (a[1].r+a[2].r<=dis(a[1],a[2]))
	return pi*(sqr(a[1].r)+sqr(a[2].r));
	if (a[1].x>a[2].x) swap(a[1],a[2]);
	double d=dis(a[1],a[2])/2;
	double delta=acos(d/a[1].r);
	delta*=2;
	double s=delta/(2*pi)*sqr(a[1].r)*pi-sqr(a[1].r)*sin(delta)/2;
	return pi*(sqr(a[1].r)+sqr(a[2].r))-(2*s);
}			
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
    int T, kase = 0;
    scanf("%d",&T);
    while (T--)
    {
		for (int i=1;i<=2;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
		printf("Case #%d: %.3lf\n",++kase, work());
	}
}
	
