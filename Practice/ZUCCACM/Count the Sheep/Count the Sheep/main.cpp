//
//  main.cpp
//  Count the Sheep
//
//  Created by czf on 2017/3/18.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 2e5 + 100;
typedef long long LL;
LL L[maxn], R[maxn], d[maxn];

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        memset(d, 0, sizeof(d));
        LL n, m, k; scanf("%lld%lld%lld",&n,&m,&k);
        for (int i = 0; i < k; i ++) {
            int x, y; scanf("%d%d",&x,&y);
            y += n;
            R[i] = x; L[i] = y;
            d[x] ++; d[y] ++;
        }
        LL res = 0;
        for (int i = 0; i < k; i ++) {
            res += (d[R[i]] - 1) * (d[L[i]] - 1);
        }
        res *= 2;
        printf("%lld\n",res);
    }
    return 0;
}
