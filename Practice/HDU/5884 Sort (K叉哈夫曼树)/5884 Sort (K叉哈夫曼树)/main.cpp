//
//  main.cpp
//  5884 Sort (K叉哈夫曼树)
//
//  Created by czf on 16/9/19.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 100;
const int inf = 0x7fffffff;

int a[maxn], n, T;

bool check(int k) {
    int cnt = 0;
    queue<int> q1, q2;
    int mod = (n-1) % (k-1);
    if (mod) {
        for (int i = 0; i < k - 1 - mod; i ++) q1.push(0);
    }
    for (int i = 0; i < n; i ++) q1.push(a[i]);
    while (1) {
        int temp = 0;
        for (int i = 0; i < k; i ++) {
            int x1 = inf, x2 = inf;
            if (!q1.empty()) x1 = q1.front();
            if (!q2.empty()) x2 = q2.front();
            if (x1 < x2) {
                temp += x1;
                q1.pop();
            } else {
                temp += x2;
                q2.pop();
            }
        }
        cnt += temp;
        if (q1.empty() && q2.empty()) break;
        q2.push(temp);
    }
    return cnt <= T;
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&T);
        for (int i = 0; i < n; i ++) scanf("%d",&a[i]);
        sort(a, a+n);
        int l = 1, r = n;
        while (l < r) {
            int m = (l + r) >> 1;
            if (check(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}