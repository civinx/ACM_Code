//
//  main.cpp
//  二叉树后序中序得出层序
//
//  Created by czf on 16/6/4.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <set>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Node *LNode;
const int maxn = 1000000;
struct Node {
    int data;
    LNode left, right;
    Node() : left(NULL), right(NULL) {}
};

int z[maxn], h[maxn], pz[maxn], ph[maxn], n;
bool ans[maxn];
bool flag = 1;
set<int> s;

LNode solve(int l, int r) {
    if (l > r) return NULL;
    int root = *s.begin();
    for (int i = 1; i <= n; i ++) {
        int x = h[i];
        if (ph[x] > ph[root] && s.count(x)) root = x;
    }
    s.clear();
    LNode T = new Node; T->data = root;
    for (int i = l; i < pz[root]; i ++) if (ans[z[i]]) s.insert(z[i]);
    T->left = solve(l, pz[root]-1);
    s.clear();
    for (int i = pz[root]+1; i <= r; i ++) if (ans[z[i]]) s.insert(z[i]);
    T->right = solve(pz[root]+1, r);
    return T;
}

void bfs(LNode T) {
    queue<LNode> q;
    q.push(T);
    while (!q.empty()) {
        LNode cur = q.front(); q.pop();
        if (cur == NULL) continue;
        if (flag) flag = 0;
        else cout << " ";
        cout << cur->data;
        q.push(cur->left);
        q.push(cur->right);
    }
    cout << '\n';
}

void test1(LNode T) {
    if (!T) return;
    test1(T->left);
    test1(T->right);
    cout << T->data << " ";
}

void test2(LNode T) {
    if (!T) return;
    test2(T->left);
    cout << T->data << " ";
    test2(T->right);
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    memset(ans, 0, sizeof(ans));
    cin >> n;
    flag = 1;
    s.clear();
    for (int i = 1; i <= n; i ++) { cin >> h[i]; ph[h[i]] = i; ans[h[i]] = 1; }
    for (int i = 1; i <= n; i ++) { cin >> z[i]; pz[z[i]] = i; }
    for (int i = 1; i <= n; i ++) s.insert(h[i]);
    LNode T = solve(1, n);
    bfs(T);
    //    test1(T); cout << '\n';
    //    test2(T); cout << '\n';
    return 0;
}

