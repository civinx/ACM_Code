#include <iostream>
#include <stack>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;
const LL INF = 1e10;

struct Edge {
    int from, to;
    LL cost;
    
    bool operator < (const Edge & rhs) const {
        return cost < rhs.cost;
    }
};

vector<Edge> edges;
vector<int> G[maxn];
int pre[maxn];
LL d[maxn][11];
bool done[maxn];
int n, m, k, s, t;

void AddEdge(int from, int to, LL cost) {
    edges.push_back((Edge){from, to, cost});
    edges.push_back((Edge){to, from, cost});
    int m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}

struct P {
    int id;
    LL d;
    
    bool operator < (const P & rhs) const {
        return d > rhs.d;
    }
};

LL solve() {
    
    for (int i = 1; i < n; i ++) {
        for (int j = 0; j <= k; j ++) {
            d[i][j] = INF;
        }
    }
    d[s][0] = 0;
    priority_queue<P> Q;
    memset(done, 0, sizeof(done));
    Q.push((P){s, 0});
    while (!Q.empty()) {
        P x = Q.top(); Q.pop();
        int u = x.id;
        if (done[u]) continue;
        done[u] = 1;
        for (int i = 0; i < G[u].size(); i ++) {
            Edge & e = edges[G[u][i]];
            for (int j = 0; j <= k; j ++) {
                // 当前用了j次机会
                if (d[e.to][j] > d[u][j] + e.cost) { //不用
                    d[e.to][j] = d[u][j] + e.cost;
                    Q.push((P){e.to, d[e.to][j]});
                }
                if (j < k) { //用一次
                    if (d[e.to][j+1] > d[u][j] + e.cost / 2) {
                        d[e.to][j+1] = d[u][j] + e.cost / 2;
                        Q.push((P){e.to, d[e.to][j]});
                    }
                }
            }
        }
    }
    LL mi = INF;
    for (int i = 0; i <= k; i ++) {
        mi = min(mi, d[t][i]);
    }
    return mi;
}


void init() {
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i < n; i ++) G[i].clear();
    edges.clear();
}

int main() {
    while (scanf("%d%d%d",&n,&m,&k) && (n || m || k)) {
        init();
        //        printf("%lld\n",INF);
        scanf("%d%d",&s,&t);
        for (int i = 0; i < m; i ++) {
            int u, v; LL cost;
            scanf("%d%d%lld",&u,&v,&cost);
            AddEdge(u, v, cost);
        }
        LL res = solve();
        printf("%lld\n",res);
    }
    return 0;
}
