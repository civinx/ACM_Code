//
//  main.cpp
//  Skip the Class
//
//  Created by czf on 2017/3/14.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
const int maxn = 111;

map<string, int> mp;

struct P {
    string s; int v;
    bool operator < (const P & lhs) const {
        return v > lhs.v;
    }
}a[maxn];

int main() {
    std::ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        mp.clear();
        int n; cin >> n;
        for (int i = 0; i < n; i ++) {
            cin >> a[i].s >> a[i].v;
        }
        sort(a, a+n);
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            if (mp[a[i].s] < 2) {
                sum += a[i].v;
                mp[a[i].s] ++;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
