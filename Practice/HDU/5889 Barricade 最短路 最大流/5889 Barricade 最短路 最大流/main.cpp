//
//  main.cpp
//  5889 Barricade 最短路 最大流
//
//  Created by czf on 16/9/27.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 100;
const int inf = 10000000;

struct Edge {
    int from, to, cap, flow;
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    
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

int c[maxn][maxn];
int d[maxn];
bool vis[maxn];
vector<int> G[maxn];

void bfs() {
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    d[1] = 0;
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < G[x].size(); i ++) {
            int to = G[x][i];
            if (!vis[to]) {
                vis[to] = 1;
                d[to] = d[x] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        g.init(n);
        for (int i = 0; i < m; i ++) {
            int from, to, cap; cin >> from >> to >> cap;
            c[from][to] = c[to][from] = cap;
            G[from].push_back(to);
            G[to].push_back(from);
        }
        bfs();
        for (int i = 1;i <= n; i ++) {
            for (int j = 0; j < G[i].size(); j ++) {
                int to = G[i][j];
                if (d[i] + 1 == d[to]) {
                    g.AddEdge(i, to, c[i][to]);
                }
            }
        }
        cout << g.Maxflow(1, n) << '\n';
        for (int i = 0; i < n; i ++) G[i].clear();
    }
    return 0;
}