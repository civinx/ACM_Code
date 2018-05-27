//
//  main.cpp
//  Problem : ZOJ-3862 Intersection
//
//  Created by czf on 16/4/6.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 * 2 + 100;
//const int maxn = 100;

struct Point { int x, y, num; };
struct Couple { int a, b; };

Point p[maxn];
Couple res[maxn];
int edge[maxn];
int ans[maxn];

bool cmp(Point a, Point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n; scanf("%d",&n);
        for (int i = 1; i <= n * 2; ++ i) {
            scanf("%d%d",&p[i].x, &p[i].y);
            p[i].num = i;
        }
        for (int i = 0; i < n; ++ i) {
            int x, y; scanf("%d%d",&x,&y);
            edge[x] = y, edge[y] = x;
        }
        sort(p+1, p+2*n+1, cmp);
        for (int i = 1; i <= 2 * n; ++ i)
            ans[p[i].num] = i;
        int cnt = 0;
        for (int i = 1; i < n * 2; i += 2) {
            int l = p[i].num, r = p[i+1].num;
            int pl = edge[l];
            if (edge[l] != r) {
                int indexpl = ans[pl], indexr = ans[r];//indexpl为l所指向的成员下标, indexr为r的下标
                ans[pl] = indexr, ans[r] = indexpl;//我们要交换l所指向的成员和r
                swap(p[indexpl], p[indexr]);
                res[cnt].a = r, res[cnt].b = pl;
                cnt ++;
            }
        }
        if (cnt > n + 10) {
            printf("-1\n");
            continue;
        }
        printf("%d\n",cnt);
        for (int i = 0; i < cnt; i ++) {
            printf("%d %d\n",res[i].a, res[i].b);
        }
    }
    return 0;
}
