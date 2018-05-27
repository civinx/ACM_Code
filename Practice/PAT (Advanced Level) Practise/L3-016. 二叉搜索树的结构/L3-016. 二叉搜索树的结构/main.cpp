//
//  main.cpp
//  L3-016. 二叉搜索树的结构
//
//  Created by czf on 2017/4/20.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
struct Node {
    int data;
    Node * lson, * rson;
    Node () : lson(NULL), rson(NULL) {};
    Node (int data) : data(data), lson(NULL), rson(NULL) {};
};

typedef Node * Tree;

const int maxn = 1000000;
//int dep[maxn], fa[maxn], bro[maxn], lc[maxn], rc[maxn];
map<int, int> dep, fa, bro, lc, rc;

void init() {
//    memset(dep, 0, sizeof(dep));
//    memset(fa, -1, sizeof(fa));
//    memset(bro, -1, sizeof(bro));
//    memset(lc, -1, sizeof(lc));
//    memset(rc, -1, sizeof(rc));
    dep.clear();
    fa.clear();
    bro.clear();
    lc.clear();
    rc.clear();
}

Tree Insert(Tree cur, Tree pre, int x, int d, bool left) {
    if (cur == NULL) {
        if (pre) {
            fa[x] = pre->data;
            Node * temp = NULL;
            if (left) {
                temp = pre->rson;
                lc[pre->data] = x;
            } else {
                temp = pre->lson;
                rc[pre->data] = x;
            }
            if (temp) {
                bro[x] = temp->data;
                bro[temp->data] = x;
            }
        } else {
            fa[x] = -1;
        }
        dep[x] = d;
        cur = new Node(x);
        return cur;
    }
    if (x < cur->data) cur->lson = Insert(cur->lson, cur, x, d+1, 1);
    else cur->rson = Insert(cur->rson, cur, x, d+1, 0);
    return cur;
}

int getInt(string & s, int pos) {
    int ret = 0;
    for (int i = pos; i < s.size() && (s[i] <= '9' && s[i] >= '0'); i ++) {
        ret = ret * 10 + (s[i] - '0');
    }
    return ret;
}

const string s1 = "is the root";
const string s2 = "are siblings";
const string s3 = "are on the same level";
const string s4 = "is the parent of";
const string s5 = "is the left child of";
const string s6 = "is the right child of";


int main() {
    int n; cin >> n;
    Tree T = NULL;
    init();
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        T = Insert(T, NULL, x, 0, 0);
    }
    int m; cin >> m;
    string s;
    getline(cin, s);
    
    while (m--) {
        bool flag = 0;
        getline(cin, s);
        if (s.find(s1) != string::npos) {
            int x = getInt(s, 0);
            if (fa.count(x) && fa[x] == -1) flag = 1;
        } else if (s.find(s2) != string::npos) {
            int x = getInt(s, 0);
            int y = getInt(s, (unsigned)s.find("and") + 4);
            if (bro.count(x) && bro[x] == y) flag = 1;
        } else if (s.find(s3) != string::npos) {
            int x = getInt(s, 0);
            int y = getInt(s, (unsigned)s.find("and") + 4);
            if (dep.count(x) && dep.count(y) && dep[x] == dep[y]) flag = 1;
        } else if (s.find(s4) != string::npos) {
            int x = getInt(s, 0);
            int y = getInt(s, (unsigned)s.find("of") + 3);
            if (fa.count(y) && fa[y] == x) flag = 1;
        } else if (s.find(s5) != string::npos) {
            int x = getInt(s, 0);
            int y = getInt(s, (unsigned)s.find("of") + 3);
            if (lc.count(y) && lc[y] == x) flag = 1;
        } else if (s.find(s6) != string::npos) {
            int x = getInt(s, 0);
            int y = getInt(s, (unsigned)s.find("of") + 3);
            if (rc.count(y) && rc[y] == x) flag = 1;
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
