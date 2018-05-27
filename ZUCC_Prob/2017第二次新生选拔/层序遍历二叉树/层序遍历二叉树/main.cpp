//
//  main.cpp
//  层序遍历二叉树
//
//  Created by czf on 2017/4/1.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 1;

vector<int> G[maxn];

void bfs() {
    queue<int> q; q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur != 1) printf(" ");
        printf("%d",cur);
        for (int i = 0; i < G[cur].size(); i ++) {
            int v = G[cur][i];
            q.push(v);
        }
    }
    printf("\n");
}

int main() {
    int n; scanf("%d",&n);
    for (int i = 0; i < n-1; i ++) {
        int u, v; scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    bfs();
    return 0;
}
