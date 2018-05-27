//
//  main.cpp
//  1754 I Hate It(线段树 单点)
//
//  Created by czf on 16/8/13.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
const int maxn = 200000 + 100;

int MAX[maxn << 2];

void pushup(int rt) {
    MAX[rt] = max(MAX[rt<<1], MAX[rt<<1|1]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        cin >> MAX[rt];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) return MAX[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret = max(ret, query(L, R, lson));
    if (R > m) ret = max(ret, query(L, R, rson));
    return ret;
}

void update(int id, int x, int l, int r, int rt) {
    if (l == r) {
        MAX[rt] = x;
        return;
    }
    int m = (l + r) >> 1;
    if (id <= m) update(id, x, lson);
    else update(id, x, rson);
    pushup(rt);
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        build(1, n, 1);
        while (m --) {
            cin.get();
            char c; c = cin.get();
            int a, b; cin >> a >> b;
            if (c == 'Q') {
                cout << query(a, b, 1, n, 1) << '\n';
            } else if (c == 'U') {
                update(a, b, 1, n, 1);
            }
        }
    }
    return 0;
}