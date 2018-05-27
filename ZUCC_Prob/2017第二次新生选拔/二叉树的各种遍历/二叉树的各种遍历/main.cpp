//
//  main.cpp
//  二叉树的各种遍历
//
//  Created by czf on 2017/4/10.
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

bool flag = 0;

void pre(int x) {
    if (!flag) flag = 1;
    else printf(" ");
    printf("%d",x);
    if (G[x].size() >= 1) pre(G[x][0]);
    if (G[x].size() == 2) pre(G[x][1]);
}

void in(int x) {
    if (G[x].size() >= 1) in(G[x][0]);
    if (!flag) flag = 1;
    else printf(" ");
    printf("%d",x);
    if (G[x].size() == 2) in(G[x][1]);
}

void pos(int x) {
    if (G[x].size() >= 1) pos(G[x][0]);
    if (G[x].size() == 2) pos(G[x][1]);
    if (!flag) flag = 1;
    else printf(" ");
    printf("%d",x);
}

int main() {
    int n; scanf("%d",&n);
    for (int i = 0; i < n-1; i ++) {
        int u, v; scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    bfs();
    flag = 0;
    pre(1); printf("\n");
    flag = 0;
    in(1); printf("\n");
    flag = 0;
    pos(1); printf("\n");
    return 0;
}

