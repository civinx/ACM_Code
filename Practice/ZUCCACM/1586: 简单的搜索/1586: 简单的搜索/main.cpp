//
//  main.cpp
//  1586: 简单的搜索
//
//  Created by czf on 16/3/26.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100 + 10;
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
struct Point {
    int x, y; //x为行，y为列
    int step;//所用时间
    int cnt;//剩余的瞬移次数
};

string pic[maxn];
bool vis[maxn][maxn];
Point mov[26][2], star;//mov存放每对字母的点
int n, m, k;

void anspic() {
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            char c = pic[i][j];
            if (islower(c)){
                if (mov[c-'a'][0].x == -1) { mov[c-'a'][0].x = i; mov[c-'a'][0].y = j; }
                else { mov[c-'a'][1].x = i; mov[c-'a'][1].y = j; }
            }
            if (c == '@') { star.x = i; star.y = j; star.cnt = k; star.step = 0; vis[i][j] = 1; }
        }
    }
}

Point move(Point p) {
    int x = p.x, y = p.y;
    char c = pic[x][y];
    if (mov[c-'a'][0].x == x && mov[c-'a'][0].y == y) //找到与之相对的瞬移目标
        return mov[c-'a'][1];
    return mov[c-'a'][0];
}

void bfs() {
    queue<Point> q;
    q.push(star);
    Point cur, next;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        if (pic[cur.x][cur.y] == '$') {
            printf("%d\n",cur.step);
            return;
        }
        if (islower(pic[cur.x][cur.y]) && cur.cnt > 0) { //使用瞬移门的情况
            next = move(cur);
            int x = next.x, y = next.y;
            if (!vis[x][y]) {
                next.cnt = cur.cnt - 1, next.step = cur.step + 1;
                vis[x][y] = 1;
                q.push(next);
            }
        }
        for(int i = 0; i < 4; i ++) { //直接步行
            int x = cur.x + dir[i][0];
            int y = cur.y + dir[i][1];
            if (x >= n || x < 0 || y >= m || y < 0 || vis[x][y]) continue;
            if (cur.cnt < 1 && islower(pic[x][y])) continue;
            vis[x][y] = 1;
            next.x = x, next.y = y, next.cnt = cur.cnt, next.step = cur.step + 1;
            q.push(next);
        }
    }
}
            
int main() {
    while(scanf("%d%d%d",&n,&m,&k) && (n || m || k)) {
        memset(mov, -1, sizeof(mov));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i ++) cin >> pic[i];
        anspic();
        bfs();
    }
    return 0;
}