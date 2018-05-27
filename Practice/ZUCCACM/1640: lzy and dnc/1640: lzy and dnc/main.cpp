//
//  main.cpp
//  1640: lzy and dnc
//
//  Created by czf on 16/5/7.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50000 + 100;
int a[maxn];
bool vis[maxn];

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int r, n, k; scanf("%d%d%d",&r,&n,&k);
        for (int i = 0; i <= n + 1; i ++)
            if (i == 0) a[i] = 0;
            else if (i == n+1) a[i] = r;
            else scanf("%d",&a[i]);
        int l = 0;
        int res = -1;
        while (l <= r) {
            memset(vis, 0, sizeof(vis));
            int mid = (l + r) >> 1;
            int cnt = 0, ans = -1;
            bool flag = 0;
            for (int i = 0; i <= n; i ++) {
                if (vis[i]) continue;
                int j = i+1; while(vis[j]) j ++;
                if (a[j] - a[i] < mid) {
                    if (cnt < k) {
                        if (j == n+1) {
                            a[i] = 1;
                            i -= 2;
                            continue;
                        }
                        vis[j] = 1; i --; cnt ++; continue;
                    }//去掉一个
                    else { r = mid; flag = 1; break; } //次数不够
                } else {
                    if (ans == -1) ans = a[j] - a[i];//ans是差值的最小值
                    else ans = min(ans, a[j] - a[i]);
                }
            }
            if (!flag) {
                res = max(res, ans);
                l = mid + 1;
            } else if (l == r) break;
        }
        printf("%d\n",res);
    }
    return 0;
}