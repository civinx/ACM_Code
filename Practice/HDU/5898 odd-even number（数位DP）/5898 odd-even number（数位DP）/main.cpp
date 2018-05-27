//
//  main.cpp
//  5898 odd-even number（数位DP）
//
//  Created by czf on 16/9/18.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 25;
ll dp[maxn][2][maxn]; //dp[pos][pre][len]
int num[maxn];

int cnt = 0;
ll dfs(int pos, int pre, int len, int limit) {
    if (pos == -1) {
        //        cout << cnt++ << " ";
        //        cout << "pre=" << pre << " len=" << len << endl;
        return (pre % 2 != len % 2) && pre != -1;
    }
    if (!limit && pre != -1 && dp[pos][pre][len] != -1) {
        return dp[pos][pre][len];
    }
    int end = (limit ? num[pos] : 9);
    ll ret = 0;
    for (int i = 0; i <= end; i ++) {
        if (pre == -1) {
            if (i == 0) ret += dfs(pos-1, -1, 0, limit && (i == end));
            else ret += dfs(pos-1, i%2, 1, limit && (i == end));
        } else {
            if (i % 2 == pre % 2) ret += dfs(pos-1, i%2, len+1, limit && (i == end));
            else {
                if (pre%2 == len%2) continue;
                ret += dfs(pos-1, i%2, 1, limit && (i == end));
            }
        }
    }
    if (!limit && pre != -1) {
        dp[pos][pre][len] = ret;
    }
    return ret;
}



ll solve(ll x) {
    int pos = 0;
    while (x) {
        num[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos-1, -1, 0, 1);
}

int main() {
    int t; scanf("%d",&t);
    memset(dp, -1, sizeof(dp));
    int kase = 0;
    while (t--) {
        ll L, R; scanf("%lld%lld",&L,&R);
        //        ll x; cin >> x;
        //        cout << solve(x) << endl;
        printf("Case #%d: ", ++kase);
        printf("%lld\n",solve(R) - solve(L-1));
    }
    return 0;
}