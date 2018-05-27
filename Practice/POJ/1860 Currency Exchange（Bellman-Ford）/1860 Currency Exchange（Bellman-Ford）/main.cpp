//
//  main.cpp
//  1860 Currency Exchange（Bellman-Ford）
//
//  Created by czf on 16/4/20.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 200 + 10;

int N, M, S, tol;
double V;

int edge[maxn][2];
double c[maxn][2];
double d[maxn];

bool Bellman(int star) {
    for (int i = 1; i <= N; i ++) d[i] = 0;
    d[star] = V;
    for (int i = 1; i < N; i ++) {
        bool flag = 0;
        for (int j = 0; j < tol; j ++) {
            int from = edge[j][0], to = edge[j][1];
            if ((d[from]-c[j][1]) * c[j][0] > d[to]) {
                flag = 1;
                d[to] = (d[from]-c[j][1]) * c[j][0];
            }
        }
        if (!flag) return 0;
    }
    for (int i = 0; i < tol; i ++) {
        int from = edge[i][0], to = edge[i][1];
        if ((d[from]-c[i][1]) * c[i][0] > d[to]) return 1;
    }
    return 0;
}
int main() {
    while (scanf("%d%d%d%lf",&N,&M,&S,&V) != EOF) {
        tol = 0;
        while (M --) {
            int from, to;
            double r1, c1, r2, c2;
            scanf("%d%d%lf%lf%lf%lf",&from,&to,&r1,&c1,&r2,&c2);
            edge[tol][0] = from, edge[tol][1] = to;
            c[tol][0] = r1, c[tol][1] = c1;
            tol ++;
            edge[tol][0] = to, edge[tol][1] = from;
            c[tol][0] = r2, c[tol][1] = c2;
            tol ++;
        }
        if (Bellman(S)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}