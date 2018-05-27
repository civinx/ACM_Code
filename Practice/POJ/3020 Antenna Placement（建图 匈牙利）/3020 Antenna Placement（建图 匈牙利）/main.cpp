//
//  main.cpp
//  3020 Antenna Placement（建图 匈牙利）
//
//  Created by czf on 16/5/17.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 500;
const int maxm = 100 * 100;
int num[maxn][maxn], n, m; //num记录二分图两边的编号
bool kind[maxn][maxn];//Kind区分图中的点属于二分图的哪一边
string pic[maxn];//保存图
vector<int> G[maxm];//保存二分图左边的点到右边的边

bool use[maxm];
int ok[maxm];

void Init(int n, int m) {
    for (int i = 0; i < maxm; i ++) G[i].clear();
    for (int i = 0; i < maxn; i ++) pic[i].clear();
//    cout << "test" << endl;
    memset(num, 0, sizeof(num));
    memset(kind, 0, sizeof(kind));
    memset(ok, 0, sizeof(ok));
    kind[0][1] = 0;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            kind[i][j] = (j == 1 ? !kind[i-1][j] : !kind[i][j-1]);
            if (kind[i][j]) num[i][j] = ++cnt1;
            else num[i][j] = ++cnt0;
        }
    }
}

void Check(int i, int j) {
    if (kind[i][j] == 1 && pic[i][j] == '*') {
        int left = num[i][j];
        if (i < n && pic[i+1][j] == '*') G[left].push_back(num[i+1][j]);
        if (pic[i-1][j] == '*') G[left].push_back(num[i-1][j]);
        if (j < m && pic[i][j+1] == '*') G[left].push_back(num[i][j+1]);
        if (pic[i][j-1] == '*') G[left].push_back(num[i][j-1]);
    }
}

bool solve(int x) {
    int len = (int)G[x].size();
    for (int i = 0; i < len; i ++) if (use[G[x][i]] == 0) {
        int to = G[x][i];
        use[to] = 1;
        if (ok[to] == 0 || solve(ok[to])) {
            ok[to] = x;
            return true;
        }
    }
    return false;
}

int main() {
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        Init(n, m);
        string temp;
        for (int i = 0; i <= m; i ++)
            pic[0] += ' ';
        for (int i = 1; i <= n; i ++) {
            pic[i] += 'o';
            cin >> temp;
            pic[i] += temp;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                Check(i , j);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1 ; j <= m; j ++) {
                if (pic[i][j] == '*') res ++;
//                cout << pic[i][j] << '\n';
            }
        }
        int cnt = 0, max_num = (n * m + 1) / 2;
        for (int i = 1; i <= max_num; i ++) {
            memset(use, 0, sizeof(use));
            if (solve(i)) cnt ++;
        }
        cout << res - cnt << '\n';
    }
    return 0;
}
