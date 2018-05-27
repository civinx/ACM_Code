//
//  main.cpp
//  Problem : Team Formation
//
//  Created by czf on 16/4/18.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 50;
const int maxn1 = 100 + 100000;
typedef long long ll;
ll bit[maxn], cur[maxn];
ll a[maxn1];

ll solve(ll x) {
    int cnt = 0, maxx = -1;
    ll ret = 0;
    while (x) {
        int m = x % 2;
        cur[cnt] = m;
        if (m) maxx = cnt;
        cnt ++;
        x /= 2;
    }
    for (int i = 0; i < cnt; i ++) {
        if (cur[i] == 0) ret += bit[i];
    }
    bit[maxx] ++;
    return ret;
}
int main() {
    int t; scanf("%d",&t);
    while (t--) {
        memset(bit, 0, sizeof(bit));
        memset(a, 0, sizeof(a));
        int n; scanf("%d",&n);
        for (int i = 0; i < n; i ++) scanf("%lld",&a[i]);
        std::sort(a, a + n);
        ll res = 0;
        for (int i = 0; i < n; i ++) {
            res += solve(a[i]);
        }
        printf("%lld\n",res);
    }
    return 0;
}