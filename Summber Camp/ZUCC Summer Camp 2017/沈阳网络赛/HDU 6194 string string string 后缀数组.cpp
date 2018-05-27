#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define MS(x, y) memset(x, y, sizeof(x))
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;

const int maxn = 100000 + 100;

struct SuffixArray {
    int cmp(int *r,int a,int b,int l){
        return (r[a]==r[b]) && (r[a+l]==r[b+l]);
    }
    int wa[maxn],wb[maxn],wc[maxn],wv[maxn];
    int sa[maxn];
    int Rank[maxn],height[maxn];
    void DA(char *r, int n,int m){
        int i,j,p,*x=wa,*y=wb,*t;
        for(i=0;i<m;i++) wc[i]=0;
        for(i=0;i<n;i++) wc[x[i]=r[i]]++;
        for(i=1;i<m;i++) wc[i]+=wc[i-1];
        for(i=n-1;i>=0;i--) sa[--wc[x[i]]]=i;
        for(j=1,p=1;p<n;j*=2,m=p)
        {
            for(p=0,i=n-j;i<n;i++) y[p++]=i;
            for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0;i<n;i++) wv[i]=x[y[i]];
            for(i=0;i<m;i++) wc[i]=0;
            for(i=0;i<n;i++) wc[wv[i]]++;
            for(i=1;i<m;i++) wc[i]+=wc[i-1];
            for(i=n-1;i>=0;i--) sa[--wc[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        }
    }
    void calheight(char * r, int n) {
        int i,j,k=0;
        for(i=1;i<=n;i++) Rank[sa[i]]=i;
        for(i=0;i<n;height[Rank[i++]] = k)
            for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k]; k++);
    }

}SA;

struct SegTree {
    int mi[maxn << 2];
    int * data;
    
    void init(int * a) {
        data = a;
    }
    
    void pushup(int rt) {
        mi[rt] = min(mi[ls], mi[rs]);
    }
    
    void build(int l, int r, int rt) {
        if (l == r) {
            mi[rt] = data[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushup(rt);
    }
    
    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            return mi[rt];
        }
        int mid = (l + r) >> 1;
        int ret = 0x3f3f3f3f;
        if (L <= mid) ret = query(L, R, lson);
        if (R > mid) ret = min(ret, query(L, R, rson));
        return ret;
    }
}Tree;

char s[maxn];

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int k;
        scanf("%d",&k);
        scanf("%s",s);
        int n = (int)strlen(s);
        SA.DA(s, n+1, 'z'+1);
        SA.calheight(s, n);
        Tree.init(SA.height);
        Tree.build(1, n, 1);
        int res = 0;
        for (int i = 1; i+k-1 <= n; i ++) {
            int L = 0, R = 0;
            if (k > 1) {
                int Left = i + 1, Right = i+k-1;
                R = Tree.query(Left, Right, 1, n, 1);
            } else {
                R = n - SA.sa[i];
            }
            if (i > 1) {
                L = SA.height[i];
            }
            if (i + k <= n) {
                L = max(L, SA.height[i+k]);
            }
            res += max(0, R - L);
        }
        printf("%d\n",res);
    }
    return 0;
}
