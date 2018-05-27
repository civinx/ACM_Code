//
//  main.cpp
//  3468 A Simple Problem with Integers（线段树成段更新 成段查询）
//
//  Created by czf on 16/8/27.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
typedef long long ll;
const int maxn = 100000 + 100;

ll sum[maxn<<2], c[maxn<<2];

void pushup(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l, int r, int rt) {
    sum[rt] = 0;
    c[rt] = 0;
    if (l == r) {
        scanf("%lld",&sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void pushdown(int rt, int m) {
    if (c[rt]) {
        c[rt<<1] += c[rt];
        c[rt<<1|1] += c[rt];
        sum[rt<<1] += c[rt] * (ll)(m - (m >> 1));
        sum[rt<<1|1] += c[rt] * (ll)(m >> 1);
        c[rt] = 0;
    }
}

void update(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        c[rt] += x;
        sum[rt] += x * (ll)(r - l + 1);
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, x, lson);
    if (R > m) update(L, R, x, rson);
    pushup(rt);
}

ll query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    ll ret = 0;
    if (L <= m) ret += query(L, R, lson);
    if (R > m) ret += query(L, R, rson);
    return ret;
}

int main() {
    int n, m;
    while (~scanf("%d%d",&n,&m)) {
        build(1, n, 1);
        while (m --) {
            char cmd[2]; scanf("%s",cmd);
            if (cmd[0] == 'Q') {
                int L, R; scanf("%d%d",&L,&R);
                printf("%lld\n",query(L, R, 1, n, 1));
            } else {
                int L, R, x; scanf("%d%d%d",&L,&R,&x);
                update(L, R, x, 1, n, 1);
            }
        }
    }
    return 0;
}
