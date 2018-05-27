//
//  main.cpp
//  1125 Stockbroker Grapevine （Floyd-Warshall）
//
//  Created by czf on 16/4/21.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 200;
const int inf = 0xfffffff;

int d[maxn][maxn]; //d[i][j]表示i到j最小距离
bool vis[maxn];

int main() {
    int n;
    while (scanf("%d",&n) && n) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                d[i][j] = inf;
            }
        }
        for (int i = 1; i <= n; i ++) {
            int m; scanf("%d",&m);
            for (int j = 0; j < m; j ++) {
                int to, cost; scanf("%d%d",&to,&cost);
                d[i][to] = cost;
                d[i][i] = 0;
            }
        }
        for (int k = 1; k <= n; k ++) {
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= n; j ++) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
        int res1 = 0, res2 = inf;
        bool flag = 0;
        for (int i = 1; i <= n; i ++) {
            memset(vis, 0, sizeof(vis));
            int ans = 0;
            vis[i] = 1;
            for (int j = 1; j <= n; j ++) {
                ans = max(ans, d[i][j]);
                if (d[i][j] != inf) vis[j] = 1;
            }
            if (ans < res2) {
                res1 = i;
                res2 = ans;
            }
            if (!flag) {
                flag = 1;
                for (int i = 1; i <= n; i ++)
                    if (!vis[i]) {flag = 0; break;}
            }
        }
        if (flag) printf("%d %d\n",res1,res2);
        else printf("disjoint\n");
    }
    return 0;
}
