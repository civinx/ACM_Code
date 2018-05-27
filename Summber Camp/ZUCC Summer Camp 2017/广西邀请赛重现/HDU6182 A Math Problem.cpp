#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
#define INIT int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;


LL mp(LL k) {
    LL ret = 1;
    for (LL i = 0; i < k; i ++) {
        ret *= k;
    }
    return ret;
}
int main() {
    LL n;
//    while (scanf("%lld",&n) == 1) {
//        printf("%lld\n",mp(n));
//    }
    while (scanf("%lld",&n) == 1) {
        int res = 0;
        for (LL i = 1; i <= 15; i ++) {
            if (mp(i) <= n) res ++;
            else break;
        }
        printf("%d\n",res);
    }
    return 0;
}
