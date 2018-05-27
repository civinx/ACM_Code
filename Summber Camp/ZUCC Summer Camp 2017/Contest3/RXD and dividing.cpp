#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <cmath>
#include <set>
using namespace std;
typedef long long LL;
const int maxn = 1000000 + 100;
//const int maxn = 10;

struct Edge {
    int from, to;
    LL cost;
};

LL sz[maxn];
LL n, k;

vector<int> G[maxn];
vector<Edge> edges;

void addEdge(int u, int v, LL cost) {
    edges.push_back(Edge{u, v, cost});
    edges.push_back(Edge{v, u, cost});
    int m = (int)edges.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
}

void init(LL n) {
    memset(sz, 0, sizeof(sz));
    for (int i = 1; i <= n; i ++) G[i].clear();
    edges.clear();
}

LL dfs(int x, int f) {
    sz[x] = 1;
    if (G[x].size() == 1 && x != 1) {
        return sz[x];
    }
    for (int i = 0; i < G[x].size(); i ++) {
        Edge & e = edges[G[x][i]];
        int to = e.to;
        if (to == f) continue;
        sz[x] += dfs(to, x);
    }
    return sz[x];
}

LL solve(int x, int f, LL cost) {
    LL ret = cost * min(k, sz[x]);
    if (G[x].size() == 1 && x != 1) {
        return ret;
    }
    for (int i = 0; i < G[x].size(); i ++) {
        Edge & e = edges[G[x][i]];
        int to = e.to;
        if (to == f) continue;
        ret += solve(to, x, e.cost);
    }
    return ret;
}

int main() {
    while (scanf("%lld%lld",&n,&k) == 2) {
        init(n);
        for (int i = 0; i < n-1; i ++) {
            int u, v; LL cost; scanf("%d%d%lld",&u,&v,&cost);
            addEdge(u, v, cost);
        }
        dfs(1, 0);
        LL res = solve(1, 0, 0);
        printf("%lld\n",res);
    }
    return 0;
}