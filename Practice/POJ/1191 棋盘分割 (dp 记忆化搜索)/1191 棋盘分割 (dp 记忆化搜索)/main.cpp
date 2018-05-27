//
//  main.cpp
//  1191 棋盘分割 (dp 记忆化搜索)
//
//  Created by czf on 16/9/21.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 20;
const int N = 8;
const int inf = 10000000;
int a[N+5][N+5];
int sum[N+5][N+5];
int dp[maxn][N+5][N+5][N+5][N+5]; //dp[k][x1][y1][x2][y2]
int n;

void read() {
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            scanf("%d",&a[i][j]);
        }
    }
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]+ a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
}

int get_sum(int x1, int y1, int x2, int y2) {
    int ret = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
    return ret*ret;
}

void test() {
    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        cout << get_sum(x1, y1, x2, y2) << endl;
    }
}

int cnt = 0;
int dfs(int k, int x1, int y1, int x2, int y2) {
    if (dp[k][x1][y1][x2][y2] != -1) {
        //        cout << ++cnt << " Get" << endl;
        return dp[k][x1][y1][x2][y2];
    }
    if (k == 0) {
        return dp[k][x1][y1][x2][y2] = get_sum(x1, y1, x2, y2);
    }
    int ret = inf;
    for (int i = x1; i < x2; i ++) {
        int t1 = min(dfs(k-1, x1, y1, i, y2)+get_sum(i+1, y1, x2, y2), dfs(k-1, i+1, y1, x2, y2)+get_sum(x1, y1, i, y2));
        ret = min(ret, t1);
    }
    for (int j = y1; j < y2; j ++) {
        int t2 = min(dfs(k-1, x1, y1, x2, j)+get_sum(x1, j+1, x2, y2), dfs(k-1, x1, j+1, x2, y2)+get_sum(x1, y1, x2, j));
        ret = min(ret, t2);
    }
    return dp[k][x1][y1][x2][y2] = ret;
}

int main() {
    while (~scanf("%d",&n)) {
        read();
        
        double ans = (sqrt(get_sum(1, 1, N, N)*1.0) / n);
        double res = dfs(n-1, 1, 1, N, N)*1.0 / n - ans * ans*1.0;
        printf("%.3f\n",sqrt(res));
        
        //        cout << sqrt(get_sum(1, 1, N, N)*1.0) << endl;
        //        cout << dfs(n-1, 1, 1, N, N) << endl;
        //        cout << 0x7fffffff << endl;
    }
    return 0;
}


