//
//  main.cpp
//  传染病控制
//
//  Created by czf on 2017/1/29.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 333;
const int INF = 0x3f3f3f3f;

int n, m, a[maxn], cnt, res = INF;
vector<int> G[maxn];

//修剪一下树
void init() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < G[i].size(); j ++) {
            int to = G[i][j];
            for (int k = 0; k < G[to].size(); k ++) {
                if (G[to][k] == i) {
                    swap(G[to][k], G[to][G[to].size()-1]);
                    G[to].pop_back();
                    break;
                }
            }
        }
    }
    a[1] = 1;
    cnt = 1;
}

void dfs(int cur) {
    if (cnt >= res) return;
    bool flag = 1;
    //找出下一层的点
    for (int i = 1; i <= n; i ++) {
        if (a[i] != cur) continue;
        for (int j = 0; j < G[i].size(); j ++) {
            a[G[i][j]] = cur + 1;
            cnt ++;
            flag = 0;
        }
    }
    
    //枚举下一层不要的点
    cnt --;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == cur + 1) {
            a[i] = 0;
            dfs(cur + 1);
            a[i] = cur + 1;
        }
    }
    cnt ++;
    
    //边界状态
    if (flag) {
        res = min(cnt, res);
    }
    
    //回溯, 由于该层完成了自己在某种情况下的使命, 马上要被上层修改, 相应的, 它的下层需被抹掉
    for (int i = 1; i <= n; i ++) {
        if (a[i] == cur + 1) {
            a[i] = 0;
            cnt --;
        }
    }
    
    
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init();
    dfs(1);
    cout << res << '\n';
    return 0;
}
