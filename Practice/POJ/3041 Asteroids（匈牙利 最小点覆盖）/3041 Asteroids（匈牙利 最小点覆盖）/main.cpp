//
//  main.cpp
//  3041 Asteroids（匈牙利 最小点覆盖）
//
//  Created by czf on 16/5/16.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 500 + 100;
vector<int> G[maxn];
bool vis[maxn];
int ans[maxn];

void Init() {
    for (int i = 0; i < maxn; i ++) G[i].clear();
    memset(ans, 0, sizeof(ans));
}

bool solve(int x) {
    int len = (int)G[x].size();
    for (int i = 0; i < len; i ++) if (vis[G[x][i]] == 0){
        int to = G[x][i];
        vis[to] = 1;
        if (ans[to] == 0 || solve(ans[to])) {
            ans[to] = x;
            return true;
        }
    }
    return false;
}

int main() {
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m) {
        Init();
        for (int i = 0; i < m; i ++) {
            int x, y; cin >> x >> y;
            G[x].push_back(y);
        }
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            memset(vis, 0, sizeof(vis));
            if (solve(i)) res ++;
        }
        cout << res << '\n';
    }
    return 0;
}
