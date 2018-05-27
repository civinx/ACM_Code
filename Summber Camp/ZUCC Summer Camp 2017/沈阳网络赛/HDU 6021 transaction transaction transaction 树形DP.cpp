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
const int INF = 0x3f3f3f3f;
//const int maxn = 100;

typedef long long LL;
struct Edge {
    int v;
    LL cost;
};
vector<Edge> edges;
vector<int> G[maxn];
int val[maxn];

void AddEdge(int u, int v, LL cost) {
    edges.push_back((Edge){v, cost});
    int m = (int)edges.size()-1;
    G[u].push_back(m);
}

LL MI[maxn], MX[maxn];

void init(int n) {
    for (int i = 1; i <= n; i ++) G[i].clear();
    edges.clear();
    MS(MI, INF);
    MS(MX, 0);
}

LL res = 0;
void dfs(int x, int pre) {
    if (G[x].size() == 1 && x != 1) {
        MI[x] = MX[x] = val[x];
        return;
    }
    
    for (int eid : G[x]) {
        Edge & e = edges[eid];
        int to = e.v;
        LL cost = e.cost;
        if (to == pre) continue;
        dfs(to, x);
        MI[x] = min(MI[x], min(MI[to] + cost, val[to] + cost));
        MX[x] = max(MX[x], max(MX[to] - cost, val[to] - cost));
    }
    res = max(res, val[x] - MI[x]);
    res = max(res, MX[x] - val[x]);
    res = max(res, MX[x] - MI[x]); // 即使形成MX[x] MI[x]的节点在一条链中，也只会形成较劣的解，不影响答案
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n); init(n);
        for (int i = 1; i <= n; i ++) scanf("%d",&val[i]);
        for (int i = 1; i <= n-1; i ++) {
            int u, v; LL cost; scanf("%d%d%lld",&u,&v,&cost);
            AddEdge(u, v, cost);
            AddEdge(v, u, cost);
        }
        res = 0;
        dfs(1, 0);
        printf("%lld\n",res);
    }
    return 0;
}
