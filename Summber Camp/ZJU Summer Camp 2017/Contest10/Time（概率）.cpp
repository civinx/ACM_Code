#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;

const LL MOD = 1000000007ll;
const int maxn = 100000 + 100;

LL fact[maxn];

LL mul(LL x, LL y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

LL add(LL x, LL y) {
    return ((x % MOD) + (y % MOD)) % MOD;
}

LL mp(LL x, LL k) {
    LL ret = 1;
    while (k) {
        if (k & 1) ret = mul(ret, x);
        x = mul(x, x);
        k /= 2;
    }
    return ret;
}

LL inv(LL x) {
    return mp(x, MOD-2);
}

void init() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < maxn; i ++) {
        fact[i] = mul(fact[i-1], (LL)i);
    }
}

LL c(LL n, LL m) {
    LL temp = inv(mul(fact[m], fact[n-m]));
    return mul(fact[n], temp);
}

int main() {
    LL t, x;
    init();
//    printf("%lld\n",c(30, 10));
    while (scanf("%lld%lld",&t,&x) == 2) {
        if (x < 0) x = -x;
        LL res = 0;
        for (LL i = 0; i <= t; i ++) {
//            LL step = t - i;
//            if (x % 2 != step % 2) continue;
            if ((t - i + x) % 2) continue;
            if ((t - i + x) < 0) continue;
            if ((t - i + x)/2 > t - i) continue;
            LL c1 = c(t, i);
            LL c2 = c(t-i, (t-i+x)/2);
            LL c3 = inv(mp(2, i));
            LL c4 = inv(mp(4, t-i));
            LL temp = mul(mul(c1, c2), mul(c3, c4));
            res = add(res, temp);
        }
        printf("%lld\n",res);
    }
    return 0;
}