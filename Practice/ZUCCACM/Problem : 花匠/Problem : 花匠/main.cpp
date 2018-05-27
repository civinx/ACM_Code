//
//  main.cpp
//  Problem : 花匠
//
//  Created by czf on 2016/10/10.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
using namespace std;
const int MAXN = 1000000 + 100;
int a[MAXN], n;

inline void FindMin(int &i) {
    while (i+1 <= n && a[i] >= a[i+1]) i ++;
}

inline void FindMax(int &i) {
    while (i+1 <= n && a[i] <= a[i+1]) i ++;
}

int main() {
    std::ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 1; i <= n; i ++) cin >> a[i];
        int cnt = 0, res = 0, op = 1;
        for (int i = 1; i <= n; i ++) {
            if (op) FindMax(i), op ^= 1;
            else FindMin(i), op ^= 1;
            cnt ++;
        }
        res = max(res, cnt);
        cnt = 0, op = 0;
        for (int i = 1; i <= n; i ++) {
            if (op) FindMax(i), op ^= 1;
            else FindMin(i), op ^= 1;
            cnt ++;
        }
        res = max(res, cnt);
        cout << res << '\n';
    }
    return 0;
}
