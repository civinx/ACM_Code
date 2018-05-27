//
//  main.cpp
//  5726 GCD
//
//  Created by czf on 2017/4/18.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int maxn = 100000 + 100;

int f[maxn][20], a[maxn];

void init(int n) {
    for (int i = 0; i < n; i ++) f[i][0] = a[i];
    for (int j = 1; j < 20; j ++) {
        for (int i = 0; i + (1<<j) - 1 < n; i ++) {
            f[i][j] = __gcd(f[i][j-1], f[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r) {
    int k = (int)log2(r - l + 1);
    return __gcd(f[l][k], f[r-(1<<k)+1][k]);
}

map<int, long long> mp;
void solve(int n) {
    mp.clear();
    for (int i = 0; i < n; i ++) {
        int j = i, g = a[i];
        while (j < n) {
            int l = j, r = n-1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (query(i, mid) == g) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            mp[g] += (l - j + 1);
            j = l + 1;
            if (j >= n) break;
            g = query(i, j);
        }
    }
}

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        for (int i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
        }
        init(n);
        solve(n);
        printf("Case #%d:\n",++kase);
        int m; scanf("%d",&m);
        for (int i = 0; i < m; i ++) {
            int l, r; scanf("%d%d",&l,&r);
            l--; r--;
            int g = query(l, r);
            printf("%d %lld\n",g, mp[g]);
        }
    }
    return 0;
}
