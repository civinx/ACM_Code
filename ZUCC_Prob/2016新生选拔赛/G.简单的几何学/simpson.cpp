#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
double eps=1e-13;
const int N=2100;
int n,m;
class arr
{
    public:
        double x,y,r;
}a[N],c[N*2];
double sqr(double x){return x*x;}
bool com(const arr &o,const arr &p)
{
    if (o.x==p.x) return o.r>p.r;
    return o.x<p.x;
}
double calc(double now)
{
    int s=0;
    for (int i=1;i<=n;i++)
    if ((a[i].x-a[i].r<now)&&(a[i].x+a[i].r>now))
    {
        double l=a[i].y-sqrt(sqr(a[i].r)-sqr(now-a[i].x));
        double r=a[i].y+sqrt(sqr(a[i].r)-sqr(now-a[i].x));
        c[++s].x=l,c[s].r=1;
        c[++s].x=r;c[s].r=-1;
    }
    sort(&c[1],&c[s+1],com);
    double l=0;
    int v=0;
    double an=0;
    for (int i=1;i<=s;i++)
    {
        v+=int(c[i].r);
        if ((v==1)&&(int(c[i].r)==1)) l=c[i].x;
        if (v==0) 
        an+=c[i].x-l,l=c[i].x;
    }
    return an;
}
double simpson(double l,double r,double SL,double Smid,double SR)
{
    
    double mid=(l+r)*0.5;
    double L=calc((l+mid)*0.5);double R=calc((mid+r)*0.5);
    double vl=(mid-l)*(SL+4*L+Smid)/6;
    double vr=(r-mid)*(Smid+4*R+SR)/6;
    double v=(r-l)*(SL+SR+4*Smid)/6;
    if (fabs(v-vl-vr)<eps)
    return max(v,vl+vr);
    return simpson(l,mid,SL,L,Smid)+simpson(mid,r,Smid,R,SR);
}
double dis(arr a,arr b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
int main()
{
    //scanf("%d",&n);
//    	freopen("a.in","r",stdin);
//	freopen("a_.out","w",stdout);
    int T, kase = 0;
    scanf("%d",&T);
    while (T--)
    { 
    n=2;
    for (int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[i].x=x;a[i].y=y;a[i].r=z;
    }
   // scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].r);
    bool use[N];
    for (int i=1;i<=n;i++)
    {
        use[i]=true;
        for (int j=1;j<=n;j++)
        if (i!=j)
        if (dis(a[i],a[j])+a[i].r<=a[j].r) {use[i]=false;break;}
    }
    int s=0;
    for (int i=1;i<=n;i++)
    if (use[i]) a[++s]=a[i];
    n=s;
    double ll=a[1].x-a[1].r;double rr=a[1].x+a[1].r;
    for (int i=1;i<=n;i++)
    ll=min(ll,a[i].x-a[i].r),rr=max(rr,a[i].x+a[i].r);
    printf("Case #%d: %.3lf\n",++kase,simpson(ll,rr,0,calc((ll+rr)/2),0));
    }
}
/*
3
0 0 1
1 0 1
-1 0 1
*/
