#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
//Macro
#define rep(i,a,b)  for(int i=a,tt=b;i<=tt;++i)
#define drep(i,a,b) for(int i=a,tt=b;i>=tt;--i)
#define erep(i,e,x) for(int i=x;i;i=e[i].next)
#define irep(i,x)   for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define read()  (strtol(ipos,&ipos,10))
#define sqr(x)  ((x)*(x))
#define pb  push_back
#define mp  make_pair
#define PS  system("pause");
typedef long long   ll;
typedef pair<int,int> pii;
const int oo=~0U>>1;
const double inf=1e100;
const double eps=1e-6;
string name="", in=".in", out=".out";
//Var
struct CIR
{
    double x,y,r;
    void init(){scanf("%lf%lf%lf",&x,&y,&r);}
}o[1008],tmp[1008];
int n,st,ed;
double xl[1008],xr[1008],ans;
pair<double,double> seg[1008];
bool cmp1(const CIR &a,const CIR &b){return a.r>b.r;}
bool cmp2(const CIR &a,const CIR &b){return a.x-a.r<b.x-b.r||fabs(a.x-a.r-(b.x-b.r))<=eps&&a.x+a.r<b.x+b.r;}
bool In(int i,int j){return sqr(tmp[i].x-o[j].x)+sqr(tmp[i].y-o[j].y)<=sqr(tmp[i].r-o[j].r);}
void Init()
{
    // scanf("%d",&n);
    n=2;
    rep(i,1,n)o[i].init();//,s[i]=i;
    sort(o+1,o+1+n,cmp1);
    int k=0,j;
    rep(i,1,n)
    {
        for(j=1;j<=k;j++)
            if(In(j,i))break;
        if(j>k)
            tmp[++k]=o[i];
    }
    n=k;
    rep(i,1,n)o[i]=tmp[i];
}
double f(double x)
{
    int tot=0,j;
    double ret=0,dis,l,r;
    rep(i,st,ed)
    {
        if(x<=xl[i]||x>=xr[i])continue;
        dis=sqrt(o[i].r-sqr(x-o[i].x));
        seg[++tot]=mp(o[i].y-dis,o[i].y+dis);
    }
    sort(seg+1,seg+1+tot);
    rep(i,1,tot)
    {
        l=seg[i].first;r=seg[i].second;
        for(j=i+1;j<=tot;j++)
            if(seg[j].first>r)break;
            else r=max(seg[j].second,r);
        ret+=r-l;i=j-1;
    }
    return ret;
}
double Calc(double s,double fl,double fr,double fmid){return (fl+fr+4*fmid)*s/6;}
double Simpson(double l,double mid,double r,double fl,double fm,double fr,double tot)
{
    double m1=(l+mid)*0.5,m2=(mid+r)*0.5;
    double fm1=f(m1),fm2=f(m2);
    double g1=Calc(mid-l,fl,fm,fm1),g2=Calc(r-mid,fm,fr,fm2);
    if(fabs(tot-g1-g2)<=eps)return g1+g2;
    return Simpson(l,m1,mid,fl,fm1,fm,g1)+Simpson(mid,m2,r,fm,fm2,fr,g2);
}

int kase;
void Work()
{
    sort(o+1,o+1+n,cmp2);
    rep(i,1,n)xl[i]=o[i].x-o[i].r,xr[i]=o[i].x+o[i].r,o[i].r*=o[i].r;
    double l,r,mid,fl,fr,fm;
    int j;
    rep(i,1,n)
    {
        l=xl[i],r=xr[i];
        for(j=i+1;j<=n;j++)
            if(xl[j]>r)break;
            else r=max(xr[j],r);
        mid=(l+r)*0.5;
        st=i;ed=j-1;i=j-1;
        fl=f(l);fm=f(mid);fr=f(r);
        ans+=Simpson(l,mid,r,fl,fm,fr,Calc(r-l,fl,fr,fm));
    }
    printf("Case #%d: %.3lf\n",++kase, ans);
}
int main()
{
//    freopen("a.in","r",stdin);
//    freopen("a_.out","w",stdout);
    int T;
    kase = 0;
    scanf("%d",&T);
    {
        T--;
        Init();
        Work();
    }
    return 0;
}
