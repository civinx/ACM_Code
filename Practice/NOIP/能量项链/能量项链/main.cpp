//
//  main.cpp
//  能量项链
//
//  Created by czf on 2017/2/1.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 222;

struct P { int head, tail; };

P a[maxn]; int temp[maxn], dp[maxn][maxn];


int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> temp[i];
    }
    for (int i = 1; i <= n; i ++) {
        a[i].head = a[i+n].head = temp[i];
        a[i].tail = a[i+n].tail = (i == n ? temp[1]: temp[i+1]);
    }
    
    int N = 2 * n;
    for (int d = 1; d < n; d ++) {
        for (int i = 1; i + d <= N; i ++) {
            for (int j = i; j < i + d; j ++) {
                dp[i][i+d] = max(dp[i][i+d], dp[i][j] + dp[j+1][i+d] + a[i].head * a[j].tail * a[i+d].tail);
            }
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        res = max(res, dp[i][i+n-1]);
    }
    
    cout << res << '\n';
    return 0;
    
}
