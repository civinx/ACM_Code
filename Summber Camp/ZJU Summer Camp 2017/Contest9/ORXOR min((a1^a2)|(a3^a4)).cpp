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
const int maxn = 100000 + 100;
//const int maxn = 100;

LL sum[maxn];
bool ok[maxn];

bool isOne(LL x, int pos) {
    return x & (1ll << pos);
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, m; scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i ++) {
            scanf("%lld",&sum[i]);
            sum[i] ^= sum[i-1];
        }
        LL res = 0;
        for (int i = 1; i <= n; i ++) ok[i] = 1;
        for (int i = 63; i >= 0; i --) {
            int cnt = 0;
            for (int j = 1; j <= n; j ++) {
                if (ok[j] && !isOne(sum[j], i)) {
                    cnt ++;
                }
            }
            if (cnt >= m && !isOne(sum[n], i)) {
                for (int j = 1; j <= n; j ++) {
                    if (isOne(sum[j], i)) {
                        ok[j] = 0;
                    }
                }
            } else {
                res |= (1ll << i);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}