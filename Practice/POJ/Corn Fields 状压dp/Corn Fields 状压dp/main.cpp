//
//  main.cpp
//  Corn Fields 状压dp
//
//  Created by czf on 16/7/10.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 100000000;
int dp[20][1<<15], map[20];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        memset(dp, 0, sizeof(dp));
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                int x; cin >> x;
                if (x == 1) map[i] += 1 << (m-j);
            }
        }
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j < (1 << m); j ++) {
                if ((map[i] & j) != j || (j & (j << 1)) != 0) continue;
                for (int k = 0; k < (1 << m); k ++) {
                    if ((k & j) || (map[i-1] & k) != k || (k & (k << 1)) != 0) continue;
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < (1 << m); i ++) {
            res = (res + dp[n][i]) % mod;
        }
        cout << res << '\n';
    }
    return 0;
}
