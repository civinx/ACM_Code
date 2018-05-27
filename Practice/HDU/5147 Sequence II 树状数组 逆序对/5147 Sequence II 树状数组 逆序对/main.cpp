//
//  main.cpp
//  5147 Sequence II 树状数组 逆序对
//
//  Created by czf on 2016/10/18.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 50000 + 100;
//const int MAXN = 100;
typedef long long LL;

LL a[MAXN], c[MAXN];
int n;
LL ls[MAXN], rb[MAXN];
inline int lowbit(int x) {
    return x & (-x);
}

inline LL sum(int x) {
    LL ret = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) ret += c[i];
    return ret;
}

inline void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) c[i] += v;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i ++) scanf("%lld",&a[i]);
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i ++) {
            add((int)a[i], 1);
            ls[i] = sum((int)a[i]-1);
        }
        rb[n] = 0;
        for (int i = n-1; i >= 1; i --) {
            rb[i] = rb[i+1] + (n - a[i] - (i - 1 - ls[i]));
        }
        LL res = 0;
        for (int i = 1; i < n; i ++) {
            res += ls[i] * rb[i+1];
        }
        printf("%lld\n",res);
    }
    return 0;
}
