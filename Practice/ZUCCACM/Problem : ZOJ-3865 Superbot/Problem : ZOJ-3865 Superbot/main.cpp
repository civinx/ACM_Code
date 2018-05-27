//
//  main.cpp
//  Problem : ZOJ-3865 Superbot
//
//  Created by czf on 16/4/7.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;
const int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
const int maxn = 15;
struct P { int x, y, csr, off, t; };
bool vis[maxn][maxn][maxn][maxn];
string pic[maxn];
int n, m, p;

P init() {
    memset(vis, 0, sizeof(vis));
    P star;
    for (int i = 0; i < n; i ++) cin >> pic[i];
    for (int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if (pic[i][j] == '@') {
                star.x = i, star.y = j, star.csr = 0, star.off = 0, star.t = 0;
            }
        }
    }
    return star;
}

bool check(P a) { //检查并记录
    int x = a.x, y = a.y, csr = a.csr, off = a.off;
    if (x >= n || y >= m || x < 0 || y < 0) return 0;
    if (pic[x][y] == '*') return 0;
    if (vis[x][y][csr][off]) return 0;
    return vis[x][y][csr][off] = 1;
}

void bfs(P star) {
    queue<P> q;
    q.push(star);
    check(star);
    while(!q.empty()) {
        P cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, csr = cur.csr, off = cur.off, t = cur.t;
        if (pic[x][y] == '$') {
            printf("%d\n",t);
            return;
        }
        cur.x = x;
        cur.y = y;
        cur.csr = csr;
        cur.off = (t + 1) / p % 4;
        cur.t = t + 1;//不动
        if (check(cur)) q.push(cur);
        
        cur.x = x;
        cur.y = y;
        cur.csr = (4 + csr - 1) % 4;
        cur.off = (t + 1) / p % 4;
        cur.t = t + 1;//光标左移
        if (check(cur)) q.push(cur);
        
        cur.x = x;
        cur.y = y;
        cur.csr = (csr + 1) % 4;
        cur.off = (t + 1) / p % 4;
        cur.t = t + 1;//光标右移
        if (check(cur)) q.push(cur);
        
        cur.x = x + dir[(4+csr-off)%4][0];
        cur.y = y + dir[(4+csr-off)%4][1];
        cur.csr = csr;
        cur.off = (t+1) / p % 4;
        cur.t = t + 1;//移动
        if (check(cur)) q.push(cur);
    }
    printf("YouBadbad\n");
}

int main() {
    int kase; scanf("%d",&kase);
    while (kase--) {
        scanf("%d%d%d",&n,&m,&p);
        P star = init();
        bfs(star);
    }
    return 0;
}

