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
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;
typedef long long LL;

const LL maxn = 200000 + 100;

struct P {
    LL x, y, sum;
}a[maxn];

bool cmp1(const P & lhs, const P & rhs)  {
    return lhs.x < rhs.x;
}

bool cmp2(const P & lhs, const P & rhs)  {
    return lhs.y < rhs.y;
}


int main() {
    LL n;
    while (scanf("%lld",&n) == 1) {
        for (LL i = 1; i <= n; i ++) {
            LL x, y; scanf("%lld%lld",&x,&y);
            a[i].x = x + y; a[i].y = y - x;
        }
        sort(a + 1, a + 1 + n, cmp1);
        LL L = 0, R = 0;
        for (LL i = 1; i <= n; i ++) {
            R += a[i].x - a[1].x;
        }
        a[1].sum = L + R;
        for (LL i = 2; i <= n; i ++) {
            R -= 1ll * (n - i + 1ll) * (a[i].x - a[i-1].x);
            L += 1ll * (i - 1ll) * (a[i].x - a[i-1].x);
            a[i].sum = L + R;
        }
        
        sort(a + 1, a + 1 + n, cmp2);
        L = R = 0;
        for (LL i = 1; i <= n; i ++) {
            R += a[i].y - a[1].y;
        }
        a[1].sum += L + R;
        for (LL i = 2; i <= n; i ++) {
            R -= 1ll * (n - i + 1ll) * (a[i].y - a[i-1].y);
            L += 1ll * (i - 1ll) * (a[i].y - a[i-1].y);
            a[i].sum += L + R;
        }
        LL res = a[1].sum;
        for (LL i = 2; i <= n; i ++) {
            res = min(res, a[i].sum);
        }
        LL er = 2;
        res = res / er;
        printf("%lld\n",res);
    }
    return 0;
}



