//
//  main.cpp
//  1436 Horizontally Visible Segments（线段树成段更新）
//
//  Created by czf on 16/8/30.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
const int N = 8000 + 100;
const int M = 10000 * 2;

int c[M<<2], p[N], x[N], y1[N], y2[N];
bool vis[N][N];

void init() {
    for (int i = 0; i < N; i ++) p[i] = i;
    memset(c, 0, sizeof(c));
    memset(vis, 0, sizeof(vis));
}

bool cmp(const int &i, const int &j) {
    return x[i] < x[j];
}

void pushdown(int rt) {
    if (c[rt] != -1) {
        c[rt<<1] = c[rt<<1|1] = c[rt];
        c[rt] = -1;
    }
}

void update(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        c[rt] = x;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, x, lson);
    if (R > m) update(L, R, x, rson);
}

void query(int L, int R, int x, int l, int r, int rt) {
    if (c[rt] != 0 && c[rt] != -1) {
        vis[x][c[rt]] = 1;
        return;
    }
    if (l == r) return;
    int m = (l + r) >> 1;
    if (L <= m) query(L, R, x, lson);
    if (R > m) query(L, R, x, rson);
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        init();
        int n; scanf("%d",&n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d%d%d",&y1[i],&y2[i],&x[i]);
            y1[i] *= 2; y2[i] *= 2;
        }
        sort(p+1, p+1+n, cmp);
        for (int i = 1; i <= n; i ++) {
            int idx = p[i];
            query(y1[idx], y2[idx], i, 0, M, 1);
            update(y1[idx], y2[idx], i, 0, M, 1);
        }
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (!vis[i][j]) continue;
                for (int k = 1; k <= n; k ++) {
                    if (vis[i][k] && vis[j][k]) res ++;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}