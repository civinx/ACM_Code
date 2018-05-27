//
//  main.cpp
//  2485 Highways（Prim 最小生成树 稠密图）
//
//  Created by czf on 16/4/24.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 500 + 100;
int edge[maxn][maxn], d[maxn];

struct P {
    int num, dist;
    bool operator > (const P &rhs) const {
        return dist > rhs.dist;
    }
};

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n; scanf("%d",&n);
        priority_queue<P, vector<P>, greater<P> > q;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                scanf("%d",&edge[i][j]);
                if (j == 0) d[i] = edge[i][j], q.push((P){i, d[i]});
            }
        }
        int res = 0, cnt = 0;
        while (!q.empty() && cnt < n - 1) {
            P cur = q.top(); q.pop();
            if (cur.dist != d[cur.num] || !d[cur.num]) continue;
            cnt ++;
            res = max(res, d[cur.num]);
            d[cur.num] = 0;
            for (int i = 0; i < n; i ++) {
                if (d[i] && d[i] > edge[cur.num][i]) {
                    d[i] = edge[cur.num][i], q.push((P){i, d[i]});
                } 
            }
        }
        printf("%d\n",res);
    }
    return 0;
}