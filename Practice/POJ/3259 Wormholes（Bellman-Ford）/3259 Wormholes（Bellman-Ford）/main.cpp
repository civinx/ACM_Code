//
//  main.cpp
//  3259 Wormholes（Bellman-Ford）
//
//  Created by czf on 16/4/20.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int inf = 0xfffffff;
const int maxn = 10000;
int edge[maxn][2], c[maxn], d[maxn];
int N, M, W, tol;

bool Bellman_Ford() {
    for (int i = 1; i <= N; i ++) d[i] = inf;
    d[1] = 0;
    for (int i = 0; i < N-1; i ++) {
        bool flag = 0;
        for (int j = 0; j < tol; j ++) {
            int from = edge[j][0], to = edge[j][1];
            if (d[from] + c[j] < d[to]) {
                flag = 1;
                d[to] = d[from] + c[j];
            }
        }
        if (!flag) return 0;
    }
    for (int i = 0; i < tol; i ++) {
        int from = edge[i][0], to = edge[i][1];
        if (d[from] + c[i] < d[to])
            return 1;
    }
    return 0;
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        tol = 0;
        scanf("%d%d%d",&N,&M,&W);
        for (int i = 0; i < M; i ++) {
            int from, to, cost;
            scanf("%d%d%d",&from,&to,&cost);
            edge[tol][0] = from, edge[tol][1] = to, c[tol] = cost, tol ++;
            edge[tol][0] = to, edge[tol][1] = from, c[tol] = cost, tol ++;
        }
        for (int i = 0; i < W; i ++) {
            int from, to, cost;
            scanf("%d%d%d",&from,&to,&cost);
            edge[tol][0] = from, edge[tol][1] = to, c[tol] = -cost, tol ++;
        }
        if (Bellman_Ford()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}