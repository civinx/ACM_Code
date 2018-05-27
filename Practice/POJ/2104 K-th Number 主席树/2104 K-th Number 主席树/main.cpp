//
//  main.cpp
//  2104 K-th Number 主席树
//
//  Created by czf on 2016/10/27.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 100;

int n, m, a[MAXN], root[MAXN], cnt;
struct { int l, r, sum; } T[MAXN*40];
vector<int> v;

inline int getId(int x) {
    return int(lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
}

void update(int l, int r, int &cur, int pre, int pos) {
    T[++cnt] = T[pre], T[cnt].sum ++, cur = cnt;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(l, mid, T[cur].l, T[pre].l, pos);
    else update(mid+1, r, T[cur].r, T[pre].r, pos);
}

int query(int l, int r, int cur, int pre, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int sum = T[T[cur].l].sum - T[T[pre].l].sum;
    if (k <= sum) return query(l, mid, T[cur].l, T[pre].l, k);
    else return query(mid+1, r, T[cur].r, T[pre].r, k - sum);
}

int main() {
    while (scanf("%d%d",&n,&m) == 2) {
        v.clear();
        memset(root, 0, sizeof(root)); cnt = 0;
        for (int i = 1; i <= n; i ++) scanf("%d",&a[i]), v.push_back(a[i]);
        sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= n; i ++) {
            update(1, n, root[i], root[i-1], getId(a[i]));
        }
        while (m--) {
            int L, R, k; scanf("%d%d%d",&L,&R,&k);
            printf("%d\n",v[query(1, n, root[R], root[L-1], k)-1]);
        }
    }
    return 0;
}
