//
//  main.cpp
//  2874 Connections between cities(LCA Tarjan)
//
//  Created by czf on 16/7/9.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 1;

struct Edge {
    int next, to, w;
    //    int from;
};

struct Que {
    int from, next, to;
};

Edge edge[maxn<<1];
Que que[maxn * 200];
int head1[maxn], head2[maxn], root[maxn], vis[maxn], d[maxn], res[maxn * 100];
int n, m, q, ecnt1, ecnt2;


void init() {
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    memset(res, -1, sizeof(res));
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    for (int i = 0; i <= n; i ++) root[i] = i;
    ecnt1 = ecnt2 = 0;
}

void AddTree(int from, int to, int dist) {
    //    edge[ecnt1].from = from;
    edge[ecnt1].to = to;
    edge[ecnt1].w = dist;
    edge[ecnt1].next = head1[from];
    head1[from] = ecnt1 ++;
}

void AddQue(int from, int to) {
    que[ecnt2].from = from;
    que[ecnt2].to = to;
    que[ecnt2].next = head2[from];
    head2[from] = ecnt2++;
}

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

void Tarjan(int u, int index) {
    root[u] = u; vis[u] = index;
    for (int k = head1[u]; k != -1; k = edge[k].next) {
        if (!vis[edge[k].to]) {
            int to = edge[k].to, w = edge[k].w;
            d[to] = d[u] + w;
            Tarjan(to, index);
            root[to] = u;
        }
    }
    for (int k = head2[u]; k != -1; k = que[k].next) {
        if (vis[que[k].to] == index) {
            //            que[k].w = que[k^1].w = root[find(que[k].to)];
            if (k%2) res[k-1] = root[find(que[k].to)];
            else res[k] = root[find(que[k].to)];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    while (cin >> n >> m >> q) {
        init();
        for (int i = 0; i < m; i ++) {
            int from, to, dist; cin >> from >> to >> dist;
            AddTree(from, to, dist);
            AddTree(to, from, dist);
        }
        for (int i = 0; i < q; i ++) {
            int from, to; cin >> from >> to;
            AddQue(from, to);
            AddQue(to, from);
        }
        //        int k = 0;
        for (int i = 1; i <= n; i ++) {
            if (!vis[i]) {
                Tarjan(i, i);
            }
        }
        for (int i = 0; i < q; i ++) {
            int s = i*2+1;
            int w = res[i], from = que[s].from, to = que[s].to;
            if (w == -1) cout << "Not connected\n";
            else cout << d[from] + d[to] - 2 * d[w] << '\n';
        }
    }
    return 0;
}

