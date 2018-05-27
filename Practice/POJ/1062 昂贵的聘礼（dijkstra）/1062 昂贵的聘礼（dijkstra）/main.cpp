//
//  main.cpp
//  1062 昂贵的聘礼（dijkstra）
//
//  Created by czf on 16/4/20.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000;
const int inf = 0xfffffff;
int M, N;

struct Edge {
    int from, to, dist;
};

struct HeapNode {
    int d, u;
    bool operator > (const HeapNode & rhs) const {
        return this->d > rhs.d;
    }
};

struct Dijkstra {
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int ans[maxn];
    
    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i ++) G[i].clear();
        edges.clear();
    }
    
    void AddEdge(int from, int to, int dist) {
        edges.push_back((Edge){from, to, dist});
        m = (int)edges.size();
        G[from].push_back(m-1);
    }
    
    void dijkstra(int s, int l, int r) {
        priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode> > q;
        for (int i = 0; i < n; i ++) d[i] = inf;
        d[0] = 0;
        memset(vis, 0, sizeof(vis));
        q.push((HeapNode){0,0});
        while (!q.empty()) {
            HeapNode x = q.top(); q.pop();
            int u = x.u;
            if (vis[u]) continue;
            vis[u] = 1;
            for (int i = 0; i < G[u].size(); i ++) {
                Edge &e = edges[G[u][i]];
                if (u && (ans[u] > r || ans[u] < l)) continue;
                if (d[e.to] > d[u] + e.dist) {
                    d[e.to] = d[u] + e.dist;
                    q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
};

int main() {
    while (~scanf("%d%d",&M,&N)) {
        Dijkstra a;
        a.init(N+1);
        for (int i = 1; i <= N; i ++) {
            int cost, level, n;
            scanf("%d%d%d",&cost,&level,&n);
            a.ans[i] = level;
            a.AddEdge(0,i,cost);
            for (int j = 0; j < n; j ++) {
                int num, cost; scanf("%d%d",&num,&cost);
                a.AddEdge(num,i,cost);
            }
        }
        int res = inf;
        for (int i = a.ans[1] - M; i <= a.ans[1]; i ++) {
            a.dijkstra(0, i, i + M);
            res = min(res, a.d[1]);
        }
        printf("%d\n",res);
    }
    return 0;
}
