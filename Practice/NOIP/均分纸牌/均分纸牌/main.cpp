//
//  main.cpp
//  均分纸牌
//
//  Created by czf on 2017/1/25.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 111;

int a[maxn];

int main() {
    std::ios::sync_with_stdio(false);
    int n; cin >> n;
    int sum = 0, res = 0, avg;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    avg = sum / n;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == avg) continue;
        else if (a[i] < avg) {
            a[i+1] -= avg - a[i];
        } else {
            a[i+1] += a[i] - avg;
        }
        a[i] = avg;
        res ++;
    }
    cout << res << '\n';
    return 0;
}
