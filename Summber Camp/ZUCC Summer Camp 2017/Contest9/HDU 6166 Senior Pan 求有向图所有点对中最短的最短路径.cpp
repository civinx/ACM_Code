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
#define MS(x, y) memset(x, y, sizeof(x))
#define INIT int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1
#define FILER freopen("1006.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;

namespace FastIO {
    char buf[1000000],*p1=buf,*p2=buf;
    inline char nc(){
        return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
    }
    inline bool rea(int & x){
        char c=nc();x=0;
        if(c==EOF) return false;
        for(;!isdigit(c);c=nc());
        for(;isdigit(c);x=x*10+c-'0',c=nc());
        return true;
    }
    inline bool rea(LL & x){
        char c=nc();x=0;
        if(c==EOF) return false;
        for(;!isdigit(c);c=nc());
        for(;isdigit(c);x=x*10+c-'0',c=nc());
        return true;
    }
}

const int maxn = 100000 + 100;
const LL INF = 10000000000000ll;
//const int maxn = 10;

struct Edge {
    int to, nx; LL cost;
};

struct P {
    int id; LL dist;
    bool operator < (const P & rhs) const {
        return dist > rhs.dist;
    }
};

struct Dij {
    Edge edges[maxn*5];
    int head[maxn];
    int sz;
    int n, m;
    LL d[maxn];
    bool isStart[maxn];
    bool isSet[maxn];
    
    void init() {
        sz = 0;
        MS(head, -1);
    }
    
    void AddEdge(int from, int to, LL cost) {
        edges[sz] = Edge{to, head[from], cost};
        head[from] = sz ++;
    }
    
    void PopEdge() {
        sz = m*2;
        head[0] = -1;
    }
    
    void build(int s[], int len) {
        MS(isStart, 0);
        for (int i = 0; i < len; i ++) {
            AddEdge(0, s[i], 0);
            isStart[s[i]] = 1;
        }
    }
    
    void setSet(int a[], int k) {
        MS(isSet, 0);
        for (int i = 0; i < k; i ++) {
            isSet[a[i]] = 1;
        }
    }
    
    LL run() {
        priority_queue<P> q;
        LL ret = INF;
        for (int i = 1; i <= n; i ++) d[i] = INF;
        d[0] = 0; q.push(P{0, 0});
        while (!q.empty()) {
            P cur = q.top(); q.pop();
            int from = cur.id; LL dist = cur.dist;
            if (d[from] != dist) continue;
            for (int e = head[from]; e != -1; e = edges[e].nx) {
                int to = edges[e].to; LL cost = edges[e].cost;
                if (cost + d[from] < d[to]) {
                    d[to] = cost + d[from];
                    if (!isStart[to] && isSet[to]) {
                        ret = min(ret, d[to]);
//                        printf("%lld\n",d[to]);
                    }
                    q.push(P{to, d[to]});
                }
            }
        }
        return ret;
    }
} solve;

int s1[maxn], s2[maxn];
int a[maxn];
int main() {
    // FILER;
    // FILEW;
    int T, kase = 0;
//    scanf("%d",&T);
    FastIO::rea(T);
    while (T--) {
        kase ++;
        solve.init();
//        scanf("%d%d",&solve.n,&solve.m);
        FastIO::rea(solve.n); FastIO::rea(solve.m);
        for (int i = 0; i < solve.m; i ++) {
            int u, v; LL cost;
//            scanf("%d%d%lld",&u,&v,&cost);
            FastIO::rea(u); FastIO::rea(v); FastIO::rea(cost);
            solve.AddEdge(u, v, cost);
        }
        int k;
//        scanf("%d",&k);
        FastIO::rea(k);
        for (int i = 0; i < k; i ++) {
//            scanf("%d",&a[i]);
            FastIO::rea(a[i]);
//            if (kase == 4) {
//                printf("%d%c",a[i],i==k-1?'\n':' ');
//            }
        }
        solve.setSet(a, k);
        LL res = INF;
        for (int i = 0; i < 20; i ++) {
            int len1 = 0, len2 = 0;
            for (int j = 0; j < k; j ++) {
                if (a[j] & (1 << i)) {
                    s1[len1++] = a[j];
                } else {
                    s2[len2++] = a[j];
                }
            }
            if (len1 == k || len2 == k) continue;
            solve.build(s1, len1);
            res = min(res, solve.run());
            solve.PopEdge();
        }
        printf("Case #%d: %lld\n",kase,res);
//        printf("Case#%d --------Down\n",kase);
    }
    return 0;
}