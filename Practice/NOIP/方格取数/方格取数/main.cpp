//
//  main.cpp
//  方格取数
//
//  Created by czf on 2017/1/22.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 11;

int dp[maxn<<1][maxn][maxn], a[maxn][maxn];

int main() {
    int n; scanf("%d",&n);;
    while (1) {
        int x, y, z; scanf("%d%d%d",&x,&y,&z);
        if ((x | y | z) == 0) break;
        a[x-1][y-1] = z;
    }
    dp[0][0][0] = a[0][0];
    for (int k = 1; k <= 2 * (n-1); k ++) {
        for (int i = 0; i < n && i <= k; i ++) {
            for (int j = 0; j < n && j <= k; j ++) {
                int last = 0;
                last = max(last, dp[k-1][i][j]);
                if (i > 0) last = max(last, dp[k-1][i-1][j]);
                if (j > 0) last = max(last, dp[k-1][i][j-1]);
                if (i > 0 && j > 0) last = max(last, dp[k-1][i-1][j-1]);
                dp[k][i][j] = last + a[k-i][i];
                if (i != j) dp[k][i][j] += a[k-j][j];
            }
        }
    }
    printf("%d\n",dp[2*(n-1)][n-1][n-1]);
    return 0;
}
