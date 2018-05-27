//
//  main.cpp
//  2991 Crane（线段树成段更新 向量旋转）
//
//  Created by czf on 16/8/30.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cmath>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
const int maxn = 10000 + 100;

int c[maxn<<2], d[maxn];
double x[maxn<<2], y[maxn<<2];

void pushup(int rt) {
    x[rt] = x[rt<<1] + x[rt<<1|1];
    y[rt] = y[rt<<1] + y[rt<<1|1];
}

void build(int l, int r, int rt) {
    c[rt] = x[rt] = y[rt] = 0;
    if (l == r) {
        scanf("%lf",&y[rt]);
        d[l] = 180;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void rotate(int rt, int dg) {
    double sita = dg * acos(-1.0) / 180;
    double tempx = x[rt] * cos(sita) - y[rt] * sin(sita);
    double tempy = y[rt] * cos(sita) + x[rt] * sin(sita);
    x[rt] = tempx;
    y[rt] = tempy;
}

void pushdown(int rt) {
    if (c[rt]) {
        c[rt<<1] += c[rt];
        c[rt<<1|1] += c[rt];
        rotate(rt<<1, c[rt]);
        rotate(rt<<1|1, c[rt]);
        c[rt] = 0;
    }
}

void update(int L, int R, int dg, int l, int r, int rt) {
    if (L <= l && r <= R) {
        c[rt] += dg;
        rotate(rt, dg);
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, dg, lson);
    if (R > m) update(L, R, dg, rson);
    pushup(rt);
}

int main() {
    int n, m; bool flag = 0;
    while (~scanf("%d%d",&n,&m)) {
        flag ? printf("\n") : (flag = 1);
        build(1, n, 1);
        while (m--) {
            int xx, dg; scanf("%d%d",&xx,&dg);
            update(xx+1, n, dg - d[xx+1], 1, n, 1);
            d[xx+1] = dg;
            printf("%.2f %.2f\n",x[1],y[1]);
        }
    }
    return 0;
}
