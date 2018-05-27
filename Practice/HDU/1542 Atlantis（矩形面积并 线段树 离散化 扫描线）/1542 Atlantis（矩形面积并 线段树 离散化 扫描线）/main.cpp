//
//  main.cpp
//  1542 Atlantis（矩形面积并 线段树 离散化 扫描线）
//
//  Created by czf on 16/9/3.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define ls rt<<1
#define rs rt<<1|1
const int N = 200 + 10;
int col[N<<2];
double mp[N], sum[N<<2];

struct Seg {
    double l, r, h;
    int s;
    Seg() {}
    Seg(double l, double r, double h, int s) : l(l), r(r), h(h), s(s) {}
    bool operator < (const Seg &rhs) const {
        return h < rhs.h;
    }
}seg[N];

int bs(int l, int r, double x) {
    while (l <= r) {
        int m = (l + r) >> 1;
        if (mp[m] == x) return m;
        if (mp[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

void pushup(int rt, int l, int r) {
    if (col[rt]) sum[rt] = mp[r+1] - mp[l];
    else if (l == r) sum[rt] = 0;
    else sum[rt] = sum[ls] + sum[rs];
}

void update(int L, int R, int v, int l, int r, int rt) {
    if (L <= l && r <= R) {
        col[rt] += v;
        pushup(rt, l, r);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, v, lson);
    if (R > m) update(L, R, v, rson);
    pushup(rt, l, r);
}

int main() {
    int n, kase = 0;
    while (scanf("%d",&n) && n) {
        int m = 0;
        memset(sum, 0, sizeof(sum));
        memset(col, 0, sizeof(col));
        for (int i = 0; i < n; i ++) {
            double x1, y1, x2, y2; scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            seg[m] = Seg{x1, x2, y1, 1};
            mp[m++] = x1;
            seg[m] = Seg{x1, x2, y2, -1};
            mp[m++] = x2;
        }
        sort(mp, mp+m);
        int k = (int)(unique(mp, mp+m) - mp);
        sort(seg, seg+m);
        double res = 0;
        for (int i = 0; i < m-1; i ++) {
            int L = bs(0, k-1, seg[i].l);
            int R = bs(0, k-1, seg[i].r) - 1;
            if (L <= R) update(L, R, seg[i].s, 0, k-1, 1);
            res += sum[1] * (seg[i+1].h - seg[i].h);
        }
        printf("Test case #%d\n",++kase);
        printf("Total explored area: %.2f\n\n", res);
    }
    return 0;
}
