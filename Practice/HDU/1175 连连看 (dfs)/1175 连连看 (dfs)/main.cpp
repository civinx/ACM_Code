//
//  main.cpp
//  1175 连连看 (dfs)
//
//  Created by czf on 16/2/3.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#define inf 0x4fffffff
const int maxn = 1000 + 10;
const int turn[4][2] = {1,0,-1,0,0,1,0,-1};
int pic[maxn][maxn];
int ans[maxn][maxn];
int n, m, x1, x2, y1, y2;
bool flag;

void dfs(int x, int y, int dir){
    if (flag){
        return;
    }
    if (ans[x][y] > 2){
        return;
    }
    if (ans[x][y] == 2 && x != x2 && y != y2){
        return;
    }
    if (x == x2 && y == y2){
        if (ans[x][y] <= 2){
            flag = 1;
        }
        return;
    }
    for(int i = 0; i < 4; i ++){
        int nx = x + turn[i][0];
        int ny = y + turn[i][1];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m){
            continue;
        }
        if (pic[nx][ny] && (nx != x2 || ny != y2)){
            continue;
        }
        if (ans[nx][ny] < ans[x][y]){
            continue;
        }
        if (ans[nx][ny] == ans[x][y] && dir != -1 && i != dir){
            continue;
        }
        ans[nx][ny] = ans[x][y];
        if (dir != -1 && i != dir){
            ans[nx][ny] ++;
        }
        dfs(nx, ny, i);
    }
}
int main(){
    while(scanf("%d%d",&n,&m) && (m || n)){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                scanf("%d",&pic[i][j]);
            }
        }
        int q; scanf("%d",&q);
        while(q--){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < m; j ++){
                    ans[i][j] = inf;
                }
            }
            x1 --; x2 --; y1 --; y2 --;
            if (pic[x1][y1] == pic[x2][y2] && pic[x1][y1] && pic[x2][y2] && (x1 != x2 || y1 != y2)){
                flag = 0;
                ans[x1][y1] = 0;
                dfs(x1, y1, -1);
                flag ? printf("YES\n") : printf("NO\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
