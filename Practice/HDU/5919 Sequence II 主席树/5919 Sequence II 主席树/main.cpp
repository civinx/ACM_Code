//
//  main.cpp
//  5919 Sequence II 主席树
//
//  Created by czf on 2016/10/29.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 2 * 1e5 + 100;
int a[MAXN], p[MAXN], root[MAXN], cnt;

struct {int l, r, sum;} T[MAXN * 40];

void init() {
    cnt = 0;
    memset(p, 0, sizeof(p));
    memset(root, 0, sizeof(root));
}

void update(int l, int r, int &cur, int pre, int pos, int v) {
    cur = ++cnt; T[cur] = T[pre]; T[cur].sum += v;
    if (l == r) return;
    int m = (l + r) >> 1;
    if (pos <= m)
        update(l, m, T[cur].l, T[pre].l, pos, v);
    else
        update(m+1, r, T[cur].r, T[pre].r, pos, v);
}

int getsum(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return T[rt].sum;
    }
    int ret = 0;
    int m = (l + r) >> 1;
    if (L <= m) ret += getsum(L, R, l, m, T[rt].l);
    if (R > m) ret += getsum(L, R, m+1, r, T[rt].r);
    return ret;
}

int query(int l, int r, int rt, int k) {
    if (l == r) {
        return l;
    }
    int m = (l + r) >> 1;
    if (T[T[rt].l].sum >= k)
        return query(l, m, T[rt].l, k);
    else
        return query(m+1, r, T[rt].r, k - T[T[rt].l].sum);
}

int main() {
    int t, kase = 0; scanf("%d",&t);
    while (t--) {
        init();
        int n, m; scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i ++) scanf("%d",&a[i]);
        for (int i = n; i >= 1; i --) {
            if (p[a[i]]) {
                update(1, n, root[i], root[i+1], p[a[i]], -1);
                update(1, n, root[i], root[i], i, 1);
            } else {
                update(1, n, root[i], root[i+1], i, 1);
            }
            p[a[i]] = i;
        }
        int ans = 0;
        printf("Case #%d:",++kase);
        while (m--) {
            int L, R; scanf("%d%d",&L,&R);
            L = (L + ans) % n + 1;
            R = (R + ans) % n + 1;
            if (L > R) swap(L, R);
            int sum = getsum(L, R, 1, n, root[L]);
            sum = (sum + 1) >> 1;
            ans = query(1, n, root[L], sum);
            printf(" %d",ans);
        }
        printf("\n");
    }
    return 0;
}
