//
//  main.cpp
//  Problem : [SCOI2005]扫雷Mine
//
//  Created by czf on 2016/11/5.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 10000 + 100;
int a[MAXN],b[MAXN], n;

int check(int x) { //x只有a[1]是1的时候才有用，表示雷放第一格或第二格
    memset(b, -1, sizeof(b)); //1表示要放雷，0表示不放，-1表示还没决定
    if (a[1] == 3 || a[n] == 3) return 0; //如果两边是3肯定不合法。
    if (a[1] == 2) b[1] = b[2] = 1; //如果边上是2那就放两颗雷
    if (a[1] == 1) b[x] = 1, b[3-x] = 0; //1放2不放，或1不放2放
    for (int i = 2; i <= n; i ++) {
        int cnt = 0;
        for (int j = i-1; j <= i; j ++) {
            if (b[j] == 1) cnt ++; //因为i-1和i都已经决定了，统计一下有几颗雷
        }
        if (cnt > a[i]) return 0;//如果大于数字了，不成立
        if (cnt == a[i]) b[i+1] = 0; //如果刚好，那么后面一个格子不放
        else if (a[i] - cnt > 1 || i == n) return 0; //如果少了两颗以上不成立，因为只有后面一个格子可以补，或者少了，而且在最后一格，因为没格子可以放雷了，也不成立
        else b[i+1] = 1; //少了一颗雷，且不是最后一格，那么把后面一个格子放上雷
    }
    return 1;
}
int main() {
    while (scanf("%d",&n) == 1) {
        for (int i = 1; i <= n; i ++) scanf("%d",&a[i]);
        int res = 0;
        if (a[1] == 1) {
            res = check(1) + check(2);
        } else {
            res = check(1);
        }
        printf("%d\n",res);
    }
    return 0;
}
