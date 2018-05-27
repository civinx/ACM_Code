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

const int maxn = 1000000 + 100;
const LL MOD = 998244353;

LL a[maxn];
bool isp[maxn<<2];
int sz;
LL p[maxn];
LL pcnt = 0;
LL an[maxn];


LL add(LL x, LL y) {
    return ((x % MOD) + (y % MOD)) % MOD;
}

LL mul(LL x, LL y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

void init(int n) {
    pcnt = 0;
    memset(isp, 0, sizeof(isp));
    isp[0] = isp[1] = 0;
    for (int i = 2; i < n; i ++ ) {
        if (!isp[i]) {
            p[pcnt++] = i;
        }
        for (int j = 0; j < pcnt && i * p[j] < n; j ++) {
            isp[i*p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

int main() {
    init(maxn);
    int T; scanf("%d",&T);
    while (T--) {
        LL l, r, k; scanf("%lld%lld%lld",&l,&r,&k);
        LL len = r-l+1;
        for (LL i = 1; i <= len; i ++) {
            a[i] = i + l - 1;
            an[i] = 1;
        }
        
        for (LL i = 0; i < pcnt; i ++) {
            LL left = ((l-1) / p[i]+1) * p[i];
            for (LL j = left; j <= r; j += p[i]) {
                LL sum = 0;
                while (a[j-l+1] % p[i] == 0) {
                    sum ++;
                    a[j-l+1] /= p[i];
                }
                an[j-l+1] = mul(an[j-l+1], mul(sum, k)+1);
            }
        }
        for (int i = 1; i <= len; i ++) {
            if (a[i] != 1) {
                an[i] = mul(an[i], (k+1)%MOD);
            }
        }
        LL res = 0;
        for (int i = 1; i <= len; i ++) {
            res = add(res, an[i]);
        }
        printf("%lld\n",res % MOD);
    }
    return 0;
}