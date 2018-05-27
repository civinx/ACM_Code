//
//  main.cpp
//  关押罪犯
//
//  Created by czf on 2017/2/10.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 20000 + 100;
const int maxm = 100000 + 100;
int root[maxn<<1];

int find(int x) {
    return x == root[x] ? x : root[x] = find(root[x]);
}

struct Edge {
    int u, v, cost;
    bool operator > (const Edge & rhs) const {
        return cost > rhs.cost;
    }
};

Edge a[maxm];

int main() {
    std::ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int N = n << 1;
    for (int i = 1; i <= N; i ++) root[i] = i;
    for (int i = 0; i < m; i ++) {
        cin >> a[i].u >> a[i].v >> a[i].cost;
    }
    sort(a, a+m, greater<Edge>());
    
    bool flag = 0;
    for (int i = 0; i < m; i ++) {
        int u = a[i].u, v = a[i].v;
        int x = find(u), y = find(v);
        if (x == y) {
            cout << a[i].cost << '\n';
            flag = 1;
            break;
        }
        root[x] = find(v + n);
        root[y] = find(u + n);
    }
    if (!flag) cout << 0 << '\n';
    return 0;
}
