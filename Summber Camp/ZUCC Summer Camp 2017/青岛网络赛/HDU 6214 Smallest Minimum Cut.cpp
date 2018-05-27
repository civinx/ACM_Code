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
using namespace std;
typedef long long LL;

struct Edge {
    int from, to;
    LL cap, flow;
};

const int maxn = 1000 + 100;
const LL inf = 1e16;

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    
    void init(int n) {
        for (int i = 0; i <= n; i ++) G[i].clear();
        edges.clear();
    }
    
    void AddEdge(int from, int to, LL cap) {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = (int)edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    
    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        d[s] = 0;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i = 0; i < G[x].size(); i ++) {
                Edge &e = edges[G[x][i]];
                int to = e.to;
                if (!vis[to] && e.cap > e.flow) {
                    vis[to] = 1;
                    d[to] = d[x] + 1;
                    q.push(to);
                }
            }
        }
        return vis[t];
    }
    
    LL DFS(int x, LL LastMax) {
        if (x == t || LastMax == 0) return LastMax;
        LL flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i ++) {
            Edge &e = edges[G[x][i]];
            int to = e.to;
            if (d[x] + 1 == d[to] && (f = DFS(to, min(LastMax, e.cap-e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                LastMax -= f;
                if (LastMax == 0) break;
            }
        }
        return flow;
    }
    
    LL Maxflow(int s, int t) {
        this->s = s; this->t = t;
        LL flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, inf);
        }
        return flow;
    }
    void rebuild() {
        for (int i = 0; i < edges.size(); i += 2) {
            Edge & e = edges[i];
            if (e.flow == e.cap) {
                e.flow = 0;
                e.cap = 1;
            } else {
                e.flow = 0;
                e.cap = inf;
            }
            edges[i^1].flow = 0;
            edges[i^1].cap = 0;
        }
    }
    
} solve ;

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, m; scanf("%d%d",&n,&m);
        int s, t; scanf("%d%d",&s,&t);
        solve.init(n);
        for (int i = 0; i < m; i ++) {
            int u, v; LL cost; scanf("%d%d%lld",&u,&v,&cost);
            solve.AddEdge(u, v, cost * (LL)(m+1) + 1);
        }
        //printf("%d\n",temp);
        //solve.rebuild();
        LL res = solve.Maxflow(s, t) % (m+1);
        printf("%lld\n",res);
    }
    return 0;
}