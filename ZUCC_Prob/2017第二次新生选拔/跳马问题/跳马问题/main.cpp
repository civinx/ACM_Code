//
//  main.cpp
//  跳马问题
//
//  Created by czf on 2017/2/21.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 500 + 1;
const int MOD = 1e9+7;
const int dir[2][2] = {{-1, -2}, {-2, -1}};

int f[maxn][maxn];
bool d[maxn][maxn];

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        memset(f, 0, sizeof(f));
        memset(d, 0, sizeof(d));
        int q; cin >> q;
        while (q--) {
            int x, y; cin >> x >> y;
            d[x][y] = 1;
        }
        f[1][1] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (d[i][j]) continue;
                for (int k = 0; k < 2; k ++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x <= 0 || y <= 0) continue;
                    f[i][j] = (f[i][j] + f[x][y]) % MOD;
                }
            }
        }
        cout << f[n][m] << endl;
    }
    return 0;
}
