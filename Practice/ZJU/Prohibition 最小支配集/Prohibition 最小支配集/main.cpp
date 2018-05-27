//
//  main.cpp
//  Prohibition 最小支配集
//
//  Created by czf on 2017/5/15.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 200;
const int INF = 0x3f3f3f3f;

int dp[maxn][3], n;
bool vis[maxn];
vector<pair<int, int> > nxt[maxn][3];
vector<int> G[maxn];

void init() {
    for (int i = 0; i <= n; i ++) {
        nxt[i][0].clear();
        nxt[i][1].clear();
        nxt[i][2].clear();
        G[i].clear();
    }
    memset(vis, 0, sizeof(vis));
    memset(dp, INF, sizeof(dp));
}

bool isleaf(int x) {
    return x != 1 && G[x].size() == 1;
}

/*
 dp[][0] 被自己支配
 dp[][1] 被父亲支配
 dp[][2] 被某些个儿子支配
 */

int getmin(int x) {
    if (dp[x][0] <= dp[x][1] && dp[x][0] <= dp[x][2]) return 0;
    if (dp[x][1] <= dp[x][0] && dp[x][1] <= dp[x][2]) return 1;
    return 2;
}

void dp0(int x, int v) {
    int c = getmin(v);
    dp[x][0] += dp[v][c];
    nxt[x][0].push_back(make_pair(v, c));
}

void dp1(int x, int v) {
    if (dp[x][1] != INF && dp[v][2] != INF) {
        dp[x][1] += dp[v][2];
        nxt[x][1].push_back(make_pair(v, 2));
    }
    else {
        dp[x][1] = INF;
        nxt[x][1].clear();
    }
    
}

bool dp2(int x, int v, int & off, int & pos) {
    bool flag = dp[v][0] <= dp[v][2];
    if (flag) {
        dp[x][2] += dp[v][0];
        nxt[x][2].push_back(make_pair(v, 0));
    } else {
        dp[x][2] += dp[v][2];
        nxt[x][2].push_back(make_pair(v, 2));
        if (dp[x][0] - dp[x][2] < off) {
            off = dp[x][0] - dp[x][2];
            pos = (int)nxt[x][2].size()-1;
        }
    }
    return flag;
}

void dfs(int x, int fa) {
    if (isleaf(x)) {
        dp[x][0] = 1;
        dp[x][1] = 0;
        dp[x][2] = INF;
        return;
    }
    dp[x][0] = 1;
    dp[x][1] = 0;
    dp[x][2] = 0;
    bool flag = 0;
    int off = INF, pos = 0;
    for (int i = 0; i < G[x].size(); i ++) {
        int v = G[x][i];
        if (v == fa) continue;
        dfs(v, x);
        dp0(x, v);
        dp1(x, v);
        flag = dp2(x, v, off, pos) || flag;
    }
    if (flag == 0) {
        dp[x][2] += off;
        nxt[x][2][pos].second = 0;
    }
}

void solve(int x, int c) {
    if (c == -1) c = dp[1][0] < dp[1][2] ? 0 : 2;
    if (c == 0) vis[x] = 1;
    for (int i = 0; i < nxt[x][c].size(); i ++) {
        solve(nxt[x][c][i].first, nxt[x][c][i].second);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n;
        init();
        for (int i = 0; i < n - 1; i ++) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1);
        solve(1, -1);
//        cout << "___" << dp[1][getmin(1)] << endl;
        for (int i = 1; i <= n; i ++) {
            printf("%d%c",vis[i],i==n?'\n':' ');
        }
    }
    return 0;
}
