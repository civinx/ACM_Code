//
//  main.cpp
//  5742 It's All In The Mind
//
//  Created by czf on 2017/4/20.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 111;

bool vis[maxn];
int a[maxn];

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        memset(vis, 0, sizeof(vis));
        int n, m; scanf("%d%d",&n,&m);
        for (int i = 0; i < m; i ++) {
            int pos, x; scanf("%d%d",&pos,&x);
            vis[pos] = 1;
            a[pos] = x;
        }
        a[0] = 100;
        for (int i = 1; i <= n; i ++) {
            if (!vis[i]) {
                a[i] = min(100, a[i-1]);
            }
        }
        a[n+1] = 0;
        for (int i = n; i > 2; i --) {
            if (!vis[i]) {
                a[i] = max(0, a[i+1]);
            }
        }
        int p = 0, q = 0;
        for (int i = 1; i <= n; i ++) q += a[i];
        p = a[1] + a[2];
        if (p && q) {
            int g = __gcd(p, q);
            p /= g;
            q /= g;
        }
        printf("%d/%d\n",p,q);
    }
    return 0;
}
