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

LL p;

LL mul(LL x, LL k) {
    LL ret = 0;
    while (k) {
        if (k & 1) ret = (ret + x) % p;
        k >>= 1;
        x = (x + x) % p;
    }
    return ret;
}

LL qp(LL x, LL k) {
    LL ret = 1;
    while (k) {
        if (k & 1) ret = mul(ret, x);
        k >>= 1;
        x = mul(x, x);
    }
    return ret;
}

map<LL, LL> mp;
map<LL, LL> mp1;

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        mp1.clear();
        mp.clear();
        LL res = 0; int n;
        scanf("%d%lld",&n,&p);
        for (int i = 0; i < n; i ++) {
            LL x; scanf("%lld",&x);
            if (x == 0) continue;
            LL g = qp(x, 3);
            res += mp[g];
            mp[g] ++;
            if (p != 3) {
                res -= mp1[x];
                mp1[x] ++;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
