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

const int maxn = 2000 + 100;
const int MOD = 998244353;

LL dp[maxn][maxn], sum[maxn][maxn];
LL a[maxn], b[maxn];

LL add(LL x, LL y) {
    return (x + y) % MOD;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        MS(sum, 0);
        MS(dp, 0);
        int n, m; scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i ++) scanf("%lld",&a[i]);
        for (int i = 1; i <= m; i ++) scanf("%lld",&b[i]);
        LL res = 0;
        for (int i = 1; i <= n; i ++) {
            LL cnt0 = 0, cnt1 = 1;
            for (int j = 1; j <= m; j ++) {
                dp[j][0] = dp[j][1] = 0;
                if (b[j] == a[i]) {
                    dp[j][0] = cnt1;
                    dp[j][1] = cnt0;
                    res = add(res, (cnt0 + cnt1) % MOD);
                } else if (b[j] < a[i]) {
                    cnt0 = add(cnt0, sum[j][0]);
                } else {
                    cnt1 = add(cnt1, sum[j][1]);
                }
            }
            for (int j = 1; j <= m; j ++) {
                sum[j][0] = add(sum[j][0], dp[j][0]);
                sum[j][1] = add(sum[j][1], dp[j][1]);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
