//
//  main.cpp
//  Problem : Inversion
//
//  Created by czf on 16/4/27.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
typedef long long ll;
const int maxn = 100000 + 100;
ll a[maxn], temp[maxn];
ll res = 0;

void solve(int l, int r) {
    if (r - l <= 1) return;
    int cnt_l = l, mid = (l + r) / 2, cnt_r = mid;
    if (r - l > 1) {
        solve(l, mid);
        solve(mid, r);
    }
    int cnt = l;
    while (cnt_l < mid || cnt_r < r) {
        if (cnt_r >= r || (cnt_l < mid && a[cnt_l] <= a[cnt_r])) {
            temp[cnt++] = a[cnt_l++];
        } else {
            temp[cnt++] = a[cnt_r++];
            res += mid - cnt_l;
        }
    }
    for (int i = l; i < r; i ++) a[i] = temp[i];
}
            
            
int main() {
    int n, k;
    while (~scanf("%d%d",&n,&k)) {
        res = 0;
        for (int i = 0; i < n; i ++) scanf("%lld",&a[i]);
        solve(0,n);
        if (k > res) res = 0;
        else res -= k;
        printf("%lld\n",res);
    }
    return 0;
}
