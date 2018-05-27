#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

typedef long long LL;

const int maxn = 1000 + 100;
const LL INF = 1e12;

struct Edge {
    int from, to;
    LL cost;
};

vector<int> G[maxn];
vector<Edge> edges;

void AddEdge(int u, int v, LL cost) {
    edges.push_back((Edge){u, v, cost});
    int m = (int)edges.size()-1;
    G[u].push_back(m);
}

LL d[maxn];
int n, m;

struct P {
    int id; LL dist;
    bool operator > (const P & rhs) const {
        return dist > rhs.dist;
    }
};

void dij(int s, int t) {
    for (int i = 1; i <= n; i ++) d[i] = INF;
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push((P){s, 0});
    while (!q.empty()) {
        P cur = q.top(); q.pop();
        if (cur.dist != d[cur.id]) continue;
        if (cur.id == t) continue;
        for (int i = 0; i < G[cur.id].size(); i ++) {
            Edge & e = edges[G[cur.id][i]];
            int from = e.from, to = e.to; LL cost = e.cost;
            if (d[to] > d[from] + e.cost) {
                d[to] = d[from] + cost;
                q.push((P){to, d[to]});
            }
        }
    }
}

void init() {
    for (int i = 1; i <= n; i ++) G[i].clear();
    edges.clear();
}

struct Dinic {
    struct Edge {
        int from, to;
        LL cap, flow;;
    };
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    
    void AddEdge(int from, int to, LL cap) {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    
    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); i ++) {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    
    LL DFS(int x, LL a) {
        if (x == t || a == 0) return a;
        LL flow = 0, f;
        for (int & i = cur[x]; i < G[x].size(); i ++) {
            Edge & e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    
    LL Maxflow(int s, int t) {
        this->s = s; this->t = t;
        LL flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
};

int path[maxn][maxn];

int main() {
    int s, t;
    while (scanf("%d%d%d%d",&n,&m,&s,&t) == 4) {
        init();
        for (int i = 0; i < m; i ++) {
            int u, v; LL cost;
            scanf("%d%d%lld",&u,&v,&cost);
            AddEdge(u, v, cost);
            AddEdge(v, u, cost);
            path[u][v] = path[v][u] = (int)cost;
        }
        dij(s, t);
        init();
        Dinic solve;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (i == j) continue;
                if (d[j] - d[i] == path[i][j]) {
                    solve.AddEdge(i, j, 1);
                }
            }
        }
        LL res = solve.Maxflow(s, t);
        printf("%lld\n",res);
    }
    return 0;
}