//
//  main.cpp
//  1214 线段覆盖
//
//  Created by czf on 2016/11/15.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000;
struct P {
    int l, r;
    bool operator < (const P &rhs) const {
        return r < rhs.r;
    }
};

P a[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i ++) {
        scanf("%d%d",&a[i].l,&a[i].r);
        if (a[i].l > a[i].r) {
            swap(a[i].l, a[i].r);
        }
    }
    sort(a, a+n);
    int t = -1000, cnt = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i].l >= t) {
            cnt ++;
            t = a[i].r;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
