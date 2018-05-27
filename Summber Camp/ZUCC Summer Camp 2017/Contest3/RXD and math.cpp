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

const LL MOD = 1e9 + 7;

LL mul(LL x, LL y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

LL mp(LL n, LL k) {
    LL ret = 1;
    while (k) {
        if (k & 1) ret = mul(ret, n);
        k /= 2;
        n = mul(n, n);
    }
    return ret;
}

int main() {
    LL n , k;
    int kase = 0;
    while (scanf("%lld%lld",&n,&k) == 2) {
        printf("Case #%d: %lld\n",++kase,mp(n, k) % MOD);
    }
    return 0;
}