//
//  main.cpp
//  5861 Road 线段树
//
//  Created by czf on 2017/4/14.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1

#define ls rt << 1
#define rs rt << 1 | 1

using namespace std;

typedef long long LL;
const int maxn = 200000 + 100;
//const int maxn = 10;
const int INF = 0x3f3f3f3f;

int road_val[maxn], mi[maxn<<2], mx[maxn<<2], lazy[maxn<<2];
vector<int> START[maxn], END[maxn];

void pushup(int rt) {
    mx[rt] = max(mx[ls], mx[rs]);
    mi[rt] = min(mi[ls], mi[rs]);
}

void build(int l, int r, int rt) {
    mi[rt] = INF;
    mx[rt] = -INF;
    lazy[rt] = 0;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void pushdown(int rt) {
    if (lazy[rt]) {
        lazy[ls] = lazy[rs] = lazy[rt];
        mx[ls] = max(mx[ls], lazy[rt]);
        mx[rs] = max(mx[rs], lazy[rt]);
        mi[ls] = min(mi[ls], lazy[rt]);
        mi[rs] = min(mi[rs], lazy[rt]);
        lazy[rt] = 0;
    }
}
void update(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        mx[rt] = max(mx[rt], x);
        mi[rt] = min(mi[rt], x);
        lazy[rt] = x;
        return;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, x, lson);
    if (R > mid) update(L, R, x, rson);
    pushup(rt);
}

void query(int l, int r, int rt) {
    if (l == r) {
        if (mi[rt] != INF) {
            START[mi[rt]].push_back(road_val[l]);
            END[mx[rt]].push_back(road_val[l]);
        }
        return;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    query(lson);
    query(rson);
}

void init(int m) {
    for (int i = 0; i <= m; i ++) {
        START[i].clear();
        END[i].clear();
    }
}

int main() {
    int n, m;
    while (scanf("%d%d",&n,&m) == 2) {
        init(m);
        for (int i = 1; i < n; i ++) {
            scanf("%d",&road_val[i]);
        }
        build(1, n-1, 1);
        for (int i = 1; i <= m; i ++) {
            int L, R; scanf("%d%d",&L,&R);
            if (L > R) swap(L, R);
            update(L, R-1, i, 1, n-1, 1);
        }
        query(1, n-1, 1);
        int sum = 0;
        for (int i = 1; i <= m; i ++) {
            for (int j = 0; j < START[i].size(); j ++) {
                sum += START[i][j];
            }
            printf("%d\n",sum);
            for (int j = 0; j < END[i].size(); j ++) {
                sum -= END[i][j];
            }
        }
    }
    return 0;
}
