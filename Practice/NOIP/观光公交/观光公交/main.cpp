//
//  main.cpp
//  观光公交
//
//  Created by czf on 2017/2/22.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
const int maxn = 1000 + 100;
const int maxm = 10000 + 100;
using namespace std;

struct P {
    int t, u, v;
} a[maxm];

int d[maxn], ar[maxn], last[maxn], R[maxn], sum[maxn];
int n, m, k;

void Update() {
    for (int i = 1; i <= n; i ++) {
        ar[i] = max(ar[i-1], last[i-1]) + d[i-1];
    }
}

void Read() {
    cin >> n >> m >> k;
    for (int i = 1; i < n; i ++) cin >> d[i];
    for (int i = 1; i <= m; i ++) { cin >> a[i].t >> a[i].u >> a[i].v; sum[a[i].v] ++; last[a[i].u] = max(last[a[i].u], a[i].t); }
    for (int i = 2; i <= n; i ++) {
        sum[i] += sum[i-1];
    }
}


int main() {
    Read();
    int ans = 0;
    Update();
    for (int i = 1; i <= m; i ++) {
        ans += ar[a[i].v] - a[i].t;
    }
    while (k--) {
        R[n] = n;
        for (int i = n-1; i >= 1; i --) {
            if (ar[i+1] > last[i+1]) {
                R[i] = R[i+1];
            } else {
                R[i] = i + 1;
            }
        }
        int mx = 0, pos = 0;
        for (int i = 1; i <= n; i ++) {
            int temp = sum[R[i]] - sum[i];
            if (temp > mx && d[i] > 0) {
                mx = temp;
                pos = i;
            }
        }
        if (mx == 0) break;
        d[pos] --;
        ans -= mx;
        Update();
    }
    cout << ans << '\n';
    return 0;
}
