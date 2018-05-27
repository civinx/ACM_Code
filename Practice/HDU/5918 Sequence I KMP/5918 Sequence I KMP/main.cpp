//
//  main.cpp
//  5918 Sequence I KMP
//
//  Created by czf on 2016/10/17.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>

const int MAXN = 1000000 + 100;
int a[MAXN], b[MAXN], f[MAXN], n, m, p;
bool vis[MAXN];

void getFail() {
    memset(f, 0, sizeof(f));
    f[0] = f[1] = 0;
    for (int i = 1; i < m; i += 1) {
        int j = f[i];
        while (j && b[i] != b[j]) j = f[j];
        f[i+1] = b[i] == b[j] ? j+1: 0;
    }
}

int kmp() {
    getFail();
    memset(vis, 0, sizeof(vis));
    int cnt = 0, j = 0;
    for (int s = 0; s + (m-1) * p < n; s ++) {
        if (vis[s]) continue;
        j = 0;
        for (int i = s; i < n; i += p) {
            vis[i] = 1;
            while (j && a[i] != b[j]) j = f[j];
            if (a[i] == b[j]) j ++;
            if (j == m) {
                cnt ++;
                j = f[j];
            }
        }
    }
    return cnt;
}

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&m,&p);
        for (int i = 0; i < n; i ++) scanf("%d",&a[i]);
        for (int i = 0; i < m; i ++) scanf("%d",&b[i]);
        printf("Case #%d: %d\n",++kase, kmp());
    }
    return 0;
}
