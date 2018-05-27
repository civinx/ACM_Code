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
using namespace std;

typedef long long LL;

const LL MOD = 998244353;
const int maxn = 300000 + 100;

struct Edge {
    int to; LL val;
};

bool vis[maxn << 1];
vector<Edge> G[maxn<<1];
int deg[maxn << 1];
vector<LL> v;
LL res = 0;

void init(int n) {
    for (int i = 1; i <= n; i ++) G[i].clear();
    v.clear();
    MS(vis, 0);
    MS(deg, 0);
    res = 0;
}

void AddEdge(int from, int to, LL val) {
    G[from].push_back(Edge{to, val});
}

LL mul(LL x, LL y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

LL add(LL x, LL y) {
    return ((x + MOD) + (y+MOD)) % MOD;
}

void dfs(int x, bool f, int st, int pre) {
    if (f && x == st) {
        LL g0 = v[0], g1 = v[1];
        for (int i = 2; i < v.size(); i ++) {
            if (i & 1) g1 = mul(g1, v[i]);
            else g0 = mul(g0, v[i]);
        }
//        res = add(res, add(g0, g1));
        res = mul(res, add(g0, g1));
        return;
    }
    vis[x] = 1;
    for (int i = 0; i < G[x].size(); i ++) {
        Edge & e = G[x][i];
        if (e.to == pre) continue;
        if (vis[e.to] && e.to != st) continue;
        v.push_back(e.val);
        dfs(e.to, 1, st, x);
        v.pop_back();
    }
}

int main() {
//    freopen("1007.in", "r", stdin);
//        freopen("data.out", "w", stdout);
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        init(n * 2);
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j < 2; j ++) {
                int to; LL val; scanf("%d%lld",&to,&val);
                to += n;
                AddEdge(i, to, val);
                AddEdge(to, i, val);
                deg[i] ++;
                deg[to] ++;
            }
        }
        
        queue<int> q;
        for (int i = n+1; i <= n * 2; i ++) {
            if (G[i].size() == 1) q.push(i);
        }
        LL base = 1;
        while (!q.empty()) {
            int cur = q.front(); q.pop(); vis[cur] = 1;
            for (int i = 0; i < G[cur].size(); i ++) {
                int to = G[cur][i].to;
                if (vis[to]) continue;
                if (--deg[to] == 1) q.push(to);
                if (cur > n) {
                    base = mul(base, G[cur][i].val);
                }
            }
        }
        res = base;
        for (int i = 1; i <= n; i ++) {
            if (vis[i]) continue;
            dfs(i, 0, i, 0);
        }
//        res = mul(res, base);
        printf("%lld\n",res);
    }
    return 0;
}
