#include <iostream>
#include <stack>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const int maxn = 3000;
const LL INF = 1e17;

struct Edge {
    int from, to;
    LL cap, flow;;
};

struct Dinic {
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

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        int num = min(2520, n);
        int mxID = 10 + num;
        Dinic solve;
        for (int i = 1; i <= 10; i ++) {
            LL x; scanf("%lld",&x);
            solve.AddEdge(0, i, x);
        }
        for (int i = 1; i <= num; i ++) {
            for (int j = 1; j <= 10; j ++) {
                if (i % j == 0) {
                    solve.AddEdge(j, i+10, INF);
                }
            }
            solve.AddEdge(i+10, mxID+1, n/2520 + (i <= n%2520));
        }
        LL res = solve.Maxflow(0, mxID+1);
        printf("%lld\n",res);
    }
    return 0;
}
