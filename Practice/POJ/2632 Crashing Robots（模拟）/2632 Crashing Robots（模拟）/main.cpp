//
//  main.cpp
//  2632 Crashing Robots（模拟）
//
//  Created by czf on 16/4/13.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
const int maxn = 200;

struct Robot {
    int x, y;
    int dir;
    Robot(int x = 0, int y = 0, int dir = -1) : x(x), y(y), dir(dir) {};
};

Robot a[maxn];
int vis[maxn][maxn];

int main () {
    int t; scanf("%d",&t);
    while (t--) {
        memset(vis, 0, sizeof(vis));
        int m, n; scanf("%d%d",&m,&n);
        int A, B; scanf("%d%d",&A,&B);
        for (int i = 1; i <= A; i ++) {
            int x, y, dir; char c;
            getchar();
            scanf("%d%d",&y,&x);
            scanf(" %c",&c);
            vis[x][y] = i;
            if (c == 'N') dir = 0;
            if (c == 'E') dir = 1;
            if (c == 'S') dir = 2;
            if (c == 'W') dir = 3;
            Robot temp(x, y, dir); a[i] = temp;
        }
        int flag = 0, res1 = 0, res2 = 0;
        for (int i = 0; i < B; i ++) {
            int num, cnt; char ins;
            ins = getchar();
            scanf("%d %c%d",&num,&ins,&cnt);
            if (flag) continue;
            if (ins == 'L') {
                a[num].dir = a[num].dir - cnt;
                while (a[num].dir < 0) a[num].dir += 4;
            }
            if (ins == 'R') a[num].dir = (a[num].dir + cnt) % 4;
            if (ins == 'F') {
                for (int j = 0; j < cnt; j ++) {
                    int x = a[num].x, y = a[num].y;
                    x += dir[a[num].dir][0];
                    y += dir[a[num].dir][1];
                    if (x <= 0 || x > n || y <= 0 || y > m) { res1 = num; flag = 1; break; }
                    if (vis[x][y]) { res1 = num; res2 = vis[x][y]; flag = 2; break; }
                    vis[a[num].x][a[num].y] = 0;
                    vis[x][y] = num;
                    a[num].x = x, a[num].y = y;
                }
            }
        }
        if (!flag) printf("OK\n");
        else if (flag == 1) printf("Robot %d crashes into the wall\n",res1);
        else if (flag == 2) printf("Robot %d crashes into robot %d\n",res1,res2);
    }
    return 0;
}
