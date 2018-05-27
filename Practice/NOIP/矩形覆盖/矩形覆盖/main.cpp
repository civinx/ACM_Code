//
//  main.cpp
//  矩形覆盖
//
//  Created by czf on 2017/1/26.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 55;
const int maxk = 5;

struct Point { int x, y; };

struct Squ {
    Point l, r;
    Squ () { l.x = l.y = INF; r.x = r.y = -INF; }
};

Point p[maxn];
Squ s[maxk];

int n, k, res = INF;

int getS() {
    int ret = 0;
    for (int i = 1; i <= k; i ++) {
        int x1 = s[i].l.x, y1 = s[i].l.y, x2 = s[i].r.x, y2 = s[i].r.y;
        if (x1 != INF) {
            ret += (x2 - x1) * (y2 - y1);
        }
    }
    return ret;
}

void getIn(Squ &s1, const Point &p1) {
    s1.l.x = min(s1.l.x, p1.x);
    s1.l.y = min(s1.l.y, p1.y);
    s1.r.x = max(s1.r.x, p1.x);
    s1.r.y = max(s1.r.y, p1.y);
}

bool isCross(const Squ &s1, const Squ &s2) {
    if (s1.l.x == INF || s2.l.x == INF) return false;
    if (s1.l.x > s2.r.x || s2.l.x > s1.r.x) return false;
    if (s1.l.y > s2.r.y || s2.l.y > s2.r.y) return false;
    return true;
}
bool check() {
    for (int i = 1; i <= k; i ++) {
        for (int j = i+1; j <= k; j ++) {
            if (isCross(s[i], s[j])) return false;
        }
    }
    return true;
}

void dfs(int dep) {
    if (dep == n + 1) {
        res = min(res, getS());
        return;
    }
    for (int i = 1; i <= k; i ++) {
        Squ temp = s[i];
        getIn(s[i], p[dep]);
        if (check() && getS() < res) {
            dfs(dep+1);
        }
        s[i] = temp;
    }
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i ++) scanf("%d%d",&p[i].x,&p[i].y);
    dfs(1);
    printf("%d\n",res);
    return 0;
}
