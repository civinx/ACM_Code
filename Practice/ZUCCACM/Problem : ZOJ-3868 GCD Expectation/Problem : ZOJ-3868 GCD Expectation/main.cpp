//
//  main.cpp
//  Problem : ZOJ-3868 GCD Expectation
//
//  Created by czf on 16/4/9.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 2000000 + 100;
//const int maxn = 100;
const ll mod = 998244353;
ll f[maxn]; //f[i]代表gcd为i的集合的个数
ll a[maxn]; //a[i],代表为i的数字有几个

ll mypow(ll a, ll n) {
    ll base = a, ret = 1;
    while (n) {
        if (n & 1) ret = (ret % mod * base % mod) % mod;
        base = (base % mod * base % mod) % mod;
        n >>= 1;
    }
    return ret;
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        ll n, k; scanf("%lld%lld",&n,&k);
        ll top = 0;
        ll res = 0;
        for (int i = 0; i < n; i ++) {
            ll x; scanf("%lld",&x);
            a[x] ++;
            top = max(top, x);
        }
        for (ll i = top; i >= 1; -- i) {
            ll cnt = 0;
            ll item = 0;
            for (ll j = i; j <= top; j += i) cnt += a[j];
            item += mypow(2, (ll)cnt) - 1;
            for (ll j = i + i; j <= top; j += i) item = (mod + item - f[j]) % mod;
            f[i] = item;
        }
        for (ll i = 1; i <= top; i ++) {
            res = (res + (mypow(i, k) % mod * f[i] % mod) % mod) % mod;
        }
        printf("%lld\n",res);
    }
    return 0;
}

