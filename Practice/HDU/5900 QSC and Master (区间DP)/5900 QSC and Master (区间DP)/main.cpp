//
//  main.cpp
//  5900 QSC and Master (区间DP)
//
//  Created by czf on 16/9/19.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 500;
typedef long long LL;
LL dp[maxn][maxn], a[maxn], b[maxn];
bool c[maxn][maxn];


void solve(int n) {
    for (int i = 2; i <= n; i ++) {//枚举右区间
        for (int j = i-1; j >= 1; j --) {//枚举左区间
            if (i - j == 1 && __gcd(a[j], a[i]) != 1) {
                dp[j][i] = max(dp[j][i], b[j] + b[i]);
                c[j][i] = 1;
            } else if (c[j+1][i-1] == 1 && __gcd(a[j], a[i]) != 1) {
                dp[j][i] = max(dp[j][i], dp[j+1][i-1] + b[j] + b[i]);
                c[j][i] = 1;
            }
            for (int k = j; k <= i; k ++) {//区间[j, i]合并
                if (k+1 >= j && k+1 <= i) {
                    if (dp[j][i] < dp[j][k] + dp[k+1][i]) {
                        dp[j][i] = dp[j][k] + dp[k+1][i];
                        if (c[j][k] && c[k+1][i]) {
                            c[j][i] = 1;
                        } else {
                            //                            c[j][i] = 0;
                        }
                    }
                }
            }
        }
    }
    
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        memset(dp, 0, sizeof(dp));
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i ++) cin >> a[i]; //key
        for (int i = 1; i <= n; i ++) cin >> b[i]; //value
        solve(n);
        cout << dp[1][n] << '\n';
    }
    return 0;
}