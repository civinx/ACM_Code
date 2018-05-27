//
//  main.cpp
//  Car的旅行路线
//
//  Created by czf on 2017/1/25.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 500;
const double INF = 10000000;
double d[maxn], edge[maxn][maxn], cost[maxn>>2];
bool vis[maxn];

struct Point {
    double x, y;
};

Point p[maxn];

double count(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool cross(double x1, double y1, double x2, double y2) {
    double L = (x1 * y2) - (x2 * y1); L *= L;
    double R = (x1 * x1 + y1 * y1) * (x2 * x2 + y2 * y2);
    return L == R;
}

void solve(const Point &p1, const Point &p2, const Point &p3, Point &p4) {
    double offx = p3.x - p1.x;
    double offy = p3.y - p1.y;
    p4.x = p2.x + offx;
    p4.y = p2.y + offy;
}



void init(int n) {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            edge[i][j] = INF;
        }
    }
}

double work(int n, int s, int t) {
    for (int i = 0; i < n; i ++) d[i] = INF;
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    int u = s;
    for (int i = 0; i < n; i ++) {
        double mi = INF;
        for (int j = 0; j < n; j ++) {
            if (d[j] < mi && !vis[j]) {
                u = j;
                mi = d[j];
            }
        }
        vis[u] = 1;
        for (int j = 0; j < n; j ++) {
            d[j] = min(d[j], d[u] + edge[u][j]);
//            if (j / 4 == t) {
//                printf("%.1f\n",d[j]);
//            }
        }
    }
    double ret = INF;
    for (int i = t*4; i < t*4+4; i ++) {
        ret = min(ret, d[i]);
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, s, t; double c1; scanf("%d%lf%d%d",&n,&c1,&s,&t);
        s--; t--;
        for (int i = 0; i < n; i ++) {
            Point p1, p2, p3, p4;
            scanf("%lf%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &cost[i]);
            if (cross(p1.x - p2.x, p1.y - p2.y, p1.x - p3.x, p1.y - p3.y)) {
                solve(p1, p2, p3, p4);
            } else if (cross(p2.x - p1.x, p2.y - p1.y, p2.x - p3.x, p2.y - p3.y)) {
                solve(p2, p1, p3, p4);
            } else {
                solve(p3, p1, p2, p4);
            }
            p[i*4] = p1, p[i*4+1] = p2, p[i*4+2] = p3, p[i*4+3] = p4;
        }
        n *= 4;
//        for (int i = 0; i < n; i ++) {
//            printf("%.3f %.3f\n",p[i].x,p[i].y);
//        }
        init(n);
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                double dist = count(p[i], p[j]);
                if (i / 4 == j / 4)
                    edge[i][j] = edge[j][i] =  dist * cost[i/4];
                else
                    edge[i][j] = edge[j][i] = dist * c1;
            }
        }
        double res = INF;
        for (int i = s * 4; i < s * 4 + 4; i ++) {
            res = min(res, work(n, i, t));
        }
        printf("%.1f\n",res);
    }
    return 0;
}
