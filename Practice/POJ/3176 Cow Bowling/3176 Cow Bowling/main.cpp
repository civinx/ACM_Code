//
//  main.cpp
//  3176 Cow Bowling
//
//  Created by czf on 16/5/20.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 400;
int a[maxn][maxn], n;
int dp[maxn][maxn];

int main() {
    while (cin >> n) {
        memset(a, -1, sizeof(a));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= i; j ++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i ++)
            dp[n][i] = a[n][i];
        for (int i = n-1; i >= 1; i --) {
            for (int j = 1; j <= i; j ++) {
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j];
            }
        }
        cout << dp[1][1] << '\n';
    }
    return 0;
}
