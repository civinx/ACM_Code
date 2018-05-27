//
//  main.cpp
//  3286 火柴排队
//
//  Created by czf on 16/9/28.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MOD = 99999997;
const int MAXN = 100000 + 100;
//const int MAXN = 100;

LL sum[MAXN], c[MAXN];
int n;

struct P {
    int v, p;
    bool operator < (const P &rhs) const {
        return v < rhs.v;
    }
}a[MAXN], b[MAXN];

inline LL lowbit(int x) {
    return (LL)(x & (-x));
}

void add(int v, int x) {
    for (int i = x; i <= n; i += lowbit(i)) {
        sum[i] += v;
    }
}

LL solve(int x) {
    LL ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ret += sum[i];
        ret %= MOD;
    }
    return ret;
}

int main() {
    while (~scanf("%d",&n)) {
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i ++) scanf("%d",&a[i].v), a[i].p = i;
        for (int i = 1; i <= n; i ++) scanf("%d",&b[i].v), b[i].p = i;
        sort(a+1, a+n+1);
        sort(b+1, b+n+1);
        for (int i = 1; i <= n; i ++) {
            c[a[i].p] = b[i].p;
        }
        
        LL res = 0;
        for (int i = n; i >= 1; i --) {
            res += solve((int)c[i]);
            res %= MOD;
            add(1, (int)c[i]);
        }
        printf("%lld\n",res);
    }
    return 0;
}
