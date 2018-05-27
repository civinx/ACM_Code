//
//  main.cpp
//  Problem : Constructing Roads In JGShining's Kingdom
//
//  Created by czf on 16/5/9.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 500000 + 100;
const int inf = 0xfffffff;
int id[maxn], a[maxn], dp[maxn], g[maxn];
//dp[i] = x代表以第i个元素结尾的最长上升子序列为x, g[x] = A, 代表最长子序列为x的结尾最小元素值为A

void LIS(int n) {
    for (int i = 1; i <= n; i ++) g[i] = inf;
    for (int i = 0; i < n; i ++) {
        int k = lower_bound(g+1, g+1+n, a[i]) - g;
        dp[i] = k;
        g[k] = a[i];
    }
}
int main() {
    int n, kase = 0;
    while (~scanf("%d",&n)) {
        for (int i = 0; i < n; i ++) {
            scanf("%d",&id[i]);
            scanf("%d",&a[id[i]-1]);
        }
        LIS(n);
        int res = 0;
        for (int i = 0; i < n; i ++) res = max(res, dp[i]);
        printf("Case %d:\n",++kase);
        if (res <= 1) printf("My king, at most %d road can be built.\n\n",res);
        else printf("My king, at most %d roads can be built.\n\n",res);
    }
    return 0;
}