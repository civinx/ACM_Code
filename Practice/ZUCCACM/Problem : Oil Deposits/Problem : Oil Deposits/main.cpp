//
//  main.cpp
//  Problem : Oil Deposits
//
//  Created by czf on 15/10/31.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

void dfs(int r, int c, int id){
    if (r < 0 || r >= m || c < 0 || c >= n) return;
    if (pic[r][c] != '@' || idx[r][c] > 0) return;
    idx[r][c] = id;
    for (int i = -1; i <= 1; i ++) {
        for (int j = -1; j <= 1; j ++) {
            if (i != 0 || j != 0) {
                dfs(r+i, c+j, id);
            }
        }
    }
}

int main() {
    while (cin >> m >> n && m && n) {
        for (int i = 0; i < m; i ++) cin >> pic[i];
        memset(idx, 0, sizeof(idx));
        int cnt = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (pic[i][j] == '@' && idx[i][j] == 0) dfs(i, j, ++cnt);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
