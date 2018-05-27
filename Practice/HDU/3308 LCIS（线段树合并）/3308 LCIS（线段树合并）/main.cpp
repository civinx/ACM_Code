//
//  main.cpp
//  3308 LCIS（线段树合并）
//
//  Created by czf on 16/9/2.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int N = 100000 + 100;
int sum[N<<2], lsum[N<<2], rsum[N<<2], lv[N<<2], rv[N<<2];

void pushup(int rt, int len) {
    lv[rt] = lv[rt<<1];
    rv[rt] = rv[rt<<1|1];
    
    lsum[rt] = lsum[rt<<1];
    rsum[rt] = rsum[rt<<1|1];
    if (lsum[rt] == len - (len>>1) && rv[rt<<1] < lv[rt<<1|1]) lsum[rt] += lsum[rt<<1|1];
    if (rsum[rt] == (len >> 1) && rv[rt<<1] < lv[rt<<1|1]) rsum[rt] += rsum[rt<<1];
    
    sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
    if (rv[rt<<1] < lv[rt<<1|1]) sum[rt] = max(sum[rt], rsum[rt<<1] + lsum[rt<<1|1]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        int x; scanf("%d",&x);
        lv[rt] = rv[rt] = x;
        sum[rt] = lsum[rt] = rsum[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt, r-l+1);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int left = 0, right = 0;
    if (L <= m) left = query(L, R, lson);
    if (R > m) right = query(L, R ,rson);
    int ret = max(left, right);
    if (rv[rt<<1] < lv[rt<<1|1]) ret = max(ret, min(rsum[rt<<1], m-L+1) + min(lsum[rt<<1|1], R-m));
    return ret;
}

void update(int p, int x, int l, int r, int rt) {
    if (l == r) {
        lv[rt] = rv[rt] = x;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, x, lson);
    else update(p, x, rson);
    pushup(rt, r-l+1);
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n, m; scanf("%d%d",&n,&m);
        build(0, n-1, 1);
        while (m--) {
            char op[2]; int a, b;
            scanf("%s%d%d",op,&a,&b);
            if (op[0] == 'Q') {
                printf("%d\n",query(a, b, 0, n-1, 1));
            } else {
                update(a, b, 0, n-1, 1);
            }
        }
    }
    return 0;
}