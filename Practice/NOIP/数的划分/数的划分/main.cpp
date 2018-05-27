//
//  main.cpp
//  数的划分
//
//  Created by czf on 2017/1/23.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
using namespace std;
const int maxn = 222;
typedef long long LL;

LL dp[maxn][10];

int main() {
    int n, k; cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= k && j <= i; j ++) {
            dp[i][j] = dp[i-j][j] + dp[i-1][j-1];
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}

