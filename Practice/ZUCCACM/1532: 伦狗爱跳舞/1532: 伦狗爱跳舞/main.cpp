//
//  main.cpp
//  1532: 伦狗爱跳舞
//
//  Created by czf on 16/5/19.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 100;
int dp[5][5][maxn], e[5][5], a[maxn], n; //dp[i][j][k],跳完k次时 左脚在i，右脚在j，到终态所需的最小值

void Init() {
    for (int i = 1; i <= 4; i ++) e[0][i] = e[i][0] = 2;
    for (int i = 0; i <= 4; i ++) e[i][i] = 1;
    e[1][2] = e[2][1] = e[2][3] = e[3][2] = e[3][4] = e[4][3] = e[1][4] = e[4][1] = 3;
    e[1][3] = e[3][1] = e[2][4] = e[4][2] = 4;
}

int dfs(int x, int y, int k) {
    if (k == n) return 0;
    if (dp[x][y][k] != -1) return dp[x][y][k];
    return dp[x][y][k] = min(dfs(a[k+1], y, k+1) + e[x][a[k+1]], dfs(x, a[k+1], k+1) + e[y][a[k+1]]);
}

int main() {
    Init();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (cin >> n) {
        for (int i = 1; i <= n; i ++) cin >> a[i];
        memset(dp, -1, sizeof(dp));
        dfs(0, 0, 0);
        cout << dp[0][0][0] << '\n';
    }
    return 0;
}

