//
// Created by CZF on 2017/2/21.
//
//
// Created by CZF on 2017/2/16.
//

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 200000 + 100;
const LL INF = 1e18;

LL sum[maxn], sum1[maxn];
struct Stone { LL w, v; } stone[maxn];
struct P { LL l, r; } sec[maxn];

int main() {
    LL n, m, S, max_w = 0; scanf("%lld%lld%lld",&n,&m,&S);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld%lld",&stone[i].w,&stone[i].v);
        max_w = max(max_w, stone[i].w);
    }
    for (int i = 1; i <= m; i ++) {
        scanf("%lld%lld",&sec[i].l,&sec[i].r);
    }
    LL L = 0, R = max_w + 1, res = INF;
    while (L <= R) {
        LL W = (L + R) >> 1;
        for (int i = 1; i <= n; i ++) {
            sum[i] = sum[i-1];
            sum1[i] = sum1[i-1];
            if (stone[i].w >= W) sum[i] += stone[i].v, sum1[i] += 1;
        }
        LL Y = 0;
        for (int i = 1; i <= m; i ++) {
            Y += (sum1[sec[i].r] - sum1[sec[i].l - 1]) * (sum[sec[i].r] - sum[sec[i].l-1]);
        }
        LL temp = S - Y;
        if (temp < 0) temp *= -1;
        res = min(res, temp);
        if (res == 0) break;
        if (Y < S) R = W - 1;
        else L = W + 1;
    }
    printf("%lld\n",res);
    return 0;
}