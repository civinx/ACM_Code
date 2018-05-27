//
//  main.cpp
//  Problem : 树上战争
//
//  Created by czf on 15/10/20.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

int father[maxn];

int Find(int x){
    int cnt = 0;
    while (x != father[x]) {
        x = father[x];
        cnt ++;
    }
    return cnt;
}

int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) == 2 && (n || m)) {
        for (int i = 1; i <= n; i ++) father[i] = i;
        for (int i = 0; i < n - 1; i ++) {
            int a,b;
            scanf("%d%d",&a,&b);
            father[b] = a;
        }
        while (m--) {
            int x,y;
            scanf("%d%d",&x,&y);
            if (Find(x) <= Find(y)) printf("lxh\n");
            else printf("pfz\n");
        }
    }
    return 0;
}
