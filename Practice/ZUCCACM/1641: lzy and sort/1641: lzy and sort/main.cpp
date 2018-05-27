//
//  main.cpp
//  1641: lzy and sort
//
//  Created by czf on 16/5/8.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;

const int maxn = 100000 + 100;
ll a[maxn], b[maxn];

int main() {
    int t; scanf("%d",&t);
    while (t --) {
        int n; scanf("%d",&n);
        for (int i = 0; i < n; i ++) scanf("%lld",&a[i]);
        for (int i = 1; i < n; i ++) b[i] = a[i] - a[i-1];
        std::sort(b+1, b+n, std::greater<int>());
        ll res = a[0];
        for (int i = 1; i < n; i ++) res += (a[i] = a[i-1] + b[i]);
        printf("%lld\n",res);
    }
    return 0;
}

