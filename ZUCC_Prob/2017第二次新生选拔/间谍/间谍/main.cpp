//
//  main.cpp
//  间谍
//
//  Created by czf on 2017/2/23.
//  Copyright © 2017年 czf. All rights reserved.
//


#include <cstdio>
const int maxn = 1e5 + 1;

int root[maxn];

int find(int x) {
    return x == root[x] ? x : find(root[x]);
}

int main() {
    int n, m, k; scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= n; i ++) root[i] = i;
    for (int i = 0; i < m; i ++) {
        int x, y; scanf("%d%d",&x,&y);
        x = find(x), y = find(y);
        if (x != y) root[x] = y;
    }
    for (int i = 0; i < k; i ++) {
        int x, y; scanf("%d%d",&x,&y);
        x = find(x), y = find(y);
        if (x == y) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
