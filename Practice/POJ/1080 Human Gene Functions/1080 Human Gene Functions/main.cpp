//
//  main.cpp
//  1080 Human Gene Functions
//
//  Created by czf on 2017/5/10.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn = 10;
const int maxm = 100 + 10;
const int pic[maxn][maxn] = {
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};

const char g[maxn] = "ACGT-";
map<char, int> mp;
int f[maxm][maxm];

void init() {
    for (int i = 0; i < 5; i ++) mp[g[i]] = i;
}

int main() {
    init();
    int T; cin >> T;
    while (T--) {
        int n, m; string s1, s2;
        cin >> n >> s1;
        cin >> m >> s2;
        s1 = " " + s1;
        s2 = " " + s2;
        f[0][0] = 0;
        for (int i = 1; i <= n; i ++) {
            int x1 = mp[s1[i]], x2 = mp['-'];
            f[i][0] = f[i-1][0] + pic[x1][x2];
        }
        for (int i = 1; i <= m; i ++) {
            int x1 = mp[s2[i]], x2 = mp['-'];
            f[0][i] = f[0][i-1] + pic[x1][x2];
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                int x1 = mp[s1[i]], x2 = mp[s2[j]];
                int g1 = f[i-1][j-1] + pic[x1][x2];
                int g2 = f[i-1][j] + pic[x1][mp['-']];
                int g3 = f[i][j-1] + pic[x2][mp['-']];
                f[i][j] = max(g1, max(g2, g3));
            }
        }
        cout << f[n][m] << '\n';
    }
    return 0;
}
