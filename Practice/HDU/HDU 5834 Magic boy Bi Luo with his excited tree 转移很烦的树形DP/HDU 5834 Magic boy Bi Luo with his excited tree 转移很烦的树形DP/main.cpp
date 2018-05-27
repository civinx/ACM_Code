//
//  main.cpp
//  HDU 5834 Magic boy Bi Luo with his excited tree 转移很烦的树形DP
//
//  Created by czf on 2017/9/12.
//  Copyright © 2017年 czf. All rights reserved.
//

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
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))
#define INIT int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;

const int maxn = 100000 + 100;
//const int maxn = 100;

struct Edge {
    int to, cost;
};

vector<int> G[maxn];
vector<Edge> edges;

void AddEdge(int from, int to, int cost) {
    edges.push_back((Edge){to, cost});
    int m = (int)edges.size()-1;
    G[from].push_back(m);
}

// dp[][0] 需要回来的最优解
// dp[][1] 不需要回来的最优解
// dp[][2] 不需要回来的次优解
int dp[maxn][3], val[maxn], id[maxn], res[maxn];

void init(int n) {
    MS(dp, 0);
    for (int i = 1; i <= n; i ++) G[i].clear();
    edges.clear();
}

int dfs1(int u, int pre, int c) {
    dp[u][0] = val[u];
    int fir = 0, sec = 0;
    for (int eid : G[u]) {
        Edge & e = edges[eid];
        if (e.to == pre) continue;
        int to = e.to, cost = e.cost;
        int ch = dfs1(to, u, cost);
        if (ch > fir) {
            sec = fir;
            fir = ch;
            id[u] = to;
        } else if (ch > sec) {
            sec = ch;
        }
        dp[u][0] += max(dp[to][0] - 2 * cost, 0);
    }
    dp[u][1] = dp[u][0] + fir;
    if (sec) {
        dp[u][2] = dp[u][0] + sec;
    }
    return max(dp[u][1] - c, 0) - max(dp[u][0] - 2 * c, 0);
}

// first 往上走需要回来
// second 往上走不需要回来
void dfs2(pair<int, int> rec, int u, int pre) {
    res[u] = max(dp[u][0] + rec.second, dp[u][1] + rec.first);
    for (int eid : G[u]) {
        Edge & e = edges[eid];
        int v = e.to, cost = e.cost;
        if (v == pre) continue;
        pair<int, int> down(0, 0);
        down.first = rec.first + dp[u][0] - max(dp[v][0] - 2 * cost, 0) - 2 * cost;
        down.second = max(rec.second + dp[u][0] - max(dp[v][0] - 2 * cost, 0) - cost, 0);
        //        down.second = max(down.first - rec.first + rec.second + cost, down.second);
        down.first = max(down.first, 0);
        if (v != id[u]) {
            down.second = max(rec.first + dp[u][1] - max(dp[v][0] - 2 * cost, 0) - cost, down.second);
        } else if (dp[u][2]) {
            down.second = max(rec.first + dp[u][2] - max(dp[v][0] - 2 * cost, 0) - cost, down.second);
        }
        dfs2(down, v, u);
    }
}

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n); init(n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&val[i]);
        }
        for (int i = 1; i <= n-1; i ++) {
            int u, v, cost; scanf("%d%d%d",&u,&v,&cost);
            AddEdge(u, v, cost);
            AddEdge(v, u, cost);
        }
        printf("Case #%d:\n",++kase);
        dfs1(1, 0, 0);
        dfs2(make_pair(0, 0), 1, 0);
        for (int i = 1; i <= n; i ++) {
            printf("%d\n",res[i]);
            //            dfs1(i, 0, 0);
            //            printf("%d\n",dp[i][1]);
        }
    }
    return 0;
}
