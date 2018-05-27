//
//  main.cpp
//  二叉树节点的深度
//
//  Created by czf on 2017/2/24.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 1;

vector<int> G[maxn];
int d[maxn];

void dfs(int u, int dep) {
    d[u] = dep;
    for (int i = 0; i < G[u].size(); i ++) {
        int v = G[u][i];
        dfs(v, dep + 1);
    }
}

void bfs() {
    struct P { int x, dep; };
    queue<P> q; q.push((P){1, 1});
    while (!q.empty()) {
        P cur = q.front(); q.pop();
        d[cur.x] = cur.dep;
        for (int i = 0; i < G[cur.x].size(); i ++) {
            int v = G[cur.x][i];
            q.push((P){v, cur.dep+1});
        }
    }
}

int main() {
//    std::ios::sync_with_stdio(false);
//    int n; cin >> n;
    int n; scanf("%d",&n);
    for (int i = 0; i < n-1; i ++) {
//        int u, v; cin >> u >> v;
        int u, v; scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    dfs(1, 1);
//    bfs();
    for (int i = 1; i <= n; i ++) {
//        cout << i << ":" << d[i] << endl;
        printf("%d:%d\n",i,d[i]);
    }
    return 0;
}
