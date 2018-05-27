//
//  main.cpp
//  rausen loves cakes
//
//  Created by czf on 2017/3/14.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 10;
//const int maxn = 20;
vector<int> G[maxn*10];
int a[maxn], c[maxn*10], sum[maxn], n;

inline int lowbit(int x) {
    return x & (-x);
}

void update(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        sum[i] += v;
    }
}

int getsum(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ret += sum[i];
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int q; scanf("%d%d",&n,&q);
        for (int i = 0; i < maxn*10; i ++) c[i] = i;
        for (int i = 0; i < maxn*10; i ++) {
            G[i].clear();
        }
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i ++) {
            int x; scanf("%d",&x);
            a[i] = x;
            G[x].push_back(i);
        }
        a[0] = a[n+1] = -1;
        for (int i = 1; i <= n; i ++) {
            if (a[i] != a[i-1]) update(i, 1);
        }
        while (q--) {
            int op, u, v; scanf("%d%d%d",&op,&u,&v);
            if (op == 2) {
                printf("%d\n",getsum(v) - getsum(u-1) + (a[u] == a[u-1]));
            } else {
                int input_u = u, input_v = v;
                u = c[input_u], v = c[input_v];
                if (G[u].size() == 0 || u == v) continue;
                if (G[u].size() > G[v].size()) {
                    swap(u, v);
                }
                for (int i = 0; i < G[u].size(); i ++) {
                    int pos = G[u][i];
                    if (a[pos] != a[pos-1])
                        update(pos, -1);
                    if (a[pos+1] != a[pos])
                        update(pos+1, -1);
                    a[pos] = v;
                    if (a[pos] != a[pos-1])
                        update(pos, 1);
                    if (a[pos+1] != a[pos])
                        update(pos+1, 1);
                }
                while (G[u].size()) {
                    G[v].push_back(G[u].back());
                    G[u].pop_back();
                }
                c[input_v] = v; c[input_u] = 0;
            }
        }
       
    }
    return 0;
}
