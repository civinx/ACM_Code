#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long LL;

LL MOD;

LL mul(LL x, LL y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

LL mp(LL x, LL n) {
    LL ret = 1;
    while (n) {
        if (n & 1) ret = mul(ret, x);
        x = mul(x, x);
        n /= 2;
    }
    return ret;
}

const int maxn = 100000 + 100;

bool isp[maxn];

void solve(LL n) {
    if (n == 1) {
        printf("1\nYES\n1\n");
        return;
    }
    if (n == 4) {
        printf("4\nYES\n1\n3\n2\n4\n");
        return;
    }
    if (!isp[n]) {
        printf("%lld\nNO\n",n);
        return;
    }
    printf("%lld\n",n);
    printf("YES\n");
    printf("1\n");
    LL g = 1;
    for (int i = 2; i < n; i ++) {
        LL temp = mul(i, mp(g, n-2));
        g = mul(g, temp);
        printf("%lld\n",temp);
        
    }
    printf("%lld\n",n);
}

void init() {
    for (int i = 0; i < maxn; i ++) isp[i] = 1;
    isp[1] = 0;
    for (LL i = 2; i < maxn; i ++) {
        if (isp[i]) {
            for (LL j = i * i; j < maxn; j += i) {
                isp[j] = 0;
            }
        }
    }
}

int main() {
    init();
    LL n;
    while (scanf("%lld",&n) == 1) {
        MOD = n;
        solve(n);
    }
    return 0;
}
