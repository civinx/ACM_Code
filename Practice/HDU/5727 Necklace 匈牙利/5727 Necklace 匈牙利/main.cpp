//
//  main.cpp
//  5727 Necklace 匈牙利
//
//  Created by czf on 2017/4/18.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 15;

int G[maxn][maxn], a[maxn], g[maxn], n, m;
bool used[maxn];

bool check(int x, int pos) {
    int l = pos ? pos - 1 : n - 1;
    int r = pos;
    if (G[x][a[r]] == 0 && G[x][a[l]] == 0) {
        return true;
    }
    return false;
}

bool solve(int x) {
    for (int i = 0; i < n; i ++) {
        if (check(x, i) && used[i] == 0) {
            used[i] = 1;
            if (g[i] == -1 || solve(g[i])) {
                g[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    while (scanf("%d%d",&n,&m) == 2) {
        memset(G, 0, sizeof(G));
        for (int i = 0; i < m; i ++) {
            int x, y; scanf("%d%d",&x,&y);
            G[x][y] = 1;
        }
        for (int i = 0; i < n; i ++) a[i] = i + 1;
        int res = 0x3f3f3f3f;
        do {
            memset(g, -1, sizeof(g));
            int cnt = 0;
            for (int i = 1; i <= n; i ++) {
                memset(used, 0, sizeof(used));
                if (solve(i)) {
                    cnt ++;
                }
            }
            res = min(res, n - cnt);
            if (res == 0) break;
        } while(next_permutation(a, a+n));
        printf("%d\n",res);
    }
    return 0;
}
