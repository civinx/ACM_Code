//
//  main.cpp
//  Bulbasaur and Matrix
//
//  Created by czf on 16/7/5.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 500 + 100;
int a[maxn][maxn];
int p[maxn], b[maxn];

bool cmp(int i, int j) {
    return b[i] > b[j];
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                cin >> a[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < n; i ++) {
            for (int k = 0; k < m; k ++) b[k] = a[i][k], p[k] = k;
            sort(p, p + m, cmp);
            for (int j = i+1; j < n; j ++) {
                
                int mx = 0, sc = 0;
                for (int k1 = 0; k1 < m; k1 ++) {
                    int k = p[k1];
                    if (a[i][k] < sc) break;
                    int temp = min(a[i][k], a[j][k]);
                    if (temp > mx) sc = mx, mx = temp;
                    else sc = max(sc, temp);
                }
                res = max(res, sc);
            }
        }
        cout << res << '\n';
    }
    return 0;
}
