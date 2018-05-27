//
//  main.cpp
//  1223: 扫雷
//
//  Created by czf on 15/11/11.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10 + 5;
char pic[maxn][maxn];
char ans[maxn][maxn];
int cnt, n, m;

void dfs(int x, int y){
    ans[x][y] = 1;
    for (int i = -1; i <= 1; i ++) {
        for (int j = -1; j <= 1; j ++) {
            if (x+i>=m || x+i<0 || y+j>=n || y+j<0 || (i==0&&j==0) || ans[x+i][y+j])
                continue;
            ans[x+i][y+j] = 1;
            cnt ++;
            if (pic[x+i][y+j] == '0')
                dfs(x+i, y+j);
        }
    }
}
int main() {
    while (scanf("%d%d",&n,&m) == 2) {
        cnt = 1;
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n; i ++) {
            cin >> pic[i];
        }
        int x, y;
        scanf("%d%d",&x,&y);
        dfs(x-1, y-1);
        printf("%d\n",cnt);
    }
    return 0;
}
