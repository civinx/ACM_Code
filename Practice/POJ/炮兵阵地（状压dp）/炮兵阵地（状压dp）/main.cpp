//
//  main.cpp
//  炮兵阵地（状压dp）
//
//  Created by czf on 16/7/10.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[110][70][70], state[70], a[11] = {0}, map[110], num[70];
int cnt = 0;

void dfs(int x) {
    if (x == 11) {
        int temp = 0, g = 0;
        for (int i = 1; i <= 10; i ++) temp = temp * 2 + a[i], g += a[i];
        num[cnt] = g;
        state[cnt++] = temp;
        return;
    }
    if ((x == 1) || (x == 2 && !a[x-1]) || (a[x-1] == 0 && a[x-2] == 0)) { a[x] = 1; dfs(x+1); }
    a[x] = 0; dfs(x+1);
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    dfs(1);
    int n, m;
    while (cin >> n >> m) {
        cin.get();
        memset(dp, 0, sizeof(dp));
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                char x; cin >> x;
                if (x == 'P') map[i] += 1<< (j-1);
            }
            cin.get();
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j < cnt; j ++) {
                if ((map[i] & state[j]) != state[j]) continue; //与地图不相符
                if (i == 1) {dp[i][j][0] = max(dp[i][j][0], num[j]); continue;}
                for (int k = 0; k < cnt; k ++) {
                    if ((map[i-1] & state[k]) != state[k]) continue; //与地图不相符
                    if (state[k] & state[j]) continue; //与上一层不相容
                    if (i == 2) {dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][0]+num[j]); continue;}
                    for (int g = 0; g < cnt; g ++) {
                        if ((map[i-2] & state[g]) != state[g]) continue; //与地图不相符
                        if (state[g] & state[k]) continue;
                        if (state[g] & state[j]) continue;
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][g] + num[j]);
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < cnt; i ++) {
            for (int j = 0; j < cnt; j ++) {
                res = max(res, dp[n][i][j]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}

