//
//  main.cpp
//  1394 Minimum Inversion Number(线段树)
//
//  Created by czf on 16/8/26.
//  Copyright © 2016年 czf. All rights reserved.
//

//
//  main.cpp
//  1394 Minimum Inversion Number(线段树)
//
//  Created by czf on 16/8/26.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
using namespace std;
const int maxn = 5000 + 100;

int sum[maxn<<2], x[maxn];

void build(int l, int r, int rt) {
    sum[rt] = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return sum[rt];
    int ret = 0, m = (l + r) >> 1;
    if (L <= m) ret += query(L, R, lson);
    if (R > m) ret += query(L, R, rson);
    return ret;
}

void pushup(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void update(int p, int l, int r, int rt) {
    if (l == r) {
        sum[rt] ++;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, lson);
    else update(p, rson);
    pushup(rt);
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        int sum = 0;
        build(0, n-1, 1);
        for (int i = 0; i < n; i ++) {
            cin >> x[i];
            sum += query(x[i]+1, n-1, 0, n-1, 1);
            update(x[i], 0, n-1, 1);
        }
        int res = sum;
        for (int i = 0; i < n; i ++) {
            sum = sum - x[i] + (n - 1 - x[i]);
            res = min(sum, res);
        }
        cout << res << '\n';
    }
    return 0;
}
