//
//  main.cpp
//  1175 连连看 (bfs)
//
//  Created by czf on 16/2/3.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <queue>
#define inf 0x4fffffff
using namespace std;
const int maxn = 1000 + 10;
const int turn[4][2] = {1,0,-1,0,0,1,0,-1};
int pic[maxn][maxn];
int ans[maxn][maxn];
int n, m, x1, x2, y1, y2;
struct Point{
    int x; int y;
    Point(int x=0, int y=0) : x(x), y(y) {}
};

void bfs(int x, int y){
    queue<Point> q;
    Point fp(x, y);
    q.push(fp);
    while(!q.empty()){
        fp = q.front(); q.pop();
        if (fp.x == x2 && fp.y == y2){
            if (ans[fp.x][fp.y] <= 2){
                printf("YES\n");
                return;
            }
        }
        for(int i = 0; i < 4; i ++){
            Point np;
            np.x = fp.x + turn[i][0];
            np.y = fp.y + turn[i][1];
            while(np.x >= 0 && np.y >= 0 && np.x < n && np.y < m){
                if (pic[np.x][np.y] != 0 && (np.x != x2 || np.y != y2)){
                    break;
                }
                if (ans[np.x][np.y] <= ans[fp.x][fp.y]){
                    break;
                }
                if (ans[fp.x][fp.y] + 1 > 2){
                    break;
                }
                if (ans[fp.x][fp.y] + 1 == 2 && np.x != x2 && np.y != y2){
                    break;
                }
                ans[np.x][np.y] = ans[fp.x][fp.y] + 1;
                q.push(np);
                np.x += turn[i][0];
                np.y += turn[i][1];
            }
        }
    }
    printf("NO\n");
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
            if (pic[x1][y1] == pic[x2][y2] && pic[x1][y1] && pic[x2][y2]){
                ans[x1][y1] = -1;
                bfs(x1, y1);
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}

