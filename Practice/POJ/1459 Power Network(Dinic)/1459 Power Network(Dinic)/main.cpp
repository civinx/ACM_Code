//
//  main.cpp
//  1459 Power Network(Dinic)
//
//  Created by czf on 16/7/11.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200;
struct Edge {
    int u, v, c, f;
    Edge (int u, int v, int c, int f) : u(u), v(v), c(c), f(f) {}
};

vector<Edge> edge;
vector<int> G[N];
int n, m, np, nc, dis[N];

void init() {
    for (int i = 0; i < N; i ++) G[i].clear();
    edge.clear();
}

void add(int u, int v, int c, int f) {
    Edge e(u,v,c,f);
    edge.push_back(e);
    int m = edge.size()-1;
    G[u].push_back(m);
}

bool build() {
    memset(dis, -1, sizeof(dis)); dis[n] = 0;
    queue<int> q; q.push(n);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < G[cur].size(); i ++) {
            Edge &e = edge[G[cur][i]]; int v = e.v;
            if (e.c > 0 && dis[v] < 0) {
                dis[v] = dis[cur] + 1;
                q.push(v);
            }
        }
    }
    return dis[n+1] > 0;
}

int find(int u, int low) {
    if (u == n+1) return low;
    int ans = 0;
    for (int i = 0; i < G[u].size(); i ++) {
        Edge &e = edge[G[u][i]]; int v = e.v;
        Edge &e1 = edge[G[u][i]^1];
        int f = min(low, e.c);
        if (e.c > 0 && dis[v] == dis[u]+1 && (ans = find(v, f))) {
            e.c -= ans; e.f += ans;
            e1.c += ans; e1.f += ans;
            return ans;
        }
    }
    dis[u] = -1;
    return 0;
}

int main() {
    while (scanf("%d%d%d%d",&n,&np,&nc,&m) != EOF) {
        init();
        for (int i = 0; i < m; i ++) {
            int u, v, c; scanf(" (%d,%d)%d",&u,&v,&c);
            add(u, v, c, 0); add(v, u, 0, 0);
        }
        for (int i = 0; i < np; i ++) {
            int v, c; scanf(" (%d)%d",&v,&c);
            add(n, v, c, 0); add(v, n, 0, 0);
        }
        for (int i = 0; i < nc; i ++) {
            int u, c; scanf(" (%d)%d",&u,&c);
            add(u, n+1, c, 0); add(n+1, u, 0, 0);
        }
        int res = 0, ans = 0;
        while (build()) {
            while ((ans = find(n, 0x7fffffff))) res += ans;
        }
        cout << res << '\n';
    }
    return 0;
}
