//
//  main.cpp
//  Problem : 大膜法师
//
//  Created by czf on 16/4/15.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int maxn = 100000 + 100;
typedef long long ll;
int r[maxn], g[maxn], b[maxn], ans[maxn];
int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n; scanf("%d",&n);
        string ss; cin >> ss;
        string s = "0"; s += ss;
        r[0] = g[0] = b[0] = 0;
        for (int i = 1; i <= n; i ++) {
            r[i] = r[i-1] + (s[i] == 'r' ? 1 : 0);
            g[i] = g[i-1] + (s[i] == 'g' ? 1 : 0);
            b[i] = b[i-1] + (s[i] == 'b' ? 1 : 0);
        }
        ll res = 0;
        ll minn = 0, maxx = 0;
        for (int i = 0; i <= n; i ++) {
            ans[i] = r[i] - b[i];
            if (ans[i] > maxx) maxx = ans[i];
            if (ans[i] < minn) minn = ans[i];
        }
        res = abs(maxx - minn);
        
        minn = 0, maxx = 0;
        for (int i = 0; i <= n; i ++) {
            ans[i] = r[i] - g[i];
            if (ans[i] > maxx) maxx = ans[i];
            if (ans[i] < minn) minn = ans[i];
        }
        res = max(res, abs(maxx - minn));
        
        minn = 0, maxx = 0;
        for (int i = 0; i <= n; i ++) {
            ans[i] = g[i] - b[i];
            if (ans[i] > maxx) maxx = ans[i];
            if (ans[i] < minn) minn = ans[i];
        }
        res = max(res, abs(maxx - minn));
        
        printf("%lld\n",res * 2);
    }
    return 0;
}