//
//  main.cpp
//  爱恨分明
//
//  Created by czf on 2017/3/17.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

const int maxn = 1e5 + 10;
//const int MOD = 1e6 + 10;

int root[maxn<<1];

int find(int x) {
    return x == root[x] ? x : root[x] = find(root[x]);
}

unordered_map<string, int> mp;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) {
        string s; cin >> s;
        mp[s] = i;
    }
    int N = n << 1;
    for (int i = 1; i <= N; i ++) root[i] = i;
    while (m--) {
        int op; string s1, s2; cin >> op >> s1 >> s2;
        int x = mp[s1], y = mp[s2];
        if (op == 1) {
            if (find(x) == find(y+n)) {
                cout << "NO" << '\n';
                continue;
            }
            root[find(x)] = find(y);
            root[find(x+n)] = find(y+n);
        } else {
            if (find(x) == find(y)) {
                cout << "NO" << '\n';
                continue;
            }
            root[find(x)] = find(y+n);
            root[find(y)] = find(x+n);
        }
        cout << "YES" << '\n';
    }
    while (q--) {
        string s1, s2; cin >> s1 >> s2;
        int x = mp[s1], y = mp[s2];
        if (find(x) == find(y)) {
            cout << 1;
        } else if (find(x) == find(y+n)) {
            cout << 2;
        } else {
            cout << 3;
        }
        cout << '\n';
    }
    return 0;
}
