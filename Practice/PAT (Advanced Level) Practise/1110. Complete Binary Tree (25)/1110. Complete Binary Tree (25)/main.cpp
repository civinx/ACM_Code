//
//  main.cpp
//  1110. Complete Binary Tree (25)
//
//  Created by czf on 2016/12/7.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 50;

struct P {
    int data, lson, rson;
};

struct Node {
    int data;
    Node *lson, *rson;
    Node() : lson(NULL), rson(NULL) {}
    Node(int data) : data(data), lson(NULL), rson(NULL) {}
};

P temp[maxn];

void read(const string &s, int &lson, int &rson) {
    stringstream ss;
    size_t p = s.find(' ');
    string s1 = s.substr(0, p), s2 = s.substr(p+1, s.size());
    if (s1 == "-") lson = -1;
    else {
        ss << s1;
        ss >> lson;
        ss.clear();
    }
    if (s2 == "-") rson = -1;
    else {
        ss << s2;
        ss >> rson;
    }
}

int mp[maxn];

Node * build(int idx) {
    if (idx == -1) return NULL;
    Node * cur = new Node(idx);
    cur->lson = build(temp[idx].lson);
    cur->rson = build(temp[idx].rson);
    return cur;
}

bool check(Node * root, int &res) {
    bool flag = 0; //未出现NULL节点
    queue<Node *> q; q.push(root);
    while (!q.empty()) {
        Node * cur = q.front(); q.pop();
        if (cur == NULL) {
            flag = 1;
            continue;
        } else {
            res = cur->data;
            if (flag) return false;
            q.push(cur->lson);
            q.push(cur->rson);
        }
    }
    return true;
}

int main() {
    int n; scanf("%d",&n);
    string s; getline(cin, s);
    for (int i = 0; i < n; i ++) {
        getline(cin, s);
        read(s, temp[i].lson, temp[i].rson);
        //        printf("%d %d\n",temp[i].lson, temp[i].rson);
        if (temp[i].lson != -1) mp[temp[i].lson] = 1;
        if (temp[i].rson != -1) mp[temp[i].rson] = 1;
    }
    int rt = 0;
    for (int i = 0; i < n; i ++) {
        if (!mp[i]) {
            rt = i;
            break;
        }
    }
    Node * root = build(rt);
    int res = 0;
    bool flag = check(root, res);
    if (flag) printf("YES %d\n",res);
    else printf("NO %d\n",rt);
    return 0;
}
