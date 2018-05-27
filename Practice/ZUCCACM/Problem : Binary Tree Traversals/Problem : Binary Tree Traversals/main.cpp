//
//  main.cpp
//  Problem : Binary Tree Traversals
//
//  Created by czf on 16/4/8.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 1000 + 10;
int pre[maxn], in[maxn];
int cnt, n;
bool flag;

void solve(int l, int r) {
    if (cnt >= n || l == r) return;
    int cur = pre[cnt++];
    int mid = in[cur];
    solve(l, mid);
    solve(mid+1, r);
    if (flag) { printf("%d",cur); flag = 0; }
    else printf(" %d",cur);
}

int main() {
    while (~scanf("%d",&n)) {
        flag = 1;
        cnt = 0;
        for (int i = 0; i < n; i ++) scanf("%d",&pre[i]);
        for (int i = 0; i < n; i ++) { int x; scanf("%d",&x); in[x] = i; }
        solve(0,n);
        printf("\n");
    }
    return 0;
}
