//
//  main.cpp
//  5828 Rikka with Sequence（线段树 区间开根号）
//
//  Created by czf on 16/9/3.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define ls rt<<1
#define rs rt<<1|1
const int N = 100000 + 100;
typedef long long LL;

LL sum[N<<2], add[N<<2], mx[N<<2], mn[N<<2];

void pushup(int rt) {
    sum[rt] = sum[ls] + sum[rs];
    mx[rt] = max(mx[ls], mx[rs]);
    mn[rt] = min(mn[ls], mn[rs]);
}

void build(int l, int r, int rt) {
    add[rt] = 0;
    if (l == r) {
        LL x; scanf("%lld",&x);
        sum[rt] = mn[rt] = mx[rt] = x;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void pushdown(int rt, int len) {
    if (add[rt]) {
        mx[ls] += add[rt];
        mn[ls] += add[rt];
        mx[rs] += add[rt];
        mn[rs] += add[rt];
        sum[ls] += (len - (len>>1)) * (LL)add[rt];
        sum[rs] += (len >> 1) * (LL)add[rt];
        add[ls] += add[rt];
        add[rs] += add[rt];
        add[rt] = 0;
    }
}

void Add(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        add[rt] += x;
        mx[rt] += x;
        mn[rt] += x;
        sum[rt] += (LL)x * (r-l+1);
        return;
    }
    pushdown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) Add(L, R, x, lson);
    if (R > m) Add(L, R, x, rson);
    pushup(rt);
}

void Sqrt(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        if (mx[rt] - mn[rt] == 0) {
            LL x = mx[rt] - (LL)floor(sqrt(mx[rt]));
            sum[rt] -= (LL)x * (r-l+1);
            mx[rt] -= x;
            mn[rt] -= x;
            add[rt] -= x;
            return;
        } else if (mx[rt] - mn[rt] == 1) {
            LL t1 = (LL)floor(sqrt(mx[rt]));
            LL t2 = (LL)floor(sqrt(mn[rt]));
            if (t1 - t2 == 1) {
                LL x = mx[rt] - (LL)floor(sqrt(mx[rt]));
                sum[rt] -= (LL)x * (r-l+1);
                add[rt] -= x;
                mx[rt] = t1;
                mn[rt] = t2;
                return;
            }
        }
    }
    pushdown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) Sqrt(L, R, lson);
    if (R > m) Sqrt(L, R, rson);
    pushup(rt);
}

LL Query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    pushdown(rt, r-l+1);
    int m = (l + r) >> 1;
    LL ret = 0;
    if (L <= m) ret += Query(L, R, lson);
    if (R > m) ret += Query(L, R, rson);
    return ret;
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n, m; scanf("%d%d",&n,&m);
        build(1, n, 1);
        while (m--) {
            int op, L, R, x;
            scanf("%d%d%d",&op,&L,&R);
            if (op == 1) {
                scanf("%d",&x);
                Add(L, R, x, 1, n, 1);
            } else if (op == 2) {
                Sqrt(L, R, 1, n, 1);
            } else {
                printf("%lld\n",Query(L, R, 1, n, 1));
            }
        }
    }
    return 0;
}