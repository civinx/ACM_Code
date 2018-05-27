#include <iostream>
#include <stack>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef long long LL;

const int maxn = 75 * 75 * 2 + 100;
const int INF = 0x3f3f3f3f;

struct Edge {
    int from, to, cap, flow, cost;
};

struct MCMF {
    int n, m, s, t;
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];
    vector<Edge> edges;
    vector<int> G[maxn];
    
    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i ++) G[i].clear();
        edges.clear();
    }
    
    void AddEdge(int from, int to, int cap, int cost) {
        edges.push_back((Edge){from, to, cap, 0, cost});
        edges.push_back((Edge){to, from, 0, 0, -cost});
        int m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    
    bool BellmanFord(int s, int t, int &flow, int &cost) {
        for (int i = 0; i < n; i ++) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;
        
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i ++) {
                Edge & e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {Q.push(e.to); inq[e.to] = 1;}
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while (u != s) {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }
    
    void Mincost(int s, int t, int &flow, int &cost) {
        flow = 0, cost = 0;
        while (BellmanFord(s, t, flow, cost));
    }
};

int a[maxn], b[maxn];

int pic[100][100];

//vector<int> Ain, Aout, Bin, Bout;

int main() {
    int n, m, w;
    while (scanf("%d%d%d",&n,&m,&w) && (n || m || w)) {
        int k = n * m;
        memset(pic, 0, sizeof(pic));
        //        Ain.clear(); Aout.clear(); Bin.clear(); Bout.clear();
        MCMF solve;
        solve.init(n*m*2+10);
        // 费用
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                int g = (i-1) * m + j;
                int x; scanf("%d",&x);
                a[g] = x;
            }
        }
        
        // 容量
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                int g = (i-1) * m + j;
                int x; scanf("%d",&x);
                b[g] = x;
            }
        }
        
        for (int i = 0; i < w; i ++) {
            int x, y; scanf("%d%d",&x,&y);
            pic[x][y] = 1; // s
        }
        
        for (int i = 0; i < w; i ++) {
            int x, y; scanf("%d%d",&x,&y);
            pic[x][y] = 2; // t
        }
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                int g = (i - 1) * m + j;
                // 拆点建边
                for (int ii = 1; ii <= b[g]; ii ++) {
                    solve.AddEdge(g, g + k, 1, (ii * 2 - 1) * a[g]);
                }
                
                // 邻点建边
                int l = g - 1;
                int r = g + 1;
                int u = g - m;
                int d = g + m;
                if (j > 1) {
                    solve.AddEdge(g + k, l, INF, 0);
                }
                if (j < m) {
                    solve.AddEdge(g + k, r, INF, 0);
                }
                if (i > 1) {
                    solve.AddEdge(g + k, u, INF, 0);
                }
                if (i < n) {
                    solve.AddEdge(g + k, d, INF, 0);
                }
                
                // 超级源、汇
                if (pic[i][j] == 1) {
                    solve.AddEdge(0, g, 1, 0);
                }
                if (pic[i][j] == 2) {
                    solve.AddEdge(g + k, 2 * k + 1, 1, 0);
                }
            }
        }
        
        int flow, cost;
        solve.Mincost(0, 2 * k + 1, flow, cost);
        if (flow == w) {
            printf("%d\n",cost);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
