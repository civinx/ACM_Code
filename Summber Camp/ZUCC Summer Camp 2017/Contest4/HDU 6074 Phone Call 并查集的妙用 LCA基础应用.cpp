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
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;

const int maxn = 100000 + 100;
//const int maxn = 10;

struct P {
    int a, b, c, d; LL w;
    bool operator < (const P & rhs) const {
        return w < rhs.w;
    }
};

vector<int> G[maxn];
int fa[maxn][20], root[maxn], up[maxn], dep[maxn];
LL sz[maxn], cost[maxn];
int n, m;
P q[maxn];

void init() {
    for (int i = 1; i <= n; i ++) G[i].clear(), root[i] = i, up[i] = i, sz[i] = 1;
    MS(cost, 0);
    MS(fa, 0);
    MS(dep, 0);
}

void dfs(int x, int f) {
    fa[x][0] = f;
    for (int i = 1; i < 20; i ++) fa[x][i] = fa[fa[x][i-1]][i-1];
    for (int to : G[x]) {
        if (to == f) continue;
        dep[to] = dep[x] + 1;
        dfs(to, x);
    }
}

int findup(int x) {
    return up[x] == x ? x : up[x] = findup(up[x]);
}

int findroot(int x) {
    return root[x] == x ? x : root[x] = findroot(root[x]);
}

void unionSet(int x, int y, LL w) {
    x = findroot(x); y = findroot(y);
    if (x == y) return;
    root[x] = y;
    sz[y] += sz[x];
    cost[y] += cost[x] + w;
}

void unionLine(int u, int v, LL w) {
    while (1) {
        u = findup(u);
        if (dep[u] <= dep[v]) return;
        unionSet(u, v, w);
        up[u] = fa[u][0];
    }
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i --) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i --) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

void solve(int a, int b, int c, int d, LL w) {
    int l1 = LCA(a, b), l2 = LCA(c, d);
    unionLine(a, l1, w);
    unionLine(b, l1, w);
    unionLine(c, l2, w);
    unionLine(d, l2, w);
    unionSet(l1, l2, w);
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        init();
        for (int i = 1; i <= n-1; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dep[0] = 0; dep[1] = 1;
        dfs(1, 0);
        for (int i = 0; i < m; i ++) {
            scanf("%d%d%d%d%lld",&q[i].a,&q[i].b,&q[i].c,&q[i].d,&q[i].w);
        }
        sort(q, q+m);
        for (int i = 0; i < m; i ++) {
            solve(q[i].a,q[i].b,q[i].c,q[i].d,q[i].w);
        }
        printf("%lld %lld\n",sz[findroot(1)], cost[findroot(1)]);
    }
    return 0;
}
