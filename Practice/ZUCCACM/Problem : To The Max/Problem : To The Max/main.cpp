//
//  main.cpp
//  Problem : To The Max
//
//  Created by czf on 16/5/16.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200;
int a[maxn][maxn];
int sum[maxn][maxn], n;

int solve(int l, int r) {
    int ret = 0, ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += sum[i][r] - sum[i][l];
        if (ans < 0) ans = 0;
        ret = max(ret, ans);
    }
    return ret;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (cin >> n) {
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                cin >> a[i][j];
                sum[i][j] = sum[i][j-1] + a[i][j];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i ++) { //枚举区间
            for (int j = 0; j < i; j ++) {
                res = max(solve(j, i), res);
            }
        }
        cout << res << '\n';
    }
    return 0;
}

