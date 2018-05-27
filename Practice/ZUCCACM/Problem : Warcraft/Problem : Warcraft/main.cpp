//
//  main.cpp
//  Problem : Warcraft
//
//  Created by czf on 16/5/18.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;
const int inf = 0xfffffff;
int a[maxn], b[maxn], dp[maxn][maxn];
//dp[i][j]代表第i秒结束时，j点魔法值对应的杀害boss的最大值
//dp[0][100]，代表刚开始，对应杀害boss最大值为0
//j的魔法值使用了K技能，魔法值变为min(100, j - a[k] + t)
// 如果使用了k号技能，则 dp[i][next] = max(dp[i][next], dp[i-1][j] + b[k])

bool Init() {
    for (int i = 0; i < maxn; i ++) {
        for (int j = 0; j < maxn; j ++) {
            dp[i][j] = -inf;
        }
    }
    dp[0][100] = 0, a[0] = 0, b[0] = 1;
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, t, q;
    while (cin >> n >> t >> q && (n || t || q) && Init()) {
        for (int i = 1; i <= n; i ++)
            cin >> a[i] >> b[i];
        bool flag = 0;
        int res = 0;
        for (int i = 1; (i - 1) * q < 100; i ++) {
            for (int j = 0; j <= 100; j ++) {
                for (int k = 0; k <= n; k ++) {
                    if (j < a[k]) continue;
                    int next = min(100, j - a[k] + t);
                    dp[i][next] = max(dp[i][next], dp[i-1][j] + b[k]);
                    if (dp[i][next] >= 100) {flag = 1; res = i; break;}
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag == 0) cout << "My god" << '\n';
        else cout << res << '\n';
    }
    return 0;
}

