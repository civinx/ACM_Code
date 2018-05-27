//
//  main.cpp
//  5862 Counting Intersections (树状数组 离散)
//
//  Created by czf on 16/8/25.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200000 + 100;

struct P {
    int type, x, y1, y2;
    bool operator < (const P &rhs) const{
        if (x == rhs.x) return type < rhs.type;
        return x < rhs.x;
    }
} node[maxn];

int y[maxn], c[maxn];
map<int, int > mp;

inline int lowbit(int x) {
    return x & (-x);
}

void add(int x, int v, int n) {
    for (int i = x; i <= n; i += lowbit(i)) {
        c[i] += v;
    }
}

int sum(int x, int n) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ret += c[i];
    }
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(c, 0, sizeof(c));
        int n; cin >> n;
        int cy = 0, cnode = 0;
        for (int i = 0; i < n; i ++) {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2) {
                if (y1 > y2) swap(y1, y2);
                node[cnode++] = {1, x1, y1, y2};
                y[cy++] = y1;
                y[cy++] = y2;
            } else {
                if (x1 > x2) swap(x1, x2);
                node[cnode++] = {0, x1, y1, 1};
                node[cnode++] = {0, x2+1, y1, -1};
                y[cy++] = y1;
            }
        }
        sort(y, y+cy);
        int cnt = 0; mp.clear();
        for (int i = 0; i < cy; i ++) {
            if (!mp[y[i]]) mp[y[i]] = ++cnt;
        }
        sort(node, node+cnode);
        long long res = 0;
        for (int i = 0; i < cnode; i ++) {
            if (node[i].type)
                res += sum(mp[node[i].y2], cnt) - sum(mp[node[i].y1]-1, cnt);
            else
                add(mp[node[i].y1], node[i].y2, cnt);
        }
        cout << res << '\n';
    }
    return 0;
}
