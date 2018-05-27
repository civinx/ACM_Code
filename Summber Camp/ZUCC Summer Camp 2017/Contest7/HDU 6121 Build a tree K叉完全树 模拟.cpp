#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;

typedef long long LL;

LL maxn;

LL num[100];

LL mp(LL x, LL k) {
    LL ret = 1;
    while (k) {
        if (k & 1) ret *= x;
        k >>= 1;
        x *= x;
    }
    return ret;
}

bool check(LL sum, LL k, LL dep) {
    LL mod = maxn - sum;
    LL t = log(mod) / log(k);
    return t >= dep;
}

void init(LL k, LL & dep) {
    LL sum = 1; dep = 1; num[0] = 1;
    while (check(sum, k, dep)) {
        sum += mp(k, dep);
        num[dep] = sum;
        dep ++;
    }
    dep --;
}

LL solve(LL sum, LL k, LL dep) {
    if (k == 1) {
        switch (sum % 4) {
            case 1: return 1;
            case 2: return sum + 1;
            case 3: return 0;
            case 0: return sum;
        }
    }
    if (dep == 0) {
        return sum ^ ((sum - 1) & 1);
    }
    if (sum == num[dep]) {
        return sum;
    }
    LL rem = sum - num[dep], ret = sum, avg = (sum - 1 - rem) / k, mx = mp(k, dep);
    LL g = rem / mx, mod = rem % mx;
    if (g & 1) ret ^= (avg + mx);
    if ((k - g - 1) & 1) ret ^= avg;
    ret ^= solve(avg + mod, k, dep - 1);
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        LL n, k; scanf("%lld%lld",&n,&k);
        maxn = n;
        LL dep;
        init(k, dep);
        LL res = solve(n, k, dep);
        printf("%lld\n",res);
    }
    return 0;
}
