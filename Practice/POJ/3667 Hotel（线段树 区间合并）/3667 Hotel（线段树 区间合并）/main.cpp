//
//  main.cpp
//  3667 Hotel（线段树 区间合并）
//
//  Created by czf on 16/9/1.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int N = 50000 + 100;
int col[N<<2], sum[N<<2], lsum[N<<2], rsum[N<<2];

void build(int l, int r, int rt) {
    col[rt] = -1;
    sum[rt] = lsum[rt] = rsum[rt] = r - l + 1;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void pushdown(int rt, int len) {
    if (col[rt] != -1) {
        sum[rt<<1] = lsum[rt<<1] = rsum[rt<<1] = (len - (len >> 1)) * col[rt];
        sum[rt<<1|1] = lsum[rt<<1|1] = rsum[rt<<1|1] = (len >> 1) * col[rt];
        col[rt<<1] = col[rt<<1|1] = col[rt];
        col[rt] = -1;
        return;
    }
}

void pushup(int rt, int len) {
    sum[rt] = max(max(sum[rt<<1], sum[rt<<1|1]), rsum[rt<<1]+lsum[rt<<1|1]);
    lsum[rt] = lsum[rt<<1];
    if (lsum[rt] == len - (len>>1)) lsum[rt] += lsum[rt<<1|1];
    rsum[rt] = rsum[rt<<1|1];
    if (rsum[rt] == (len>>1)) rsum[rt] += rsum[rt<<1];
}

void update(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        col[rt] = x;
        sum[rt] = lsum[rt] = rsum[rt] = (r - l + 1) * col[rt];
        return;
    }
    pushdown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, x, lson);
    if (R > m) update(L, R, x, rson);
    pushup(rt, r-l+1);
}

int query(int x, int l, int r, int rt) {
    if (l == r) return l;
    pushdown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (sum[rt<<1] >= x) return query(x, lson);
    else if (rsum[rt<<1] + lsum[rt<<1|1] >= x) return m - rsum[rt<<1] + 1;
    return query(x, rson);
}

int main() {
    int n, m;
    while (~scanf("%d%d",&n,&m)) {
        build(1, n, 1);
        while (m--) {
            int op; scanf("%d",&op);
            if (op == 1) {
                int x; scanf("%d",&x);
                if (sum[1] < x) puts("0");
                else {
                    int p = query(x, 1, n, 1);
                    printf("%d\n",p);
                    update(p, p+x-1, 0, 1, n, 1);
                }
            } else {
                int L, R; scanf("%d%d",&L,&R);
                R = L + R - 1;
                update(L, R, 1, 1, n, 1);
            }
        }
    }
    return 0;
}