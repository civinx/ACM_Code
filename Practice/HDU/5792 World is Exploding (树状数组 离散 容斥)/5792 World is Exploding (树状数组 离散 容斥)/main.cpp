//
//  main.cpp
//  5792 World is Exploding (树状数组 离散 容斥)
//
//  Created by czf on 16/8/12.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 50000 + 100;
typedef long long ll;
int a[maxn], b[maxn], c[maxn], ls[maxn], lb[maxn], rs[maxn], rb[maxn], n;

inline int lowbit(int x) {
    return x & (-x);
}

void add(int x) {
    for (int i = x; i <= n; i += lowbit(i)) {
        c[i] += 1;
    }
}

int sum(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ret += c[i];
    }
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 1; i <= n; i ++) cin >> a[i], b[i] = a[i];
        sort(b+1, b+1+n);
        int m = unique(b+1, b+1+n) - (b+1);
        for (int i = 1; i <= n; i ++) a[i] = lower_bound(b+1, b+1+m, a[i]) - b;
        memset(c, 0, sizeof(c));
        ll inv = 0, ord = 0;
        for (int i = 1; i <= n; i ++) {
            add(a[i]);
            ls[i] = sum(a[i]-1);
            lb[i] = i - sum(a[i]);
            inv += lb[i];
            ord += ls[i];
        }
        for (int i = 1; i <= n; i ++) {
            rs[i] = sum(a[i]-1) - ls[i];
            rb[i] = n - sum(a[i]) - lb[i];
        }
        ll ans = inv * ord;
        //        cout << ans << '\n';
        for (int i = 1; i <= n; i ++) {
            ans -= lb[i]*ls[i] + lb[i]*rb[i] + ls[i]*rs[i] + rb[i]*rs[i];
        }
        cout << ans << '\n';
    }
    return 0;
}