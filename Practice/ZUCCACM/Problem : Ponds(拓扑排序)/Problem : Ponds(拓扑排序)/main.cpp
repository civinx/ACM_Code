//
//  main.cpp
//  Problem : Ponds(拓扑排序)
//
//  Created by czf on 16/6/3.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 100;
typedef long long ll;

struct Edge {
    int from, to;
};

bool dp[maxn], vis[maxn];
int in[maxn], n, m;
ll p[maxn];
vector<int> G[maxn];
vector<Edge> edge;

void init() {
    for (int i = 0; i < maxn; i ++) G[i].clear();
    edge.clear();
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    memset(in, 0, sizeof(in));
}

void add(int from, int to) {
    edge.push_back((Edge){from, to});
    int m = (int)edge.size() - 1;
    G[from].push_back(m);
}

ll bfs(int star) {
    ll ret = 0; int cnt = 0;
    queue<int> q; q.push(star);
    while (!q.empty()) {
        int from = q.front(); q.pop();
        if (dp[from] || vis[from]) continue;
        vis[from] = 1;
        cnt ++; ret += p[from];
        for (int i = 0; i < G[from].size(); i ++) {
            Edge &e = edge[G[from][i]];
            int to = e.to;
            q.push(to);
        }
    }
    if (cnt % 2) return ret;
    return 0;
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        init(); scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i ++) scanf("%lld",&p[i]);
        for (int i = 0; i < m; i ++) {
            int from, to; scanf("%d%d",&from,&to);
            in[from] ++; in[to] ++;
            add(from, to); add(to, from);
        }
        queue<int> q;
        for (int i = 1; i <= n; i ++) {
            if (in[i] == 0) dp[i] = 1;
            if (in[i] == 1) { dp[i] = 1; q.push(i); }
        }
        while (!q.empty()) {
            int from = q.front(); q.pop();
            dp[from] = 1;
            for (int i = 0; i < G[from].size(); i ++) {
                Edge &e = edge[G[from][i]];
                int to = e.to;
                in[to] --;
                if (in[to] == 0) dp[to] = 1;
                if (in[to] == 1) { dp[to] = 1; q.push(to); }
            }
        }
        ll res = 0;
        for (int i = 1; i <= n; i ++) {
            if (!dp[i]) res += bfs(i);
        }
        printf("%lld\n",res);
    }
    return 0;
}
