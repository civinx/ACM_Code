//
//  main.cpp
//  Problem : Anniversary party
//
//  Created by czf on 16/5/14.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 6000 + 1000;
//const int maxn = 10;

int rat[maxn];
int par[maxn];
int dp[maxn][2];
vector<int> G[maxn];

void Init(int n) {
    for (int i = 1; i <= n; i ++) G[i].clear();
    memset(par, -1, sizeof(par));
    memset(dp, 0, sizeof(dp));
}

void dfs(int x) {
    if (!G[x].size()) {
        dp[x][1] = rat[x];
        return;
    }
    for (int i = 0; i < G[x].size(); i ++) {
        int son = G[x][i]; dfs(son);
        dp[x][0] += max(dp[son][0], dp[son][1]);
        dp[x][1] += dp[son][0];
    }
    dp[x][1] += rat[x];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    while (cin >> n) {
        Init(n);
        for (int i = 1; i <= n; i ++) cin >> rat[i];
        int s, p;
        while (cin >> s >> p && (s || p)) {
            G[p].push_back(s);
            par[s] = p;
        }
        int res = 0;
        for (int i = 1; i <= n; i ++) if (par[i] == -1) {
            dfs(i); res += max(dp[i][0], dp[i][1]);
        }
        cout << res << '\n';
    }
    return 0;
}
