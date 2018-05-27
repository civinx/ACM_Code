//
//  main.cpp
//  1782 逃离迷宫 (BFS)
//
//  Created by czf on 16/2/3.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <queue>
using namespace std;
const int inf = 0x4fffffff;
const int maxn = 100 + 5;
const int turn[4][2] = {0,1,0,-1,1,0,-1,0};
char pic[maxn][maxn];
int ans[maxn][maxn];
int m, n, k, x1, x2, y1, y2;
struct Point{
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};
void bfs(int x, int y){ //fp = fisrt point, np = next point
    queue<Point> q;
    Point fp(x,y);
    q.push(fp);
    while(!q.empty()){
        fp = q.front(); q.pop();
        if (fp.x == x2 && fp.y == y2){
            if (ans[fp.x][fp.y] <= k){
                printf("yes\n");
                return;
            }
        }
        for(int i = 0; i < 4; i ++){
            Point np(fp.x+turn[i][0], fp.y+turn[i][1]);
            while(np.x >= 0 && np.y >=0 && np.x < m && np.y < n){
                if (pic[np.x][np.y] == '*'){
                    break;
                }
                if (ans[np.x][np.y] <= ans[fp.x][fp.y]){
                    break;
                }
                if (ans[fp.x][fp.y]+1 > k){
                    break;
                }
                if (ans[fp.x][fp.y]+1 == k && np.x != x2 && np.y != y2){
                    break;
                }
                ans[np.x][np.y] = ans[fp.x][fp.y] + 1;
                q.push(np);
                np.x += turn[i][0];
                np.y += turn[i][1];
            }
        }
    }
    printf("no\n");
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(int i = 0; i < m; i ++)
            scanf("%s",pic[i]);
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                ans[i][j] = inf;
        scanf("%d%d%d%d%d",&k,&y1,&x1,&y2,&x2);
        x1 --; x2 --; y1 --; y2 --;
        ans[x1][y1] = -1;
        bfs(x1, y1);
    }
    return 0;
}