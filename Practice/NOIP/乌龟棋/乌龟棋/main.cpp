//
//  main.cpp
//  乌龟棋
//
//  Created by czf on 2017/2/10.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 400;
const int maxm = 50;
int a[maxn], dp[maxm][maxm][maxm][maxm], c[5];

int dfs() {
    if (dp[c[1]][c[2]][c[3]][c[4]] != -1) {
        return dp[c[1]][c[2]][c[3]][c[4]];
    }
    int ret = 0, cur = c[1] + c[2] * 2 + c[3] * 3 + c[4] * 4;
    for (int i = 1; i <= 4; i ++) {
        if (!c[i]) continue;
        c[i] --;
        ret = max(ret, dfs() + a[cur]);
        c[i] ++;
    }
    return dp[c[1]][c[2]][c[3]][c[4]] = ret;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < m; i ++) {
        int x; cin >> x;
        c[x] ++;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = a[0];
    cout << dfs() << '\n';
    return 0;
}
