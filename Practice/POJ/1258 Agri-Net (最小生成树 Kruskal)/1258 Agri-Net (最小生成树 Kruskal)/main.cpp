//
//  main.cpp
//  1258 Agri-Net (最小生成树 Kruskal)
//
//  Created by czf on 16/4/25.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200;
const int maxm = 50000;

int u[maxm], v[maxm], root[maxn], p[maxm], w[maxm];

bool cmp(const int i, const int j) {
    return w[i] < w[j];
}

int find(int x) {
    return x == root[x] ? x : root[x] = find(root[x]);
}

int main() {
    int n;
    while (~scanf("%d",&n)) {
        int m = 0;
        for (int i = 0; i < n; i ++) {
            root[i] = i;
            for (int j = 0; j < n; j ++) {
                int x; scanf("%d",&x);
                if (i == j) continue;
                w[m] = x;
                p[m] = m, u[m] = i, v[m] = j;
                m ++;
            }
        }
        sort(p, p + m, cmp);
        int res = 0;
        for (int i = 0; i < m; i ++) {
            int e = p[i]; int x = find(u[e]); int y = find(v[e]);
            if (x == y) continue;
            res += w[e];
            root[x] = y;
        }
        printf("%d\n",res);
    }
    return 0;
}
