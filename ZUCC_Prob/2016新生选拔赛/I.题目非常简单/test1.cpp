#include <cstdio>
typedef long long LL;
const LL MOD = 100000007;

inline LL mul(LL a, LL b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

LL qp(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = mul(ret, a);
        b >>= 1;
        a = mul(a, a);
    }
    return ret;
}

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        LL n, m, res = 0; scanf("%lld%lld",&n,&m);
        for (LL i = 1; i <= n; i ++) {
            LL t1 = qp(i, m+1), t2 = (m + 1 - mul(m, i) + MOD) % MOD;
            res = (res + (i - mul(t1, t2) + MOD) % MOD) % MOD;
        }
        printf("Case #%d: %lld\n",++kase,res);
    }
    return 0;
}
