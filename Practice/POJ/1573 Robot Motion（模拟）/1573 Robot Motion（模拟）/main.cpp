//
//  main.cpp
//  1573 Robot Motion（模拟）
//
//  Created by czf on 16/4/13.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; //E->0 W->1 S->2 N->3
const int maxn = 15;
string pic[maxn];
int ans[maxn][maxn];
map<char, int> mm;

int main() {
    int n, m, k;
    mm['E'] = 0, mm['W'] = 1, mm['S'] = 2, mm['N'] = 3;
    while (scanf("%d%d%d",&n,&m,&k) && (n || m || k)) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                ans[i][j] = 0xfffffff;
            }
        }
        for (int i = 0; i < n; ++i) cin >> pic[i];
        int x = 0, y = --k;
        ans[x][y] = 0;
        while (1) {
            char c = pic[x][y];
            int xx, yy;
            xx = x + dir[mm[c]][0];
            yy = y + dir[mm[c]][1];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) {
                printf("%d step(s) to exit\n",ans[x][y] + 1);
                break;
            }
            if (ans[xx][yy] > ans[x][y]) {
                ans[xx][yy] = ans[x][y] + 1;
                x = xx, y = yy;
            } else {
                int res = ans[x][y] + 1 - ans[xx][yy];
                printf("%d step(s) before a loop of %d step(s)\n",ans[xx][yy],res);
                break;
            }
        }
    }
    return 0;
}