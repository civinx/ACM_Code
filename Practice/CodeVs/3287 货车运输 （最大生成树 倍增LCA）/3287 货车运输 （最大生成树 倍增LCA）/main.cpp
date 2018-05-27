//
//  main.cpp
//  3287 货车运输 （最大生成树 倍增LCA）
//
//  Created by czf on 16/9/30.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 100;
//const int MAXN = 100;
const int INF = 0x3f3f3f3f;


struct Edge {
    int from, to, cost;
    bool operator < (const Edge &rhs) const {
        return cost > rhs.cost;
    }
};

vector<Edge> tempe;
vector<Edge> edges;
vector<int> G[MAXN];
int n, m, root[MAXN], anc[MAXN][30], mincost[MAXN][30], deep[MAXN], vis[MAXN];

int find(int x) {
    return x == root[x] ? x : root[x] = find(root[x]);
}

void AddEdge(int from, int to, int cost) {
    edges.push_back((Edge){from, to, cost});
    int m = (int)edges.size() - 1;
    G[from].push_back(m);
}

void dfs(int cur, int pre) {
    vis[cur] = 1; anc[cur][0] = pre;
    for (int i = 0; i < G[cur].size(); i ++) {
        Edge &e = edges[G[cur][i]];
        int to = e.to;
        if (to != pre) {
            deep[to] = deep[cur] + 1;
            mincost[to][0] = e.cost;
            dfs(to, cur);
        }
    }
}

int solve(int p1, int p2) {
    if (find(p1) != find(p2)) {
        return -1;
    }
    int log, ret = INF;
    if (deep[p1] < deep[p2]) swap(p1, p2);
    for (log = 1; (1<<log) <= deep[p1]; log ++); log--;
    for (int i = log; i >= 0; i --) {
        if (deep[p1] - (1<<i) >= deep[p2]) {
            ret = min(ret, mincost[p1][i]);
            p1 = anc[p1][i];
        }
    }
    if (p1 == p2) return ret;
    for (int i = log; i >= 0; i --) {
        int xx = anc[p1][i], yy = anc[p2][i];
        if (xx != yy) {
            ret = min(ret, mincost[p1][i]);
            ret = min(ret, mincost[p2][i]);
            p1 = xx, p2 = yy;
        }
    }
    ret = min(ret, mincost[p1][0]);
    ret = min(ret, mincost[p2][0]);
    return ret;
}

void init() {
    tempe.clear(); edges.clear();
    for (int i = 0; i <= n; i ++) G[i].clear();
    for (int i = 1; i <= n; i ++) root[i] = i;
    memset(vis, 0, sizeof(vis));
    memset(mincost, INF, sizeof(mincost));
}

int main() {
    while (scanf("%d%d",&n,&m) == 2) {
        init();
        for (int i = 0; i < m; i ++) {
            int from, to, cost; scanf("%d%d%d",&from,&to,&cost);
            tempe.push_back((Edge){from, to, cost});
        }
        sort(tempe.begin(), tempe.end());
        for (int i = 0; i < m; i ++) {
            Edge &e = tempe[i];
            int from = e.from, to = e.to;
            from = find(from); to = find(to);
            if (from == to) continue;
            root[from] = to;
            AddEdge(from, to, e.cost);
            AddEdge(to, from, e.cost);
        }
        for (int i = 1; i <= n; i ++) if (!vis[i]) {
            deep[i] = 1; mincost[i][0] = INF;
            dfs(i, i);
        }
        for (int j = 1; (1<<j) < n; j ++) {
            for (int i = 1; i <= n; i ++) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
                mincost[i][j] = min(mincost[i][j-1], mincost[anc[i][j-1]][j-1]);
            }
        }
        int k; scanf("%d",&k);
        while (k --) {
            int x, y; scanf("%d%d",&x,&y);
            printf("%d\n",solve(x, y));
        }
    }
    return 0;
}
