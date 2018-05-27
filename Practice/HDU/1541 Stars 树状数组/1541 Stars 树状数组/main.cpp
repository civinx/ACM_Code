//
//  main.cpp
//  1541 Stars 树状数组
//
//  Created by czf on 2016/11/1.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 40000 + 100;
int c[maxn], res[maxn], n;

struct P{
    int x, y;
    bool operator < (const P &rhs) const {
        if (x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
}a[maxn];

inline int lowbit(int x) {
    return x & -x;
}

inline int sum(int x) {
    int ret = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) ret += c[i];
    return ret;
}

inline void add(int x) {
    for (int i = x; i < maxn; i += lowbit(i)) c[i] += 1;
}

int main() {
    while (scanf("%d",&n) != EOF) {
        memset(c, 0, sizeof(c));
        memset(res, 0, sizeof(res));
        for (int i = 1; i <= n; i ++) scanf("%d%d",&a[i].x,&a[i].y), a[i].x++, a[i].y++;
        //        sort(a+1, a+1+n);
        for (int i = 1; i <= n; i ++) {
            //            printf("%d\n",sum(a[i].x));
            res[sum(a[i].x)] ++;
            add(a[i].x);
        }
        for (int i = 0; i < n; i ++) printf("%d\n",res[i]);
    }
    return 0;
}
