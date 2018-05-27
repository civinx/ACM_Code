//
//  main.cpp
//  5723 Abandoned country 最小生成树
//
//  Created by czf on 2017/4/13.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn = 100000 + 100;
//const int maxn = 10;

struct Edge {
    int u, v;
    double w;
    bool operator < (const Edge & rhs) const {
        return w < rhs.w;
    }
};

int fa[maxn], pre[maxn];
double son[maxn];
vector<int> G[maxn];
vector<Edge> edges, edges_temp;

void init(int n) {
    for (int i = 1; i <= n; i ++) {
        fa[i] = i;
        G[i].clear();
    }
    edges.clear();
    edges_temp.clear();
    memset(son, 0, sizeof(son));
    memset(pre, 0, sizeof(pre));
}

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int dfs(int x, int from) {
    for (int i = 0; i < G[x].size(); i ++) {
        int v = G[x][i];
        if (v == from) continue;
        son[x] += dfs(v, x);
    }
    pre[x] = from;
    return ++son[x];
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, m; scanf("%d%d",&n,&m);
        init(n);
        for (int i = 0; i < m; i ++) {
            int u, v; double w;
            scanf("%d%d%lf",&u,&v,&w);
            edges_temp.push_back((Edge){u, v, w});
        }
        sort(edges_temp.begin(), edges_temp.end());
        LL sum = 0;
        for (int i = 0; i < m; i ++) {
            Edge &e = edges_temp[i];
            int u = e.u, v = e.v; double w = e.w;
            
            int uu = find(u), vv = find(v);
            if (uu == vv) {
                continue;
            }
            fa[uu] = vv;
            edges.push_back((Edge){u, v, w});
            G[u].push_back(v);
            G[v].push_back(u);
            sum += w;
            if (edges.size() == n-1) {
                break;
            }
        }
        dfs(1, 0);
    
        double ex = 0;
        double N = n;
        for (int i = 0; i < n-1; i ++) {
            Edge &e = edges[i];
            int u = e.u, v = e.v; double w = e.w;
            if (pre[u] == v) swap(u, v);
//            printf("u = %d, v = %d, son[v] = %d, ans = %.f\n",u,v,son[v],(son[v]) * (n - son[v]) * 2 * w);
//            ex += (son[u]-1) * (n - son[u] + 1) * 2 * w;
            ex += (son[v]) * (N - son[v]) * 2 * w;
        }
        ex /= N * (N - 1.0);
        printf("%lld %.2f\n",sum,ex);
    }
    return 0;
}
