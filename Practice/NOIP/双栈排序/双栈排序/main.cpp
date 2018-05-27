//
//  main.cpp
//  双栈排序
//
//  Created by czf on 2017/2/7.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1111;
const int INF = 0x3f3f3f3f;
int a[maxn], c[maxn];

vector<int> G[maxn];

bool flag;

void dfs(int cur, int color) {
    c[cur] = color;
    for (int i = 0; i < G[cur].size(); i ++) {
        if (!flag) return;
        int to = G[cur][i];
        if (c[to] == color) {
            flag = false;
            return;
        }
        if (!c[to]) dfs(to, 3 - color);
    }
}

void solve(int n) {
    stack<int> A, B;
    int need = 1;
    for (int i = 1; i <= n; i ++) {
        if (i != 1) cout << " ";
        if (c[i] == 1) {
            A.push(a[i]);
            cout << "a";
        } else {
            B.push(a[i]);
            cout << "c";
        }
        while ((!A.empty() && A.top() == need) || (!B.empty() && B.top() == need)) {
            if (!A.empty() && A.top() == need) {
                A.pop();
                cout << " b";
            } else {
                B.pop();
                cout << " d";
            }
            need ++;
        }
    }
    cout << '\n';
}

int f[maxn];

void init(int n) {
    f[n+1] = INF;
    for (int i = n; i >= 1; i --) {
        f[i] = min(f[i+1], a[i]);
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = i+1; j <= n; j ++) {
            if (a[i] < a[j] && f[j+1] < a[i]) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
}


int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    init(n);
    flag = true;
    for (int i = 1; i <= n; i ++) {
        if (!c[i] && flag) dfs(i, 1);
    }
    if (!flag) cout << 0 << '\n';
    else solve(n);
    return 0;
}
