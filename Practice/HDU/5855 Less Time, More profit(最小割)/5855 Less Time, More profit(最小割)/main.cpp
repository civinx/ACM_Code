//
//  main.cpp
//  5855 Less Time, More profit(最小割)
//
//  Created by czf on 16/9/26.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N = 300, M = 300;
const int inf = 100000000;

int pay[N], t[N], pro[M];

struct Edge {
    int from, to, cap, flow;
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N+M];
    bool vis[N+M];
    int d[N+M];
    int cur[N+M];
    
    void init(int n) {
        for (int i = 0; i < n; i ++) G[i].clear();
        edges.clear();
    }
    
    void AddEdge(int from, int to, int cap) {
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
    
    int DFS(int x, int LastMax) {
        if (x == t || LastMax == 0) return LastMax;
        int flow = 0, f;
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
    
    int Maxflow(int s, int t) {
        this->s = s; this->t = t;
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, inf);
        }
        return flow;
    }
    
};

Dinic g;
vector<int> G[N+M];
int n, m, L;

int check(int mid) {
    int s = 0, T = n + m + 1;
    g.init(T + 10);
    for (int i = 1; i <= n; i ++) {
        if (t[i] > mid)
            g.AddEdge(i, T, inf);
        else
            g.AddEdge(i, T, pay[i]);
    }
    int tot = 0;
    for (int i = 1; i <= m; i ++) {
        for (int j = 0; j < G[i].size(); j ++) {
            int to = G[i][j];
            g.AddEdge(i+n, to, inf);
        }
        g.AddEdge(s, i+n, pro[i]);
        tot += pro[i];
    }
    int ans = g.Maxflow(s, T);
    return tot - ans;
}

int main() {
    ios::sync_with_stdio(false);
    int T, kase = 0; cin >> T;
    while (T--) {
        cin >> n >> m >> L;
        int l = 0, r = 0;
        for (int i = 1; i <= n; i ++) {
            cin >> pay[i] >> t[i];
            r = max(r, t[i]);
        }
        for (int i = 1; i <= m; i ++) {
            int k; cin >> pro[i] >> k;
            G[i].clear();
            for (int j = 0; j < k; j ++) {
                int v; cin >> v;
                G[i].push_back(v);
            }
        }
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid) >= L) r = mid;
            else l = mid + 1;
        }
        int res = check(l);
        cout << "Case #" << ++kase << ": ";
        if (res >= L) cout << l << " " << res << '\n';
        else cout << "impossible" << '\n';
    }
    return 0;
}

