//
//  main.cpp
//  5877 Weak Pair (dfs序 离散化 树状数组)
//
//  Created by czf on 16/9/14.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100000 + 100;
const int inf = 0x7fffffff;
typedef long long ll;
ll a[N<<1], sum[N<<1], mp[N<<1];
bool vis[N], root[N];
vector<int> G[N];
ll n, m, k, res;


void init() {
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    memset(root, 0, sizeof(root));
    for (int i = 0; i < N; i ++) G[i].clear();
    res = 0;
}

inline int lowbit(int x) {
    return x & (-x);
}

ll query(int x) {
    ll ret = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) {
        ret += sum[i];
    }
    return ret;
}

void add(int x, int v) {
    for (int i = x; i <= m; i += lowbit(i)) {
        sum[i] += v;
    }
}

void dfs(int u) {
    vis[u] = 1;
    ll temp = (a[u] == 0 ? inf : k / a[u]);
    int pos = (int)(lower_bound(mp+1, mp+1+m, temp) - mp);
    int pos1 = (int)(lower_bound(mp+1, mp+1+m, a[u]) - mp);
    res += (long long)query(pos);
    add(pos1, 1);
    for (int v : G[u]) {
        if (!vis[v]) dfs(v);
    }
    add(pos1, -1);
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        init();
        scanf("%lld%lld",&n,&k);
        for (int i = 1; i <= n; i ++) {
            scanf("%lld",&a[i]);
            mp[i] = a[i];
        }
        for (int i = n+1; i <= 2*n; i ++) {
            int temp = mp[i-n];
            if (temp == 0) mp[i] = inf;
            else mp[i] = k / temp;
        }
        sort(mp+1, mp+1+2*n);
        m = (int)(unique(mp+1, mp+1+2*n) - (mp+1));
        for (int i = 0; i < n-1; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            root[v] = 1;
            G[u].push_back(v);
        }
        int s = 1;
        for (int i = 1; i <= n; i ++) {
            if (!root[i]) {
                s = i;
                break;
            }
        }
        dfs(s);
        printf("%lld\n",res);
    }
    return 0;
}