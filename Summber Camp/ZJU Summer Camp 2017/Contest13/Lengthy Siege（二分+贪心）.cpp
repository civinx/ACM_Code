//
//  main.cpp
//  E
//
//  Created by czf on 2016/12/24.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;
//const int maxn = 100;


priority_queue<int, vector<int>, greater<int> > q1;
priority_queue<int, vector<int>, greater<int> > q2;

int a[maxn], b[maxn], n, m, k;

void init() {
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
}

bool check(int x) {
    init();
    if (x >= n) return false;
    for (int i = 0; i < x; i ++) q1.push(a[n-i-1]);
    for (int i = 0; i < x; i ++) q2.push(b[i]);
    int cnt = 0;
    while (!q2.empty()) {
        if (q1.empty()) return false;
        while (q1.top() < q2.top()) {
            cnt ++;
            if (cnt > n-1) return false;
            int cur = q1.top(); q1.pop();
            cur += k; q1.push(cur);
        }
        q1.pop();
        q2.pop();
    }
    return true;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int res = 0; scanf("%d%d%d",&n,&m,&k);
        for (int i = 0; i < n; i ++) scanf("%d",&a[i]);
        sort(a, a + n);
        int cnt = 0;
        for (int i = 0; i < m; i ++) {
            int x; scanf("%d",&x);
            if (x > a[n-1]) b[cnt++] = x;
            else res ++;
        }
        sort(b, b + cnt);
        int L = 0, R = cnt;
        while (L < R) {
            int mid = (L + R + 1) / 2;
            if (check(mid)) L = mid;
            else R = mid - 1;
        }
        printf("%d\n",res + L);
    }
    return 0;
}

