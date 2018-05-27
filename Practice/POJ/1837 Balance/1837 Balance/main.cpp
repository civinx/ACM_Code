//
//  main.cpp
//  1837 Balance
//
//  Created by czf on 16/5/19.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 7500 * 2 + 100;
int dp[21][maxn], c[maxn], w[maxn];

int main() {
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(nullptr);
    int m, n; //m钩子数 n砝码数
    while (cin >> m >> n) {
        for (int i = 1; i <= m; i ++) cin >> c[i];
        for (int i = 1; i <= n; i ++) cin >> w[i];
        memset(dp, 0, sizeof(dp));
        dp[0][7500] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= maxn; j ++) {
                for (int k = 1; k <= m; k ++) {
                    dp[i][j+c[k]*w[i]] += dp[i-1][j];
                }
            }
        }
        cout << dp[n][7500] << '\n';
    }
    return 0;
}
