//
//  main.cpp
//  1660: 青蛙过河（二分）
//
//  Created by czf on 16/9/22.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 50000 + 100;

int a[maxn] = {0}, b[maxn] = {0}, L, n, m;

bool check(int k) {
    int cnt = 0;
    for (int i = 1; i <= n+1; i ++) b[i] = a[i];
    for (int i = 1; i <= n+1; i ++) {
        int ans = b[i] - b[i-1];
        if (ans < k) {
            if (++cnt > m) return false;
            b[i] = b[i-1];
        }
    }
    return true;
}

int main() {
    while (scanf("%d%d%d",&L,&n,&m) == 3) {
        a[n+1] = L;
        for (int i = 1; i <= n; i ++) scanf("%d",&a[i]);
        int l = 0, r = L;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (check(m)) l = m;
            else r = m - 1;
        }
        printf("%d\n",l);
    }
    return 0;
}