//
//  main.cpp
//  1579: A-B
//
//  Created by czf on 16/3/26.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using std::sort;
const int maxn = 1000 + 100;
int a[maxn];

int bSearch(int left, int right, int x) {
    int mid;
    int l = left, r = right;
    while(l <= r) {
        mid = (l + r) / 2;
        if (a[mid] >= x) r = mid - 1;
        else l = mid + 1;
    }
    if (l > right) return r;
    return l;
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int n, m; scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        sort(a, a+n);
        while(m--) {
            int A = 0, B = 0;
            int p, q; scanf("%d%d",&p,&q);
            int x = p - q;
            int index = bSearch(0, n-1, x);
            A = a[index];
            if (A < x) {
                B = A;
                A = 0;
            } else {
                if (index == 0) B = 0;
                else B = a[index-1];
            }
            printf("%d\n",A-B);
        }
    }
    return 0;
}