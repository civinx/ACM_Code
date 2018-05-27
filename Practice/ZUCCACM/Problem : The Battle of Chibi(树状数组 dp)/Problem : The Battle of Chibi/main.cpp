//
//  main.cpp
//  Problem : The Battle of Chibi
//
//  Created by czf on 16/7/9.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 1000 + 10;
int f[N][N],c[N][N], a[N], r[N];
int n, m;

int lowbit (int x) {
    return x & (-x);
}

int sum(int i, int j) {
    int ret = 0;
    while(i > 0) {
        ret = (ret + c[i][j]) % MOD;
        i -= lowbit(i);
    }
    return ret;
}

void add(int i, int j, int v) {
    while(i <= n) {
        c[i][j] = (c[i][j] + v) % MOD;
        i += lowbit(i);
    }
}

bool cmp(int i ,int j) {
    return a[i] < a[j];
}

int main() {
    std::ios::sync_with_stdio(false);
    int t, kase = 0; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        memset(f, 0, sizeof(f));
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i ++) r[i] = i; sort(r+1,r+1+n,cmp);
        for (int i = 1; i <= n; i ++) {
            int id = r[i];
            f[id][1] = 1; add(id, 1, 1);
            for (int j = 2; j <= m; j ++) {
                f[id][j] = sum(id-1, j-1);
                add(id, j, f[id][j]);
            }
        }
        cout << "Case #" << ++kase << ": ";
        cout << sum(n, m) << '\n';
//        cout << res << '\n';
    }
    return 0;
}

