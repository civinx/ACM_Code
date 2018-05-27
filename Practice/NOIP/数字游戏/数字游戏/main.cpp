//
//  main.cpp
//  数字游戏
//
//  Created by czf on 2017/1/22.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 111;
const int maxm = 10;
const int INF = 0x3f3f3f3f;
int mi[maxn][maxm], mx[maxn][maxm], sum[maxn];
int Max = 0, Min = INF;

int aa[maxn];

void solve(int a[], int n, int m) {
    for (int i = 0; i < maxn; i ++) {
        for (int j = 0; j < maxm; j ++) {
            mi[i][j] = INF;
            mx[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i ++) {
        sum[i] = (i == 0 ? a[i] : sum[i-1] + a[i]);
    }
    for (int i = 0; i < n; i ++) {
        mi[i][1] = mx[i][1] = (sum[i] % 10 + 10) % 10;
    }
    for (int k = 2; k <= m; k ++) {
        for (int i = 0; i < n; i ++) {
            for (int j = k-2; j < i; j ++) {
                mi[i][k] = min(mi[i][k], mi[j][k-1] * (((sum[i] - sum[j]) % 10 + 10) % 10));
                mx[i][k] = max(mx[i][k], mx[j][k-1] * (((sum[i] - sum[j]) % 10 + 10) % 10));
            }
        }
    }
    Max = max(Max, mx[n-1][m]);
    Min = min(Min, mi[n-1][m]);
}

int main() {
    int n, m; scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i ++) {
        scanf("%d",&aa[i]);
        aa[i+n] = aa[i];
    }
    for (int i = 0; i < n; i ++) {
        solve(aa+i, n, m);
    }
    printf("%d\n%d\n",Min,Max);
    return 0;
}

