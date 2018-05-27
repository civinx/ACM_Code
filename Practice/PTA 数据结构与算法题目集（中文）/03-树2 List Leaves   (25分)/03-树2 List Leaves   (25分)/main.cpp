//
//  main.cpp
//  03-树2 List Leaves   (25分)
//
//  Created by czf on 16/9/25.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 15;

struct Node {
    int data;
    Node *lson, *rson;
    Node(int data = -1, Node *lson = NULL, Node *rson = NULL) : data(data), lson(lson), rson(rson) {}
};

Node *pos[maxn];
bool vis[maxn];
bool flag = 0;
void bfs(Node *cur) {
    queue<Node*> q;
    q.push(cur);
    while (!q.empty()) {
        cur = q.front(); q.pop();
        if (cur->lson == NULL && cur->rson == NULL) {
            if (!flag) flag = 1;
            else printf(" ");
            printf("%d",cur->data);
            continue;
        }
        if (cur->lson) q.push(cur->lson);
        if (cur->rson) q.push(cur->rson);
    }
    printf("\n");
}

int main() {
    int n; scanf("%d",&n);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i ++) {
        pos[i] = new Node(i);
    }
    for (int i = 0; i < n; i ++) {
        char c1, c2; scanf("\n%c %c",&c1,&c2);
        int l = -1, r = -1;
        if (isdigit(c1)) l = c1 - '0', vis[l] = 1;
        if (isdigit(c2)) r = c2 - '0', vis[r] = 1;
        pos[i]->lson = (l == -1 ? NULL : pos[l]);
        pos[i]->rson = (r == -1 ? NULL : pos[r]);
    }
    for (int i = 0; i < n; i ++) {
        if (!vis[i]) {
            bfs(pos[i]);
            break;
        }
    }
    return 0;
}