//
//  main.cpp
//  5935 Car 贪心 分数
//
//  Created by czf on 2016/10/31.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 100;
LL temp[MAXN], a[MAXN];

struct F {
    LL fz, fm;
    F & operator = (const F &rhs) {
        fz = rhs.fz;
        fm = rhs.fm;
        return *this;
    }
    F operator / (const F &rhs) const {
        F ret;
        ret.fz = fz * rhs.fm;
        ret.fm = fm * rhs.fz;
        LL temp = __gcd(ret.fz, ret.fm);
        ret.fz /= temp;
        ret.fm /= temp;
        return ret;
    }
    LL getv() {
        return fz / fm;
    }
    bool check() {
        return fz % fm;
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    int t, kase = 0; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i ++) cin >> temp[i];
        for (int i = 1; i <= n; i ++) a[i] = temp[i] - temp[i-1];
        F v{a[n], 1}; LL res = 1;
        for (int i = n-1; i >= 1; i --) {
            F dist = {a[i], 1};
            F tim = dist / v;
            if (tim.check()) tim.fz += tim.fm;
            res += tim.getv();
            F temp = {tim.getv(), 1};
            v = dist / temp;
        }
        cout << "Case #" << ++kase << ": " << res << '\n';
    }
    return 0;
}
