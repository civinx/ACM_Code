//
//  main.cpp
//  1072 Nightmare
//
//  Created by czf on 16/2/5.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <queue>
#define inf 100
using namespace std;
enum{WALL, ROAD, STAR, EXIT, BRE};
const int maxn = 10;
const int turn[4][2] = {1,0,-1,0,0,1,0,-1};
int map[maxn][maxn], Time[maxn][maxn], cnt[maxn][maxn];
int n, m;

struct Pos{
    int x, y;
    bool flag = 0;
    Pos(int x=0, int y=0) : x(x), y(y) {}
};

void bfs(int x, int y){
    queue<Pos> q;
    Pos fir(x, y);
    q.push(fir);
    while(!q.empty()){
        fir = q.front(); q.pop();
        if (map[fir.x][fir.y] == EXIT){
            printf("%d\n",cnt[fir.x][fir.y]);
            return;
        }
        for(int i = 0; i < 4; i ++){
            Pos next(fir.x+turn[i][0], fir.y+turn[i][1]);
            if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m){
                continue;
            }
            if (map[next.x][next.y] == WALL){
                continue;
            }
            if (Time[fir.x][fir.y]-1 <= Time[next.x][next.y]){
                continue;
            }
            if (next.flag == 1){
                continue;
            }
            if (Time[fir.x][fir.y] == 1){
                break;
            }
            Time[next.x][next.y] = Time[fir.x][fir.y] - 1;
            if (map[next.x][next.y] == BRE){
                Time[next.x][next.y] = 6;
                next.flag = 1;
            }
            cnt[next.x][next.y] = cnt[fir.x][fir.y] + 1;
            q.push(next);
        }
    }
    printf("-1\n");
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int x, y;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                scanf("%d",&map[i][j]);
                Time[i][j] = -inf;
                cnt[i][j] = 0;
                if (map[i][j] == STAR){
                    x = i; y = j;
                }
            }
        }
        Time[x][y] = 6;
        bfs(x, y);
    }
}