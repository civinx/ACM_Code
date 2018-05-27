//
//  main.cpp
//  作业调度方案
//
//  Created by czf on 2017/2/2.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 22;

int seq[maxn*maxn], cnt[maxn], order[maxn][maxn], cost[maxn][maxn], last[maxn], n, m;

bool used[maxn][maxn*maxn*maxn*maxn];

void read() {
    cin >> m >> n;
    for (int i = 0; i < n * m; i ++) {
        cin >> seq[i];
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> order[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> cost[i][j];
        }
    }
}

bool check(int st, int end, int id, int m_id) {
    for (int i = st; i <= end; i ++) {
        if (used[m_id][i]) return false;
    }
    
    for (int i = st; i <= end; i ++) {
        used[m_id][i] = 1;
    }
    last[id] = end;
    return true;
}

void solve() {
    for (int i = 0; i < n * m; i ++) {
        //id表示工件, times表示要做的是第几次工序, m_id表示这次工序用哪一台机器
        int id = seq[i], times = cnt[id], m_id = order[id][times];
        for (int j = last[id]+1; ; j ++) {
            if (check(j, j+cost[id][times]-1, id, m_id)) break;
        }
        cnt[id]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        res = max(res, last[i]);
    }
    cout << res << '\n';
}

int main() {
    read();
    solve();
    return 0;
}
