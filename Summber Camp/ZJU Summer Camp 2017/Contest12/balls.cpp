//
//  main.cpp
//  E
//
//  Created by czf on 2016/12/24.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

const int maxn = 500 + 100;

LL a[maxn];

bool check(LL sum, LL sx) {
    return sum / sx >= sum % sx;
}

LL solve(LL x, int n) {
    LL ret = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] % x == 0) {
            ret += a[i] / x;
        } else if (a[i] / x + a[i] % x >= x - 1) {
            ret += a[i] / x + 1;
        } else {
            return 0;
        }
    }
    return ret;
}

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        for (int i = 0; i < n; i ++) {
            scanf("%lld",&a[i]);
        }
        sort(a, a+n);
        LL res = 0;
        for (int i = 1; i <= a[0]; i ++) {
            res = solve(a[0] / i + 1, n);
            if (res) break;
            res = solve(a[0] / i, n);
            if (res) break;
            res = solve(a[0] - 1, n);
            if (res) break;
        }
        printf("%lld\n",res);
    }
    return 0;
}