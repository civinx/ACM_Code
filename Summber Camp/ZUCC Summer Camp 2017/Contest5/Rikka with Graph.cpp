#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef long long LL;

LL solve1(LL n, LL m) {
    LL ret = 0;
    for (LL i = 0; i < m; i ++) {
        ret += 2ll * ((n - 1) + i * (n - 2));
    }
    return ret;
}

LL solve2(LL n, LL m) {
    LL ret = solve1(n, n-1);
    m -= n - 1;
    ret += 2ll * m;
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        LL n, m; scanf("%lld%lld",&n,&m);
        if (m >= n * (n-1) / 2ll) {
            printf("%lld\n",n*(n-1));
            continue;
        }
        LL res = n * (n - 1) * n;
        if (m <= n - 1) {
            res -= solve1(n, m);
        } else {
            res -= solve2(n, m);
        }
        printf("%lld\n",res);
    }
    return 0;
}