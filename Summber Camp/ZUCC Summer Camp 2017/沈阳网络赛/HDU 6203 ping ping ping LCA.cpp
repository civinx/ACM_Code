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
#define pb push_back
#define MS(x, y) memset(x, y, sizeof(x))
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;
typedef long long LL;
const int maxn = 10000 + 100;
const int maxm = 50000 + 100;

vector<int> G[maxn];
int L[maxn], R[maxn], dep[maxn], fa[maxn][20];

struct Query {
    int u, v, lca;
    bool operator < (const Query & rhs) const {
        return dep[lca] < dep[rhs.lca];
    }
}q[maxm];

void init(int n) {
    for (int i = 0; i <= n; i ++) G[i].clear();
}

int cnt = 0;

void dfs(int u, int f) {
    L[u] = ++cnt;
    fa[u][0] = f;
    for (int i = 1; i < 20; i ++) fa[u][i] = fa[fa[u][i-1]][i-1];
    for (int to : G[u]) {
        if (to == f) continue;
        dep[to] = dep[u] + 1;
        dfs(to, u);
    }
    R[u] = cnt;
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

struct SeqTree {
    int mi[maxn<<2], lazy[maxn<<2];
    
    void build() {
        MS(mi, 0);
        MS(lazy, 0);
    }
    
    void pushup(int rt) {
        mi[rt] = min(mi[ls], mi[rs]);
    }
    
    void pushdown(int rt, int len) {
        if (lazy[rt]) {
            mi[ls] += lazy[rt];
            lazy[ls] += lazy[rt];
            mi[rs] += lazy[rt];
            lazy[rs] += lazy[rt];
            lazy[rt] = 0;
        }
    }
    
    void update(int L, int R, int v, int l, int r, int rt) {
        if (L <= l && r <= R) {
//            sum[rt] += v;
            mi[rt] += v;
            lazy[rt] += v;
            return;
        }
        pushdown(rt, r - l + 1);
        int mid = (l + r) >> 1;
        if (L <= mid) update(L, R, v, lson);
        if (R > mid) update(L, R, v, rson);
        pushup(rt);
    }
    
    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            return mi[rt];
        }
        pushdown(rt, r-l+1);
        int mid = (l + r) >> 1;
        int ret = 0x3f3f3f3f;
        if (L <= mid) ret = query(L, R, lson);
        if (R > mid) ret = min(ret, query(L, R, rson));
        return ret;
    }
}Tree;

int n;

bool check(int x) {
    int s = Tree.query(L[x], R[x], 1, n, 1);
    if (s) return false;
    return true;
}

int main() {
    while (scanf("%d",&n) == 1) {
        n ++;
        init(n);
        Tree.build();
        for (int i = 1; i <= n-1; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            u ++; v ++;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dep[1] = 1;
        cnt = 0;
        dfs(1, 0);
        int m; scanf("%d",&m);
        for (int i = 0; i < m; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            u ++; v ++;
            int lca = LCA(u, v);
            q[i].u = u; q[i].v = v; q[i].lca = lca;
        }
        sort(q, q + m);
        int res = 0;
        for (int i = m-1; i >= 0; i --) {
            if (check(q[i].u) && check(q[i].v)) {
                res ++;
                int left = L[q[i].lca];
                int right = R[q[i].lca];
                Tree.update(left, right, 1, 1, n, 1);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
