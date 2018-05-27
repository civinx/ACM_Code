//
//  main.cpp
//  机器翻译
//
//  Created by czf on 2017/2/9.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1111;
queue<int> q;
int cache[maxn];

int main() {
    int m, n; cin >> m >> n;
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        if (!cache[x]) {
            if (q.size() >= m) {
                cache[q.front()] = 0;
                q.pop();
            }
            q.push(x);
            cache[x] = 1;
            cnt ++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
