//
//  main.cpp
//  合并果子
//
//  Created by czf on 2017/1/29.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> a, b;

int main() {
    std::ios::sync_with_stdio(false);
    int n, res = 0; cin >> n;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int L1 = 0, L2 = 0;
    while ((a.size() - L1) + (b.size() - L2) > 1) {
        int temp = 0;
        for (int i = 0; i < 2; i ++) {
            if (b.size() - L2 == 0 || (a.size() - L1 > 0 && a[L1] < b[L2])) {
                temp += a[L1++];
            } else {
                temp += b[L2++];
            }
        }
        b.push_back(temp);
        res += temp;
    }
    cout << (!L1 ? a[0] : res) << '\n';
    return 0;
}
