//
//  main.cpp
//  1588: 目标是成为第一水题
//
//  Created by czf on 2017/3/6.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1

using namespace std;

const int maxn = 1000000 + 100;
const int INF = 0x3f3f3f3f;

int a[maxn<<2];

void pushup(int rt) {
    a[rt] = min(a[ls], a[rs]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d",&a[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int pos, int x, int l, int r, int rt) {
    if (l == r) {
        a[rt] = x;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m) update(pos, x, lson);
    else update(pos, x, rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return a[rt];
    }
    int ret = INF;
    int m = (l + r) >> 1;
    if (L <= m) ret = min(ret, query(L, R, lson));
    if (R > m) ret = min(ret, query(L, R, rson));
    return ret;
}

int main() {
    int n, m;
    while (scanf("%d%d",&n,&m) == 2) {
        memset(a, INF, sizeof(a));
        build(1, n, 1);
        for (int i = 0; i < m; i ++) {
            char c = '\0'; while (!isalpha(c)) c = cin.get();
            int L, R; scanf("%d%d",&L,&R);
            if (c == 'Q') printf("%d\n",query(L, R, 1, n, 1));
            else update(L, R, 1, n, 1);
        }
    }
    return 0;
}
