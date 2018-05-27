//
//  main.cpp
//  5925 Counting Cliques （搜索）
//
//  Created by czf on 2016/11/9.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

vector<int> G[MAXN];
bool mp[MAXN][MAXN];
int n, m, s, a[MAXN], cnt, res;

void dfs(int cur) {
    if (cnt > 0 && cur < a[cnt-1]) return;
    for (int i = 0; i < cnt; i ++) {
        if (!mp[cur][a[i]]) {
            return;
        }
    }
    a[cnt] = cur;
    if (cnt+1 == s) {
        res ++;
        return;
    }
    for (int i = 0; i < G[cur].size(); i ++) {
        int to = G[cur][i];
        cnt ++;
        dfs(to);
        cnt --;
    }
}
int main() {
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&m,&s);
        for (int i = 1; i <= n; i ++) G[i].clear();
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < m; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            mp[u][v] = mp[v][u] = 1;
            if (u > v) swap(u, v);
            G[u].push_back(v);
        }
        cnt = res = 0;
        for (int i = 1; i <= n; i ++) {
            dfs(i);
        }
        printf("%d\n",res);
    }
    return 0;
}

