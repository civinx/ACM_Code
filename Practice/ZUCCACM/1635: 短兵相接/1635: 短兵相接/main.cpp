//
//  main.cpp
//  1635: 短兵相接
//
//  Created by czf on 16/4/8.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 100;
ll a[maxn], m[maxn];
bool vis[maxn][maxn];
int main (){
    int t; scanf("%d",&t);
    while(t--) {
        ll n; scanf("%lld",&n);
        ll sum = n * (n-1) * (n-2) / 6;
        memset(a, 0, sizeof(a));
        memset(m, 0, sizeof(m));
        memset(vis, 0, sizeof(vis));
        ll top = -1;
        for (int i = 0; i < n; i ++) {
            ll x; scanf("%lld",&x);
            a[x] ++;
            top = max(top, x);
        }
        for (int i = 1000; i >= 1; i --) {
            m[i] += a[i] + m[i+1];
        }
        
        for (int i = 1; i <= top; i ++) {
            for (int j = 1; j <= top; j ++) {
                if (vis[i][j] || vis[j][i]) continue;
                vis[i][j] = vis[j][i] = 1;
                int k = i + j;
                if (i == j) sum -= a[i] * (a[i]-1) / 2 * m[k];
                else sum -= a[i] * a[j] * m[k];
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}