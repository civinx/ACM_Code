//
//  main.cpp
//  1241 Oil Deposits (DFS)
//
//  Created by czf on 16/2/2.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;

char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

void dfs(int r, int c, int id){
    if (r < 0 || r >= m || c < 0 || c >= n) { // m是行，n是列。
        return;
    }
    if (idx[r][c] > 0 || pic[r][c] != '@') {
        return;
    }
    idx[r][c] = id;
    for (int i = -1; i <= 1; i ++) {
        for (int j = -1; j <= 1; j ++) {
            dfs(r+i, c+j, id);
        }
    }
}

int main() {
    int cnt = 0;
    while (cin >> m >> n && m && n) {
        for (int i = 0; i < m; i ++) {
            cin >> pic[i];
        }
        memset(idx, 0, sizeof(idx));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (!idx[i][j] && pic[i][j] == '@') {
                    dfs(i, j, ++ cnt);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}

