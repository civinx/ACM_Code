//
//  main.cpp
//  Fxx and game
//
//  Created by czf on 2017/3/18.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 100;
//const int maxn = 100;

queue<int> q;
int dp[maxn];

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        while (!q.empty()) q.pop();
        memset(dp, INF, sizeof(dp));
        int x, k, t; scanf("%d%d%d",&x,&k,&t);
        dp[1] = 0; q.push(1);
        for (int i = 2; i <= x; i ++) {
            while (!q.empty() && i - t > q.front()) q.pop();
            if (!q.empty()) dp[i] = min(dp[i], dp[q.front()] + 1);
            if (i % k == 0) dp[i] = min(dp[i], dp[i/k] + 1);
            if (dp[i] <= dp[q.front()]) {
                while (!q.empty()) q.pop();
            }
            q.push(i);
        }
        printf("%d\n",dp[x]);
    }
    return 0;
}
