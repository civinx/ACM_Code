//
//  main.cpp
//  Problem : Flyer
//
//  Created by czf on 16/4/27.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 20000 + 100;
ll a[maxn], b[maxn], c[maxn];

ll solve(ll mid, int n) {
    ll ret = 0;
    for (int i = 0; i < n; i ++) {
        ll k = min(b[i], mid);
        if (k >= a[i])
            ret += (k - a[i]) / c[i] + 1;
    }
    return ret;
}

int main() {
    int n;
    while (~scanf("%d",&n)) {
        for (int i = 0; i < n; i ++)
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        ll l = 1, r = 1ll << 31;
        while (l < r) {
            ll mid = (l + r) / 2;
            if (solve(mid, n) % 2) r = mid;
            else l = mid + 1;
        }
        if (l == 1ll << 31) printf("DC Qiang is unhappy.\n");
        else {
            printf("%lld %lld\n",l,solve(l,n)-solve(l-1,n));
        }
    }
    return 0;
}