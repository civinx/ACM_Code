//
//  main.cpp
//  4081 Qin Shi Huang's National Road System 次小生成树
//
//  Created by czf on 2017/7/17.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int maxn = 1000 + 10;

struct Point {
    double x, y, p;
};

struct P {
    int id, to;
    double dist;
    bool operator > (const P & rhs) const {
        return dist > rhs.dist;
    }
};

Point city[maxn];
double d[maxn];
double maxedge[maxn][maxn];
bool edges[maxn][maxn];
bool vis[maxn];

double getDist(const Point & a, const Point & b) {
    double g1 = a.x - b.x;
    double g2 = a.y - b.y;
    return sqrt(g1 * g1 + g2 * g2);
}

double prim(int n) {
    memset(edges, 0, sizeof(edges));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            maxedge[i][j] = maxedge[j][i] = 0;
        }
    }
    d[0] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    for (int i = 1; i < n; i ++) {
        d[i] = getDist(city[0], city[i]);
        q.push(P{i, 0, d[i]});
        //        maxedge[i][0] = maxedge[0][i] = d[i];
    }
    double ret = 0;
    int cnt = 1;
    vis[0] = 1;
    while (cnt < n) {
        P cur = q.top(); q.pop();
        if (vis[cur.id] || d[cur.id] != cur.dist) {
            continue;
        }
        ret += cur.dist;
        edges[cur.id][cur.to] = edges[cur.to][cur.id] = 1;
        d[cur.id] = 0;
        vis[cur.id] = 1;
        cnt ++;
        for (int i = 0; i < n; i ++) {
            if (i == cur.id || vis[i]) {
                continue;
            }
            double temp = getDist(city[cur.id], city[i]);
            if (temp < d[i]) {
                d[i] = temp;
                q.push(P{i, cur.id, d[i]});
            }
        }
        for (int i = 0; i < n; i ++) {
            if (i == cur.id || vis[i] == 0) {
                continue;
            }
            maxedge[cur.id][i] = maxedge[i][cur.id] = max(getDist(city[cur.id], city[cur.to]), maxedge[cur.to][i]);
        }
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        for (int i = 0; i < n; i ++) {
            scanf("%lf%lf%lf",&city[i].x,&city[i].y,&city[i].p);
        }
        double B = prim(n);
        double res = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i+1; j < n; j ++) {
                double a = city[i].p + city[j].p;
                if (edges[i][j]) {
                    double b = B - getDist(city[i], city[j]);
                    res = max(res, a / b);
                } else {
                    double b = B - maxedge[i][j];
                    res = max(res, a / b);
                }
            }
        }
        printf("%.2f\n",res);
    }
    return 0;
}
