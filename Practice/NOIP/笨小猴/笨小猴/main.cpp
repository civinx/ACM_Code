//
//  main.cpp
//  笨小猴
//
//  Created by czf on 2017/2/4.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 30;
int a[maxn];

bool check(int x) {
    if (x <= 1) return false;
    int end = (int)sqrt(x+0.5);
    for (int i = 2; i <= end; i ++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    string s; cin >> s;
    for (int i = 0; i < s.size(); i ++) {
        a[s[i]-'a'] ++;
    }
    int mi = 200, mx = 0;
    for (int i = 0; i < 26; i ++) {
        if (!a[i]) continue;
        mi = min(mi, a[i]);
        mx = max(mx, a[i]);
    }
    if (check(mx - mi)) {
        cout << "Lucky Word\n" << mx - mi << endl;
    } else {
        cout << "No Answer\n" << 0 << endl;
    }
    return 0;
}
