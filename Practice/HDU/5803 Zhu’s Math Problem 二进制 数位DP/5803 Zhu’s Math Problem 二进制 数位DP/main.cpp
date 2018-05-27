//
//  main.cpp
//  5803 Zhu’s Math Problem 二进制 数位DP
//
//  Created by czf on 2017/4/19.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 7;
const int OFF = 2;
LL dp[64][5][5][16]; //dp[pos][g1][g2][limit]
LL a[4];

int getB(LL x, int pos) {
    return 1 & (x >> pos);
}

int getEnd(int id, int pos, int limit) {
    return getB(limit, id) ? getB(a[id], pos) : 1;
}

LL dfs(int pos, int g1, int g2, int limit) {
    if (pos == -1) {
        return g1 > 0 && g2 >= 0;
    }
    if (dp[pos][g1+OFF][g2+OFF][limit] != -1) {
        return dp[pos][g1+OFF][g2+OFF][limit];
    }
    int e0 = getEnd(0, pos, limit);
    int e1 = getEnd(1, pos, limit);
    int e2 = getEnd(2, pos, limit);
    int e3 = getEnd(3, pos, limit);
    LL ret = 0;
    for (int i = 0; i <= e0; i ++) {
        for (int j = 0; j <= e1; j ++) {
            for (int k = 0; k <= e2; k ++) {
                for (int l = 0; l <= e3; l ++) {
                    int t1 = g1 * 2, t2 = g2 * 2, t3 = 0;
                    t1 += (i + k - j - l);
                    t2 += (i + l - j - k);
                    if (t1 <= -2 || t2 <= -2) {
                        continue;
                    }
                    if (t1 >= 2) {
                        t1 = 2;
                    }
                    if (t2 >= 2) {
                        t2 = 2;
                    }
                    if (i == e0) t3 |= (1<<0);
                    if (j == e1) t3 |= (1<<1);
                    if (k == e2) t3 |= (1<<2);
                    if (l == e3) t3 |= (1<<3);
                    ret = (ret + dfs(pos-1, t1, t2, limit & t3) % MOD);
                }
            }
        }
    }
    return dp[pos][g1+OFF][g2+OFF][limit] = ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 4; i ++) scanf("%lld",&a[i]);
        printf("%lld\n",dfs(63, 0, 0, 15));
    }
    return 0;
}
