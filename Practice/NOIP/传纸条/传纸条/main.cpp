//
//  main.cpp
//  传纸条
//
//  Created by czf on 2017/2/6.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 55;

int dp[maxn<<1][maxn][maxn], a[maxn][maxn];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    
    for (int k = 3; k <= n + m; k ++) {
        for (int i = 1; i <= n && i <= k - 1; i ++) {
            for (int j = 1; j <= n && j <= k - 1; j ++) {
                if (i == j && k != n + m) continue;
                int temp = 0;
                temp = max(temp, dp[k-1][i][j]);
                temp = max(temp, dp[k-1][i][j-1]);
                temp = max(temp, dp[k-1][i-1][j]);
                temp = max(temp, dp[k-1][i-1][j-1]);
                dp[k][i][j] = temp + a[i][k-i] + a[j][k-j];
//                printf("dp[%d][%d][%d] = %d\n",k,i,j,dp[k][i][j]);
            }
        }
    }
    
    cout << dp[n+m][n][n] << '\n';
    return 0;
}
