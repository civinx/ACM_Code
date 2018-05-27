//
//  main.cpp
//  1561 The More,The Better 树形DP 分组背包
//
//  Created by czf on 2016/11/14.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 300;

int dp[MAXN][MAXN], n, m;
vector<int> G[MAXN];

void dfs(int u) {
    for (int i = 0; i < G[u].size(); i ++) { //枚举物品组（每一颗子树）
        int son = G[u][i];
        dfs(son);
        for (int j = m+1; j > 1; j --) { // 分组背包
            for (int k = 1; k < j; k ++) { // 枚举在这个子树种选几个城市（相当于一个物品）
                dp[u][j] = max(dp[u][j], dp[u][j-k] + dp[son][k]);
            }
        }
    }
}

int main() {
    while (scanf("%d%d",&n,&m) && (n || m)) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i ++) G[i].clear();
        for (int i = 1; i <= n; i ++) {
            int from, val; scanf("%d%d",&from,&val);
            G[from].push_back(i);
            for (int j = 1; j <= m; j ++) {
                dp[i][j] = val;
            }
        }
        dfs(0);
        printf("%d\n",dp[0][m+1]);
    }
    return 0;
}
