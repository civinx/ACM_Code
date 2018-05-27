//
//  main.cpp
//  1328 Radar Installation（贪心）
//
//  Created by czf on 16/3/23.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;

struct Point {
    double x, y;
    double l, r;
};

bool cmp(Point a, Point b) {
    return a.r < b.r;
}

Point p[maxn];

int main() {
    int n, kase = 0;
    double r;
    while(scanf("%d%lf",&n,&r) && (n || r)) {
        int res = 0;
        bool flag = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        for(int i = 0; i < n; i ++) {
            if (p[i].y > r || p[i].y < 0 || r < 0) { flag = 1; break; }
            int x = p[i].x, y = p[i].y;
            p[i].l = x - sqrt(r*r - y*y);
            p[i].r = x + sqrt(r*r - y*y);
        }
        if (flag) { printf("Case %d: -1\n",++kase); continue; }
        sort(p, p+n, cmp);
        double ans = -2000000000;
        for(int i = 0; i < n; i ++) {
            if (p[i].l - ans > 1e-5){
                res ++;
                ans = p[i].r;
            }
        }
        printf("Case %d: %d\n",++kase,res);
    }
    return 0;
}