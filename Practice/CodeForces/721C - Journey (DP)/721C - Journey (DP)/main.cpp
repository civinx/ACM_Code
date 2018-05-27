//
//  main.cpp
//  721C - Journey (DP)
//
//  Created by czf on 2016/10/9.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 5000 + 100;

struct Edge {
    int from, to, cost;
};

vector<Edge> edges;
vector<int> G[MAXN];

int n, m, t;
int dp[MAXN][MAXN], pre[MAXN][MAXN], vis[MAXN];

void AddEdge(int from, int to, int cost) {
    edges.push_back((Edge){from, to, cost});
    int m = (int)edges.size() - 1;
    G[from].push_back(m);
}

void init() {
    for (int i = 0; i <= n; i ++) G[i].clear();
    edges.clear();
    memset(dp, INF, sizeof(dp));
    memset(pre, -1, sizeof(pre));
    memset(vis, 0, sizeof(vis));
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i ++) {
        Edge &e = edges[G[u][i]];
        int v = e.to;
        dfs(v);
        for (int i = 2; i <= n; i ++) {
            if (dp[v][i-1] + e.cost < dp[u][i]) {
                dp[u][i] = dp[v][i-1] + e.cost;
                pre[u][i] = v;
            }
        }
    }
}

void print(int u, int num) {
    if (u == -1) return;
    print(pre[u][num], num-1);
    if (pre[u][num] != -1) printf(" ");
    printf("%d",u);
}

int main() {
    while (scanf("%d%d%d",&n,&m,&t) == 3) {
        init();
        for (int i = 0; i < m; i ++) {
            int from, to, cost; scanf("%d%d%d",&from,&to,&cost);
            AddEdge(to, from, cost);
        }
        dp[1][1] = 0;
        dfs(n);
        int num = 0;
        for (int i = 1; i <= n; i ++) {
            if (dp[n][i] <= t) {
                num = max(num, i);
            }
        }
        printf("%d\n",num);
        print(n, num);
        printf("\n");
    }
    return 0;
}