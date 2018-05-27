//
//  main.cpp
//  1394 Minimum Inversion Number(树状数组)
//
//  Created by czf on 16/8/26.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5000 + 100;
int c[maxn],x [maxn], n;

inline int lowbit(int x) {
    return x & (-x);
}

int sum(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ret += c[i];
    }
    return ret;
}

void add(int x) {
    for (int i = x; i <= n; i += lowbit(i)) {
        c[i] += 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        int s = 0;
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i ++) {
            cin >> x[i]; x[i] ++;
            s += i - sum(x[i]);
            add(x[i]);
        }
        int res = s;
        for (int i = 0; i < n; i ++) {
            int ans = x[i] - 1;
            s = s - ans + (n - 1 - ans);
            res = min(res, s);
        }
        cout << res << '\n';
    }
    return 0;
}
