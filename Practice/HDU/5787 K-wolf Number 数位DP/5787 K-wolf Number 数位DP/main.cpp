//
//  main.cpp
//  5787 K-wolf Number 数位DP
//
//  Created by czf on 2017/4/13.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 20;

LL dp[maxn][11][11][11][11][6]; //dp[pos][p1][p2][p3][p4][p5]
int num[maxn];

int cnt = 0;
int k;

LL dfs(int pos, int pre[], int limit) {
    if (pos == -1) {
        return 1;
    }
    int p0 = 10, p1 = 10, p2 = 10, p3 = 10;
    if (k >= 1) p0 = pre[0];
    if (k >= 2) p1 = pre[1];
    if (k >= 3) p2 = pre[2];
    if (k >= 4) p3 = pre[3];
    if (!limit && dp[pos][p0][p1][p2][p3][k] != -1) {
        return dp[pos][p0][p1][p2][p3][k];
    }
    
    int temp[6]; for (int i = 0; i < k; i ++) temp[i] = pre[i];
    int end = (limit ? num[pos] : 9);
    LL ret = 0;
    for (int i = 0; i <= end; i ++) {
        bool flag = 1;
        for (int j = 0; j < k; j ++) {
            if (pre[j] == i) {
                flag = 0;
                break;
            }
        }
        if (!flag) continue;
        
        bool zero = 1;
        for (int i = 0; i < k; i ++) {
            if (pre[i] != 10) {
                zero = 0;
                break;
            }
        }
        
        if (!zero || i != 0) {
            for (int i = k-1; i > 0; i --) pre[i] = pre[i-1];
            pre[0] = i;
        }
        
        
        ret += dfs(pos - 1, pre, limit && (i == end));
        
        for (int i = 0; i < k; i ++) pre[i] = temp[i];
    }
    if (!limit) {
        dp[pos][p0][p1][p2][p3][k] = ret;
    }
    return ret;
}


LL solve(LL x) {
    int pos = 0;
    while (x) {
        num[pos++] = x % 10;
        x /= 10;
    }
    int temp[6];
    for (int i = 0; i < k; i ++) temp[i] = 10;
    return dfs(pos-1, temp, 1);
}

int main() {
    
    LL L, R;
    memset(dp, -1, sizeof(dp));
    while (scanf("%lld%lld%d",&L,&R,&k) == 3) {
        
        k --;
        //printf("solve(%lld) = %lld\n",L,solve(L));
        //printf("solve(%lld) = %lld\n",R,solve(R));
        printf("%lld\n",solve(R) - solve(L-1));
    }
    return 0;
}
