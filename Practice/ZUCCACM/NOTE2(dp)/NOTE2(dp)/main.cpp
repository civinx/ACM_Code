//
//  main.cpp
//  NOTE2(dp)
//
//  Created by czf on 16/7/11.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
const int inf = 0x77ffffff;
using namespace std;
const int N = 200;
int a[N][N], dp[N][N][N];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i ++)
            for (int j = 0; j < N; j ++)
                for (int k = 0; k < N; k ++)
                    dp[k][i][j] = -inf;
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                cin >> a[i][j];
            }
        }
        dp[0][0][0] = a[1][1];
        for (int k = 1; k <= n+m-2; k ++) {
            for (int i = 0; i <= n-1; i ++) {
                for (int j = 0; j <= n-1; j ++) {
                    if (i == j && (k != n+m-2 || i != n-1)) continue;
                    int t1 = (i >= 1 && j >= 1 ?dp[k-1][i-1][j-1] : -inf);
                    int t2 = (i >= 1 ? dp[k-1][i-1][j] : -inf);
                    int t3 = (j >= 1 ? dp[k-1][i][j-1] : -inf);
                    int t4 = dp[k-1][i][j];
                    dp[k][i][j] = max(max(t1,t2), max(t3,t4)) + a[1+i][k-i+1] + a[1+j][k-j+1];
                    
                }
            }
        }
        cout << dp[n+m-2][n-1][n-1] - a[n][m] << '\n';
    }
    return 0;
}
