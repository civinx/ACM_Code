//
//  main.cpp
//  2579 Dating with girls(2)
//
//  Created by czf on 16/2/5.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 100 + 1;
const int max_k = 10 + 1;
const int turn[4][2] = {1,0,-1,0,0,1,0,-1};
char map[maxn][maxn];
bool vis[maxn][maxn][max_k];
int n, m, k;
struct Pos{
    int x, y;
    int time = 0;
    Pos(int x=0, int y=0) : x(x), y(y) {}
};

void bfs(int x, int y){
    memset(vis, 0, sizeof(vis));
    queue<Pos> q; Pos fir(x, y);
    q.push(fir);
    vis[x][y][0] = 1;
    while(!q.empty()){
        fir = q.front(); q.pop();
        if (map[fir.x][fir.y] == 'G'){
            printf("%d\n",fir.time);
            return;
        }
        for(int i = 0; i < 4; i ++){
            Pos next(fir.x+turn[i][0], fir.y+turn[i][1]);
            if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m){
                continue;
            }
            if (map[next.x][next.y] == '#' && (fir.time+1)%k != 0){
                continue;
            }
            if (vis[next.x][next.y][(fir.time+1)%k] == 1){
                continue;
            }
            next.time = fir.time+1;
            vis[next.x][next.y][next.time%k] = 1;
            q.push(next);
        }
    }
    printf("Please give me another chance!\n");
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        int x, y;
        for(int i = 0; i < n; i ++){
            scanf("%s",map[i]);
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (map[i][j] == 'Y'){
                    x = i; y = j;
                }
            }
        }
        bfs(x, y);
    }
    return 0;
}