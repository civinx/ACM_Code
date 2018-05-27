//
//  main.cpp
//  Problem : Employment Planning
//
//  Created by czf on 16/5/15.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 20;
const int inf = 0xfffffff;
int a[maxn];
int dp[maxn][2000];

int solve(int hire, int sala, int fir, int maxd, int n) {
    for (int i = 0; i < maxn; i ++) {//初始化
        for (int j = 0; j < 2000; j ++) {
            dp[i][j] = inf;
        }
    }
    for (int i = a[1]; i <= maxd; i ++) dp[1][i] = i * (hire + sala);
    for (int i = 2; i <= n; i ++) {//处理第i个月
        for (int j = a[i]; j <= maxd; j ++) {//处理第i个月的雇佣j的情况
            for (int k = a[i-1]; k <= maxd; k ++) {//可能由上个月雇佣k个人的情况得来
                int temp = 0;
                if (k <= j) temp = dp[i-1][k] + (j - k) * hire + j * sala;
                else temp = dp[i-1][k] + (k - j) * fir + j * sala;
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }
    int res = inf;
    for (int i = a[n]; i <= maxd; i ++)
        res = min(res, dp[n][i]);
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    while (cin >> n && n) {
        int hire, sala, fir; cin >> hire >> sala >> fir;
        int maxd = 0;
        for (int i = 1; i <= n; i ++) { cin >> a[i]; maxd = max(maxd, a[i]); }
        int res = solve(hire, sala, fir, maxd, n);
        cout << res << endl;
    }
    return 0;
}

