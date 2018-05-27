//
//  main.cpp
//  1312 Red and Black
//
//  Created by czf on 15/11/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 20 + 5;

char pic[maxn][maxn];
int cnt;
int m ,n; // 列m 行n
void dfs(int x, int y){
    if (x >= n || x < 0 || y >= m || y < 0) return;
    if (pic[x][y] == '#') return;
    if (pic[x][y] != '@')
        cnt ++;
    pic[x][y] = '#';
    for(int i = -1; i <= 1; i ++)
        for(int j = -1; j <= 1; j ++)
            if ((i != 0 || j != 0) && (i == 0 || j == 0))
                dfs(x+i,y+j);
}
int main(){
    while(cin >> m >> n && m){
        cnt = 0;
        for (int i = 0; i < n; i ++){
            cin >> pic[i];
        }
        int i = 0, j = 0;
        int flag = 0;
        for(i = 0; i < n; i ++){
            for(j = 0; j < m; j ++){
                if (pic[i][j] == '@'){
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        dfs(i,j);
        printf("%d\n",cnt+1);
    }
}