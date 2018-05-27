//
//  main.cpp
//  Bulbasaur and Matrix（二分法）
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
int n, m;

bool check(int x) {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (a[i][j] < x) continue;
            for (int i1 = i+1; i1 < n; i1 ++) {
                if (a[i1][j] < x) continue;
                for (int j1 = j+1; j1 < m; j1 ++) {
                    if (a[i1][j1] < x) continue;
                    if (a[i][j1] < x) continue;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                cin >> a[i][j];
            }
        }
        int l = 0, r = 1e9 + 100, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (check(mid)) l = mid + 1;
            else r = mid;
        }
        cout << l - 1 << '\n';
    }
    return 0;
}

