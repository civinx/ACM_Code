//
//  main.cpp
//  Problem : Valid Pattern Lock
//
//  Created by czf on 16/3/31.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 10;
const int dir[16] = {-8,-7,-6,-5,-4,-3,-2,-1,1,2,3,4,5,6,7,8}; //16个方向
const int check[8][2] = {1,3,1,9,1,7,2,8,3,9,3,7,4,6,7,9};
bool vis[maxn], ans[maxn];
int n, kase, a[maxn], res[500000][maxn], temp[maxn];

bool solve(int a, int b) {
    for (int i = 0; i < 8; i ++) {
        if (check[i][0] == a && check[i][1] == b) {
            int x = (check[i][0] + check[i][1]) / 2;
            return vis[x];
        }
        if (check[i][1] == a && check[i][0] == b) {
            int x = (check[i][0] + check[i][1]) / 2;
            return vis[x];
        }
    }
    return 1;
}

void dfs(int x, int cnt) {
    temp[cnt] = x;
    vis[x] = 1;
    if (cnt == n-1) {
        for(int i = 0; i < n; i ++) res[kase][i] = temp[i];
        kase ++;
        vis[x] = 0;
        return;
    }
    for(int i = 0; i < 16; i ++) {
        int next = x + dir[i];
        if (next < 1 || next > 9) continue;
        if (!solve(x, next)) continue;
        if (vis[next]) continue;
        if (!ans[next]) continue;
        dfs(next, cnt+1);
    }
    vis[x] = 0;
}
int main() {
    int t; scanf("%d",&t);
    while(t--) {
        kase = 0; scanf("%d",&n);
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; i ++) { scanf("%d",&a[i]); ans[a[i]] = 1; }
        sort(a,a+n);
        for(int i = 0; i < n; i ++) {
            dfs(a[i], 0);
        }
        printf("%d\n",kase);
        for(int i = 0; i < kase; i ++) {
            for(int j = 0; j < n; j ++) {
                printf("%d%c",res[i][j],j==n-1?'\n':' ');
            }
        }
    }
    return 0;
}
