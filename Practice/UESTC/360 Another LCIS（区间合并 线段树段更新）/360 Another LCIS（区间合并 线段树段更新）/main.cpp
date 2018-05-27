//
//  main.cpp
//  360 Another LCIS（区间合并 线段树段更新）
//
//  Created by czf on 16/8/31.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int maxn = (100000 + 100) << 2;

int sum[maxn], lsum[maxn], rsum[maxn];
int lv[maxn], rv[maxn], add[maxn];

void pushup(int rt, int len) {
    lsum[rt] = lsum[rt<<1];
    lv[rt] = lv[rt<<1];
    if (lsum[rt] == len - (len>>1) && rv[rt<<1] < lv[rt<<1|1]) lsum[rt] += lsum[rt<<1|1];
    
    rsum[rt] = rsum[rt<<1|1];
    rv[rt] = rv[rt<<1|1];
    if (rsum[rt] == (len >> 1) && rv[rt<<1] < lv[rt<<1|1]) rsum[rt] += rsum[rt<<1];
    
    if (rv[rt<<1] < lv[rt<<1|1]) {
        sum[rt] = max(max(sum[rt<<1], sum[rt<<1|1]), rsum[rt<<1]+lsum[rt<<1|1]);
    } else {
        sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
    }
}

void build(int l, int r, int rt) {
    add[rt] = 0;
    if (l == r) {
        lsum[rt] = rsum[rt] = sum[rt] = 1;
        int x; scanf("%d",&x);
        lv[rt] = rv[rt] = x;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt, r-l+1);
}

void pushdown(int rt) {
    if (add[rt]) {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        lv[rt<<1] += add[rt];
        rv[rt<<1] += add[rt];
        lv[rt<<1|1] += add[rt];
        rv[rt<<1|1] += add[rt];
        add[rt] = 0;
    }
}

void update(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        add[rt] += x;
        lv[rt] += x;
        rv[rt] += x;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, x, lson);
    if (R > m) update(L, R, x, rson);
    pushup(rt, r-l+1);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int t1 = -1, t2 = -1, t3 = -1;
    if (L <= m) t1 = query(L, R, lson);
    if (R > m) t2 = query(L, R, rson);
    if (rv[rt<<1] < lv[rt<<1|1]) t3 = min(rsum[rt<<1], m-L+1) + min(lsum[rt<<1|1], R-m);
    return max(max(t1,t2),t3);
}

int main() {
    int t, kase = 0; scanf("%d",&t);
    while (t--) {
        printf("Case #%d:\n",++kase);
        int n, m; scanf("%d%d",&n,&m);
        build(1, n, 1);
        while (m--) {
            char op[2]; scanf("%s",op);
            if (op[0] == 'q') {
                int L, R; scanf("%d%d",&L,&R);
                printf("%d\n",query(L, R, 1, n, 1));
            } else {
                int L, R, x; scanf("%d%d%d",&L,&R,&x);
                update(L, R, x, 1, n, 1);
            }
        }
    }
    return 0;
}