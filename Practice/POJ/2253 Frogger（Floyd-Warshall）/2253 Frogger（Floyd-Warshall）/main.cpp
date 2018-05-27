//
//  main.cpp
//  2253 Frogger（Floyd-Warshall）
//
//  Created by czf on 16/4/21.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 200 + 100;
double d[maxn][maxn];//d[i][j]代表从i到j各条通路中最小的frog_distance， frog_distance为一条通路中最长的边。

struct Point {
    double x, y;
};

Point a[maxn];

double solve(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int main() {
    int kase = 0;
    int n;
    while(scanf("%d",&n) && n) {
        for (int i = 1; i <= n; i ++) {
            scanf("%lf%lf",&a[i].x,&a[i].y);
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                d[i][j] = solve(a[i].x, a[i].y, a[j].x, a[j].y);
            }
        }
        for (int k = 1; k <= n; k ++) {
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= n; j ++) {
                    if (d[i][j] > max(d[i][k], d[k][j])) {
                        d[i][j] = max(d[i][k], d[k][j]);
                    }
                }
            }
        }
        printf("Scenario #%d\n",++kase);
        printf("Frog Distance = %.3f\n\n",d[1][2]);
        getchar();
    }
    return 0;
}
