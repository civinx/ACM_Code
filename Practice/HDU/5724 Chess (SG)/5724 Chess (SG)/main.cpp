//
//  main.cpp
//  5724 Chess (SG)
//
//  Created by czf on 2017/4/14.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>

const int maxn = 20;

int SG[(1<<maxn)+100], vis[maxn];

int solve(int state) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < maxn; i ++) {
        if (state & (1 << i)) {
            for (int j = i-1; j >= 0; j --) {
                if ((state & (1 << j)) == 0) {
                    vis[SG[state ^ (1 << i) ^ (1 << j)]] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < maxn; i ++) {
        if (!vis[i]) {
            return i;
        }
    }
    return 0;
}

int main() {
    int T; scanf("%d",&T);
    memset(SG, 0, sizeof(SG));
    for (int i = 0; i < (1 << maxn); i ++) {
        SG[i] = solve(i);
    }
    while (T--) {
        int n; scanf("%d",&n);
        int res = 0;
        for (int i = 0; i < n; i ++) {
            int m; scanf("%d",&m);
            int state = 0;
            for (int j = 0; j < m; j ++) {
                int pos; scanf("%d",&pos);
                state |= (1 << (20 - pos));
            }
            res ^= SG[state];
        }
        if (res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
