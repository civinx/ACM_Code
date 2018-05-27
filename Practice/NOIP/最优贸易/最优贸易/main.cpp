//
//  main.cpp
//  最优贸易
//
//  Created by czf on 2017/2/9.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <stack>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 111111;
const int INF = 0x3f3f3f3f;


vector<int> G1[maxn], G2[maxn];
vector<pair<int, int> > edges;
stack<int> s;

//Tarjan
int color[maxn], low[maxn], dfn[maxn], vis[maxn], cnt, colorCnt;

//
int mi[maxn], mx[maxn], a[maxn], f[maxn], res, n, m;

void Tarjan(int x) {
    vis[x] = 1;
    s.push(x);
    dfn[x] = low[x] = ++cnt;
    for (int i = 0; i < G1[x].size(); i ++) {
        int to = G1[x][i];
        if (!vis[to]) {
            Tarjan(to);
            low[x] = min(low[x], low[to]);
        } else if (vis[to] == 1) {
            low[x] = min(low[x], dfn[to]);
        }
    }
    if (low[x] == dfn[x]) {
        while (s.top() != x) {
            mi[colorCnt] = min(mi[colorCnt], a[s.top()]);
            mx[colorCnt] = max(mx[colorCnt], a[s.top()]);
            color[s.top()] = colorCnt;
            vis[s.top()] = 2;
            s.pop();
        }
        
        mi[colorCnt] = min(mi[colorCnt], a[s.top()]);
        mx[colorCnt] = max(mx[colorCnt], a[s.top()]);
        color[s.top()] = colorCnt;
        vis[s.top()] = 2;
        s.pop();
        
        colorCnt ++;
    }
}

void init() {
    memset(mi, INF, sizeof(mi));
    memset(mx, 0, sizeof(mx));
}

void dfs(int x) {
    vis[x] = 1;
    if (x == color[n]) {
        f[x] = max(f[x], mx[x]);
    }
    for (int i = 0; i < G2[x].size(); i ++) {
        int to = G2[x][i];
        if (!vis[to]) dfs(to);
        f[x] = max(f[x], f[to]);
    }
    if (f[x]) f[x] = max(f[x], mx[x]);
    res = max(res, f[x] - mi[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 0; i < m; i ++) {
        int u, v, k; cin >> u >> v >> k;
        G1[u].push_back(v);
        edges.push_back(make_pair(u, v));
        if (k == 2) {
            G1[v].push_back(u);
            edges.push_back(make_pair(v, u));
        }
    }
    init();
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) Tarjan(i);
    }
    for (int i = 0; i < edges.size(); i ++) {
        int u = edges[i].first, v = edges[i].second;
        if (color[u] != color[v]) G2[color[u]].push_back(color[v]);
    }
    
    memset(vis, 0, sizeof(vis));
    dfs(color[1]);
    cout << res << '\n';
}
