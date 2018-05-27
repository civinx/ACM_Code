//
//  main.cpp
//  神经网络
//
//  Created by czf on 2017/1/26.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 111;

struct Edge { int to, val; };
struct Point { int c, u; Point () : c(0), u(0) {} };

//Point a[maxn];
int a[maxn], in[maxn];
vector<int> G[maxn];
vector<Edge> edges;

void AddEdge(int from, int to, int val) {
    edges.push_back((Edge){to, val});
    int m = (int)edges.size() - 1;
    G[from].push_back(m);
}

void work(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i ++) {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < G[cur].size(); i ++) {
            Edge &e = edges[G[cur][i]];
            int to = e.to;
            a[to] += e.val * a[cur];
            if (--in[to] == 0 && a[to] > 0) {
                q.push(to);
            }
        }
    }
    bool flag = false;
    for (int i = 1; i <= n; i ++) {
        if (G[i].size() == 0 && a[i] > 0) {
            cout << i << " " << a[i] << '\n';
            flag = true;
        }
    }
    if (!flag) cout << "NULL" << '\n';
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int c, u; cin >> c >> u;
        if (c <= 0) c -= u;
        a[i] = c;
    }
    for (int i = 1; i <= m; i ++) {
        int from, to, val; cin >> from >> to >> val;
        AddEdge(from, to, val);
        in[to] ++;
    }
    work(n);
}
