//
//  main.cpp
//  5934 Bomb (Tarjan缩点)
//
//  Created by czf on 2016/10/31.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 100;
const int INF = 0x3f3f3f3f;
typedef long long  LL;

struct {LL x, y, r, c;} a[MAXN];
int color[MAXN], ing[MAXN], dfn[MAXN], low[MAXN], vis[MAXN], cnt, colorCnt;;
LL cost[MAXN];
vector<int> G1[MAXN], G2[MAXN], s;

bool check(const int i, const int j) {
    LL dist = (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
    return a[i].r * a[i].r >= dist;
}


void dfs(int x) {
    dfn[x] = low[x] = ++cnt;
    s.push_back(x);
    vis[x] = 1;
    for (int i = 0; i < G1[x].size(); i ++) {
        int to = G1[x][i];
        if (!vis[to]) {
            dfs(to);
            low[x] = min(low[x], low[to]);
        } else {
            if (vis[to] == 1) {
                low[x] = min(low[x], dfn[to]);
            }
        }
    }
    if (low[x] == dfn[x]) {
        while (s.back() != x) {
            color[s.back()] = colorCnt;
            cost[colorCnt] = min(cost[colorCnt], a[s.back()].c);
            vis[s.back()] = 2;
            s.pop_back();
        }
        cost[colorCnt] = min(cost[colorCnt], a[s.back()].c);
        color[s.back()] = colorCnt++;
        vis[s.back()] = 2;
        s.pop_back();
    }
}


void init(int n) {
    for (int i = 0; i <= n; i ++) G1[i].clear(), G2[i].clear();
    s.clear(); cnt = colorCnt = 0;
    memset(cost, INF, sizeof(cost));
    memset(ing, 0, sizeof(ing));
    memset(vis, 0, sizeof(vis));
}

int main() {
    int t, kase = 0; cin >> t;
    while (t--) {
        int n; cin >> n; init(n);
        for (int i = 0; i < n; i ++) cin >> a[i].x >> a[i].y >> a[i].r >> a[i].c;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != j && check(i, j)) G1[i].push_back(j);
            }
        }
        for (int i = 0; i < n; i ++) {
            if (!vis[i]) dfs(i);
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != j && color[i] != color[j] && check(i, j)) {
                    G2[color[i]].push_back(color[j]);
                    ing[color[j]] ++;
                }
            }
        }
        LL res = 0;
        for (int i = 0; i < colorCnt; i ++) {
            if (ing[i] == 0) res += cost[i];
        }
        cout << "Case #" << ++kase << ": " << res << '\n';
    }
    return 0;
}
