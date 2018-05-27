//
//  main.cpp
//  2586 How far away ？(LCA 倍增)
//
//  Created by czf on 16/7/9.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 40000 + 10;

struct Edge {
    int v, next, w;
};

Edge edge[N*2];

int head[N], d[N], g[N][32], dist[N];
int cnt;

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(dist, 0, sizeof(dist));
    memset(g, 0, sizeof(g));
}

void add(int u, int v, int w) {
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt ++;
}

void dfs(int u, int f) {
    g[u][0] = f, d[u] = d[f] + 1;
    for (int k = head[u]; k != -1; k = edge[k].next) {
        int v = edge[k].v;
        if (v != f) {
            dist[v] = dist[u] + edge[k].w;
            dfs(v, u);
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    int j;
    for(j=0;(1<<j)<=d[x];j++);
    j --;
    for (int i = j; i >= 0; i --) {
        if (d[x] - (1<<i) >= d[y]) x = g[x][i];
    }
    if (x == y) return x;
    for (int i = j; i >= 0; i --) {
        int xx = g[x][i], yy = g[y][i];
        if (xx != yy) x = g[x][i], y = g[y][i];
    }
    return g[x][0];
}

int main() {
//    std::ios::sync_with_stdio(false);
    int t; scanf("%d",&t);
    while (t--) {
        init();
        int n, m; scanf("%d%d",&n,&m);
        for (int i = 0; i < n-1; i ++) {
            int u, v, w; scanf("%d%d%d",&u,&v,&w);
            add(u, v, w); add(v, u, w);
        }
        d[1] = 1; dfs(1, 1);
        for (int j = 1; (1<<j) <= n; j ++) {
            for (int i = 1; i <= n; i ++) {
                g[i][j] = g[g[i][j-1]][j-1];
            }
        }
        for (int i = 0; i < m; i ++) {
            int x, y; scanf("%d%d",&x,&y);
            int k = lca(x, y);
            cout << dist[x] + dist[y] - 2 * dist[k] << '\n';
        }
        if (t) cout << "\n";
    }
    return 0;
}
