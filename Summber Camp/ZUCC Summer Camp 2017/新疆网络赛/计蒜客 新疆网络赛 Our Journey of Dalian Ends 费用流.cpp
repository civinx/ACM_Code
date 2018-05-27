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

//const int maxn = 100;
const LL INF = 1e17;
const int MAXN = 50000;
struct MCMF {
    struct Edge {
        int from, to;
        LL cap, flow, cost;
    };
    int n, m, s, t;
    // 注意MAXN的大小不一定是原图点的大小
    int inq[MAXN];
    LL d[MAXN];
    int p[MAXN];
    LL a[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];
    
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i ++) G[i].clear();
        edges.clear();
    }
    
    void AddEdge(int from, int to, LL cap, LL cost) {
        edges.push_back((Edge){from, to, cap, 0, cost});
        edges.push_back((Edge){to, from, 0, 0, -cost});
        int m = (int)edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    
    bool BellmanFord(int s, int t, LL &flow, LL &cost) {
        for (int i = 0; i <= n; i ++) d[i] = INF;
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
        
        // 此处有技巧，如果要求最大收益，那么收益的边是负数，当d[t] > 0就说明没有收益，返回false
        // if (d[t] > 0) return false;
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
    
    void Mincost(int s, int t, LL &flow, LL &cost) {
        flow = 0, cost = 0;
        while (BellmanFord(s, t, flow, cost));
    }
} solve;

map<string, int> mp;

int getID(string & s, int & cnt) {
    if (!mp.count(s)) {
        mp[s] = ++cnt;
    }
    return mp[s];
}

struct Input {
    int u, v; LL cost;
}q[MAXN];

int main() {
//    FILER;
    int T; scanf("%d",&T);
    while (T--) {
        mp.clear();
        int m; scanf("%d",&m);
        int cnt = 0;
        
        for (int i = 0; i < m; i ++) {
            string s1, s2; cin >> s1 >> s2;
            int cost; cin >> cost;
            int u = getID(s1, cnt), v = getID(s2, cnt);
            q[i].u = u; q[i].v = v; q[i].cost = cost;
        }
        if (!mp.count("Shanghai") || !mp.count("Xian") || !mp.count("Dalian")) {
            printf("-1\n");
            continue;
        }
        solve.init(cnt * 2);
        int sh = mp["Shanghai"];
        for (int i = 1; i <= cnt; i ++) {
            if (i == sh) solve.AddEdge(i, i+cnt, 2, 0);
            else solve.AddEdge(i, i+cnt, 1, 0);
        }
        for (int i = 0; i < m; i ++) {
            solve.AddEdge(q[i].u + cnt, q[i].v, 1, q[i].cost);
            solve.AddEdge(q[i].v + cnt, q[i].u, 1, q[i].cost);
        }
        solve.AddEdge(0, mp["Xian"], 1, 0);
        solve.AddEdge(0, mp["Dalian"], 1, 0);
        LL flow, cost;
        solve.Mincost(0, mp["Shanghai"] + cnt, flow, cost);
        if (flow < 2) {
            printf("-1\n");
        } else {
            printf("%lld\n",cost);
        }
    }
    return 0;
}