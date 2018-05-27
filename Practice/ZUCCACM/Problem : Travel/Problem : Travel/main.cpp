//
//  main.cpp
//  Problem : Travel
//
//  Created by czf on 16/5/25.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 0xfffffff;
const int maxn = 100 + 10;
int d[maxn][maxn];
int n, m;

struct Edge {
    int from, to;
};

struct P {
    int num, dist;
};

vector<int> G[maxn];
vector<Edge> edge;

void add(int from, int to) {
    edge.push_back((Edge){from, to});
    int m = (int)edge.size() - 1;
    G[from].push_back(m);
}

void init() {
    for (int i = 0; i < maxn; i ++) G[i].clear();
    for (int i = 0; i < maxn; i ++) {
        for (int j = 0; j < maxn; j ++) {
            d[i][j] = (i == j ? 0 : inf);
        }
    }
    edge.clear();
}

int bfs(int star) {
    queue<P> q; q.push((P){star, 0});
    while (!q.empty()) {
        P cur = q.front(); q.pop();
        int from = cur.num;
        for (int i = 0; i < G[from].size(); i ++) {
            Edge &e = edge[G[from][i]];
            int to = e.to;
            if (cur.dist + 1 < d[star][to]) {
                d[star][to] = cur.dist + 1;
                q.push((P){to, d[star][to]});
            }
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i ++) ret += d[star][i];
    return ret;
}

int solve(int x, int sum) {
    int star = edge[x].from, end = edge[x].to;
    queue<P> q; q.push((P){star, 0});
    int pre = d[star][end];
    for (int i = 0; i < maxn; i ++) d[star][i] = inf;
    while (!q.empty()) {
        P cur = q.front(); q.pop();
        if (cur.num == end) break;
        int from = cur.num;
        for (int i = 0; i < G[from].size(); i ++) {
            if (G[from][i] == x || G[from][i] == x+1) continue;
            Edge &e = edge[G[from][i]];
            int to = e.to;
            if (cur.dist + 1 < d[star][to]) {
                d[star][to] = cur.dist + 1;
                q.push((P){to, d[star][to]});
            }
        }
    }
    if (d[star][end] == inf) return -1;
    return sum + 2 * (d[star][end] - pre);
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    while (cin >> n >> m) {
        init();
        for (int i = 0; i < m; i ++) {
            int from, to; cin >> from >> to;
            add(from, to); add(to, from);
        }
        int sum = 0;
        bool flag = 0;
        for (int i = 1; i <= n; i ++) {
            int ret = bfs(i);
            if (ret == -1) { flag = 1; break; }
            sum += ret;
        }
        for (int i = 0; i < edge.size(); i += 2) {
            if (flag) cout << "INF" << '\n';
            else {
                int x = solve(i, sum);
                if (x == -1) cout << "INF" << '\n';
                else cout << x << '\n';
            }
        }
    }
    return 0;
}

