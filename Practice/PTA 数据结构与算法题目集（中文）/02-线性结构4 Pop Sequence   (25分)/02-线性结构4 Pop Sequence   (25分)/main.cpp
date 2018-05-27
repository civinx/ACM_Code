//
//  main.cpp
//  02-线性结构4 Pop Sequence   (25分)
//
//  Created by czf on 16/9/25.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
const int maxn = 1000 + 100;
int a[maxn], m, n, k;


bool check() {
    stack<int> s;
    int cnt = 1;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        s.push(i);
        if (s.size() > m) return false;
        while (!s.empty() && s.top() == a[cnt]) {
            s.pop();
            cnt ++;
        }
    }
    return s.empty();
}

int main() {
    cin >> m >> n >> k;
    while (k--) {
        if (check()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
