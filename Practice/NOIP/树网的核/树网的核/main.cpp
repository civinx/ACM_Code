//
//  main.cpp
//  树网的核
//
//  Created by czf on 2017/2/4.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 333;
const int INF = 0x3f3f3f3f;
struct Edge {
    int to, w;
};

vector<int> G[maxn];
vector<Edge> edges;
int n, s, d[maxn], pre[maxn];
bool vis[maxn];

void AddEdge(int from, int to, int w) {
    edges.push_back((Edge){to, w});
    int m = (int)edges.size() - 1;
    G[from].push_back(m);
}

void dfs(int cur) {
    for (int i = 0; i < G[cur].size(); i ++) {
        Edge &e = edges[G[cur][i]];
        int to = e.to, w = e.w;
        if (vis[to] || to == pre[cur]) continue;
        d[to] = d[cur] + w;
        pre[to] = cur;
        dfs(to);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 0; i < n - 1; i ++) {
        int from, to, w; cin >> from >> to >> w;
        AddEdge(from, to, w);
        AddEdge(to, from, w);
    }
    //L->R 0->oo
    int L = 1, R = 1;
    
    //找直径
    d[L] = 0; dfs(L);
    for (int i = 1; i <= n; i ++) {
        if (d[i] > d[L]) L = i;
    }
    memset(pre, 0, sizeof(pre));
    d[L] = 0; dfs(L);
    for (int i = 1; i <= n; i ++) {
        if (d[i] > d[R]) R = i;
    }
    
    int res = INF, j = R;//j枚举左端点, i枚举右端点
    
    //直径上除了核外的点对核偏心距的影响
    int LL = 0, RR = 0;
    for (int i = R; i; i = pre[i]) {
        while (pre[j] && d[i] - d[pre[j]] <= s) j = pre[j];
        if (res > max(d[j], d[R]-d[i])) {
            LL = j, RR = i;
            res = max(d[j], d[R]-d[i]);
        }
    }
    
    //枚举核上每一个点的子树的最大深度
    memset(d, 0, sizeof(d));
    for (int i = RR; i != pre[LL]; i = pre[i]) vis[i] = 1;
    for (int i = RR; i != pre[LL]; i = pre[i]) d[i] = 0, dfs(i);

    for (int i = 1; i <= n; i ++) res = max(res, d[i]);
    cout << res << '\n';
}
