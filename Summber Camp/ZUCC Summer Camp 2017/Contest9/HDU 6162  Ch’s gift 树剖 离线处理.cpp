#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
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
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 10;
//const int maxn = 15;

struct TreeCut {
    struct Seg {
        int l, r;
    };
    vector<int> G[maxn];
    Seg t[maxn<<4];
    int dep[maxn], size[maxn], fa[maxn], pos[maxn], bl[maxn], son[maxn];
    LL sum[maxn<<4];
    int sz;
    
    void init(int n) {
        for (int i = 1; i <= n; i ++) G[i].clear();
        sz = 0;
        MS(size, 0);
    }
    
    void AddEdge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    void dfs1(int x) {
        size[x] = 1;
        int mx_son = 0;
        for (int i = 0; i < G[x].size(); i ++) {
            int to = G[x][i];
            if (to == fa[x]) continue;
            dep[to] = dep[x] + 1;
            fa[to] = x;
            dfs1(to);
            size[x] += size[to];
            if (size[to] > size[mx_son]) {
                mx_son = to;
            }
        }
        son[x] = mx_son;
    }
    
    void dfs2(int x, int chain) {
        sz ++;
        pos[x] = sz;
        bl[x] = chain;
        if (!son[x]) return;
        dfs2(son[x], chain);
        for (int i = 0; i < G[x].size(); i ++) {
            int to = G[x][i];
            if (to == fa[x] || to == son[x]) continue;
            dfs2(to, to);
        }
    }
    
    void build(int l, int r, int rt) {
        t[rt].l = l; t[rt].r = r;;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
    }
    
    void pushup(int rt) {
//        t[rt].sum = t[ls].sum + t[rs].sum;
        sum[rt] = sum[ls] + sum[rs];
    }
    
    void change(int x, LL v, int rt) {
        //        int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1;
        INIT;
        if (l == r) {
//            t[rt].sum = v;
            sum[rt] = v;
            return;
        }
        if (x <= mid) {
            change(x, v, ls);
        } else {
            change(x, v, rs);
        }
        pushup(rt);
    }
    
    LL querysum(int L, int R, int rt) {
        //        int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1;
        INIT;
        if (L <= l && r <= R) {
//            return t[rt].sum;
            return sum[rt];
        }
        LL ret = 0;
        if (L <= mid) ret += querysum(L, R, ls);
        if (R > mid) ret += querysum(L, R, rs);
        return ret;
    }
    
    void solvechange(int x, LL v) {
        change(pos[x], v, 1);
    }
    
    LL solvesum(int x, int y) {
        LL ret = 0;
        while (bl[x] != bl[y]) {
            if (dep[bl[x]] < dep[bl[y]]) swap(x, y);
            ret += querysum(pos[bl[x]], pos[x], 1);
            x = fa[bl[x]];
        }
        if (pos[x] > pos[y]) swap(x, y);
        ret += querysum(pos[x], pos[y], 1);
        return ret;
    }
    
} solve;

struct Query {
    int id;
    int s, t;
    LL l, r;
} q[maxn];

struct Node {
    LL val;
    int id;
    bool operator < (const Node & rhs) const {
        return val < rhs.val;
    }
} a[maxn];

bool cmpl(const Query & lhs, const Query & rhs) {
    return lhs.l < rhs.l;
}

bool cmpr(const Query & lhs, const Query & rhs) {
    return lhs.r < rhs.r;
}

LL res[maxn];

int main() {
//    FILER;
    int n, m;
    while (scanf("%d%d",&n,&m) == 2) {
        solve.init(n);
        for (int i = 0; i < n; i ++) {
            scanf("%lld",&a[i].val);
            a[i].id = i+1;
        }
        sort(a, a+n);
        for (int i = 0; i < n-1; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            solve.AddEdge(u, v);
        }
        solve.dfs1(1);
        solve.dfs2(1, 1);
        solve.build(1, n, 1);
        for (int i = 0; i < m; i ++) {
            scanf("%d%d%lld%lld",&q[i].s,&q[i].t,&q[i].l,&q[i].r);
            q[i].id = i;
        }
        MS(res, 0);
        MS(solve.sum, 0);
        sort(q, q+m, cmpl);
        int j = 0;
        for (int i = 0; i < m; i ++) {
            while (j < n && a[j].val <= q[i].l-1) {
                solve.solvechange(a[j].id, a[j].val);
                j ++;
            }
            res[q[i].id] -= solve.solvesum(q[i].s, q[i].t);
        }
        MS(solve.sum, 0);
        sort(q, q+m, cmpr);
        j = 0;
        for (int i = 0; i < m; i ++) {
            while (j < n && a[j].val <= q[i].r) {
                solve.solvechange(a[j].id, a[j].val);
                j ++;
            }
            res[q[i].id] += solve.solvesum(q[i].s, q[i].t);
        }
        for (int i = 0; i < m; i ++) {
            printf("%lld%c",res[i],i==m-1?'\n':' ');
        }
    }
    return 0;
}
