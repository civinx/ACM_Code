#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define pb push_back
#define MS(x, y) memset(x, y, sizeof(x))
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
#define AS(x, L, R) assert((L) <= x && x <= (R))
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;

const int maxn = 1e4 + 1;

LL f[maxn];

LL mul(LL x, LL y) {
    return x * y % MOD;
}

void init() {
    f[0] = f[1] = 1;
    for (int i = 2; i < maxn; i ++) {
        f[i] = mul(f[i-1], i);
    }
}

LL mp(LL x, LL k) {
    LL ret = 1;
    while (k) {
        if (k & 1) ret = mul(ret, x);
        k /= 2;
        x = mul(x, x);
    }
    return ret;
}

LL inv(LL x) {
    return mp(x, MOD-2);
}

LL solve(LL n, LL k) {
    LL ret = f[n];
    ret = mul(ret, inv(f[k]));
    ret = mul(ret, inv(f[n-k]));
    return ret;
}

int main() {
    init();
    int T; cin >> T;
    AS(T, 1, 100);
    while (T--) {
        int n, k; cin >> n >> k;
        AS(k, 0, 1e4);
        AS(n, k, 1e4);
        LL res = solve(n, k);
        AS(res, 0, MOD-1);
        cout << res << endl;
    }
    return 0;
}

