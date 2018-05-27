//
//  main.cpp
//  Problem : Trees on the level
//
//  Created by czf on 16/5/4.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
char s[100];

struct Node {
    bool vis;
    int v;
    Node *left, *right;
    Node() : vis(false), left(NULL), right(NULL) {}
};

Node *root;
bool failed; //有重复节点

Node * newnode() {
    return new Node();
}

void addnode(int v, char *s) {
    int n = (int)strlen(s);
    Node *u = root;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'L') {
            if (u->left == NULL) u->left = newnode();
            u = u->left;
        } else if (s[i] == 'R') {
            if (u->right == NULL) u->right = newnode();
            u = u->right;
        }
    }
    if (u->vis == true) failed = true;
    u->v = v;
    u->vis = true;
}

bool read_input() {
    root = newnode();
    failed = false;
    while (1) {
        if (scanf("%s",s) != 1) return false;
        if (!strcmp(s, "()")) break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',') + 1);
    }
    return true;
}

bool bfs(vector<int> &res) {
    queue<Node*> q;
    res.clear();
    q.push(root);
    while (!q.empty()) {
        Node *u = q.front(); q.pop();
        if (u->vis == false) return false; //有缺少的节点
        res.push_back(u->v);
        if (u->left != NULL) q.push(u->left);
        if (u->right != NULL) q.push(u->right);
    }
    return true;
}

int main() {
    while (read_input()) {
        vector<int> res;
        if (failed || bfs(res) == false) printf("not complete\n");
        else {
            for (int i = 0; i < res.size(); i ++)
                printf("%d%c",res[i],i == res.size()-1 ? '\n' : ' ');
        }
    }
    return 0;
}