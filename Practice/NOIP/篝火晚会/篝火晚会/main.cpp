//
//  main.cpp
//  篝火晚会
//
//  Created by czf on 2017/1/31.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 55555;

vector<int> G[maxn];
vector<int> cir;

bool vis[maxn];
int a[maxn], b[maxn];

bool build(int n) {
    cir.push_back(0);
    vis[0] = 1;
    int cur = cir.back();
    while (cir.size() < n) {
        int x1 = G[cur][0], x2 = G[cur][1];
        if (vis[x1] && vis[x2]) break;
        int next = (!vis[x1] ? x1 : x2);
        cir.push_back(next);
        vis[next] = 1;
        cur = next;
    }
    return cir.size() == n;
}

int solve(int n) {
    for (int i = 0; i < n; i ++) {
        a[(cir[i]-i+n)%n] ++;
        int j = n - i - 1;
        b[(cir[j]-i+n)%n] ++;
    }
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        ans = max(ans, max(a[i], b[i]));
    }
    return n - ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; i ++) {
        int x1, x2; cin >> x1 >> x2;
        x1 --; x2 --;
        G[i].push_back(x1);
        G[i].push_back(x2);
    }
    if (!build(n)) {
        cout << -1 << '\n';
    } else {
        cout << solve(n) << '\n';
    }
    return 0;
}
