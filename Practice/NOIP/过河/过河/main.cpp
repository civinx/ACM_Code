//
//  main.cpp
//  过河
//
//  Created by czf on 2017/1/30.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 11111;
const int INF = 0x3f3f3f3f;
const int dis = 90;

int isStone[maxn], dp[maxn];
vector<int> stone;

int solve(int x) {
    int ret = 0;
    for (int i = 0; i < stone.size(); i ++) {
        if (stone[i] % x == 0) ret ++;
    }
    return ret;
}

int main() {
    int L, s, t, n; cin >> L >> s >> t >> n;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        stone.push_back(x);
    }
    if (s == t) {
        cout << solve(s) << '\n';
        return 0;
    }
    sort(stone.begin(), stone.end());
    int d = 0;
    if (stone[0] > dis) d += stone[0] - dis, stone[0] = dis;
    for (int i = 1; i < stone.size(); i ++) {
        stone[i] -= d;
        if (stone[i] - stone[i-1] > dis) {
            d += stone[i] - stone[i-1] - dis;
            stone[i] = stone[i-1] + dis;
        }
    }
    
    for (int i = 0; i < stone.size(); i ++) {
        isStone[stone[i]] = 1;
    }
    
    L = stone.back() + t;
    
    for (int i = 0; i <= L; i ++) {
        dp[i] = (i ? INF : 0);
    }
    for (int i = s; i <= L; i ++) {
        for (int j = s; j <= t; j ++) {
            dp[i] = min(dp[i], dp[i-j] + isStone[i]);
        }
    }
    int res = INF;
    for (int i = L; i >= L - t; i --) {
        res = min(res, dp[i]);
    }
    cout << res << '\n';
    return 0;
}
