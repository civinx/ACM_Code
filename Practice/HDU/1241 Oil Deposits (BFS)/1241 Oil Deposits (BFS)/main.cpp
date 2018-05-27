//
//  main.cpp
//  1241 Oil Deposits (BFS)
//
//  Created by czf on 16/2/2.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 100 + 10;
char pic[maxn][maxn];
int m, n;

struct point{
    int x;
    int y;
    point(int x, int y) : x(x), y(y) {}
};

void input(){
    
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++)
            scanf("%c",&pic[i][j]);
        getchar();
    }
}

void bfs(int a, int b){
    queue<point> q;
    point temp(a, b);
    q.push(temp); pic[a][b] = '*';
    while(!q.empty()){
        point u = q.front(); q.pop();
        for(int i = -1; i <= 1; i ++){
            for(int j = -1; j <= 1; j ++){
                if ((i||j) && i+u.x < m && i+u.x >= 0 && j+u.y >= 0 && j+u.y < n && pic[i+u.x][j+u.y]!='*'){
                    temp.x = i+u.x; temp.y = j+u.y; pic[i+u.x][j+u.y] = '*';
                    q.push(temp);
                }
            }
        }
    }
}
int main(){
    while(scanf("%d%d",&m,&n) && (m || n)){
        getchar();
        input();
        int cnt = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if (pic[i][j]!='*'){
                    bfs(i, j);
                    cnt ++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

