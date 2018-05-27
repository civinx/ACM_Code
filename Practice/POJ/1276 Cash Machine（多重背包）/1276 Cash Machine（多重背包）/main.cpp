//
//  main.cpp
//  1276 Cash Machine（多重背包）
//
//  Created by czf on 16/5/19.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 100;
const int maxm = 100000 + 100;
int w[maxn], d[maxn], dp[maxm], n, v;

void ZP(int w) {
    for (int i = v; i >= w; i --) {
        dp[i] = max(dp[i], dp[i-w] + w);
    }
}

void CP(int w) {
    for (int i = w; i <= v; i ++) {
        dp[i] = max(dp[i], dp[i-w] + w);
    }
}

void MP(int w, int n) {
    if (n * w >= v) {
        CP(w);
        return;
    }
    int k = 1;
    while (k < n) {
        ZP(k * w);
        n -= k;
        k <<= 1;
    }
    ZP(n * w);
}

int main() {
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    while (cin >> v >> n) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i ++) cin >> d[i] >> w[i];
        for (int i = 1; i <= n; i ++) MP(w[i], d[i]);
        cout << dp[v] << '\n';
    }
    return 0;
}
