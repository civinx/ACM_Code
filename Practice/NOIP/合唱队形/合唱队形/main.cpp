//
//  main.cpp
//  合唱队形
//
//  Created by czf on 2017/1/29.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 111;
const int INF = 0x3f3f3f3f;
int a[maxn], b[maxn], c[maxn];

void getup(int n) {
    for (int i = 1; i <= n; i ++) {
        int temp = 0;
        for (int j = 1; j < i; j ++) {
            if (a[j] < a[i]) temp = max(temp, b[j]);
        }
        b[i] = temp + 1;
    }
}

void getdown(int n) {
    for (int i = n; i >= 1; i --) {
        int temp = 0;
        for (int j = n; j > i; j --) {
            if (a[j] < a[i]) temp = max(temp, c[j]);
        }
        c[i] = temp + 1;
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    getup(n);
    getdown(n);
    int res = INF;
    for (int i = 1; i <= n; i ++) {
        res = min(res, n - (b[i] + c[i]) + 1);
    }
    cout << res << '\n';
    return 0;
}
