//
//  main.cpp
//  Saving Beans （Lucas定理）
//
//  Created by czf on 16/4/5.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
typedef long long ll;
const int maxn = 100000 + 10;

ll inv[maxn];

ll getinv(ll a, ll p) {
    ll n = p-2, ret = 1, base = a;
    while(n) {
        if (n & 1) ret = (ret % p) * (base % p) % p;
        base = (base % p) * (base % p) % p;
        n >>= 1;
    }
    return ret;
}

ll C(ll n, ll k, ll p) {
    ll up = 1, down = 1;
    if (k > n) return 0;
    for (;k ; --k, --n) {
        up = (up * n) % p;
        down = (down * k) % p;
    }
    return up * getinv(down, p) % p;
}

ll Lucas(ll n, ll k, ll p) {
    if (k == 0) return 1;
    return C(n % p, k % p, p) * Lucas(n / p, k / p, p) % p;
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        ll n, m, p; scanf("%lld%lld%lld",&n,&m,&p);
        ll res = Lucas(n+m, m, p);
        printf("%lld\n",res);
    }
    return 0;
}
