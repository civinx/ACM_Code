//
//  main.cpp
//  Lotus and Horticulture
//
//  Created by czf on 2017/3/18.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;

struct P {
    double pos, val;
    bool operator < (const P & rhs) const {
        return pos < rhs.pos;
    }
}p[maxn];

int main() { //c a b
    int T; scanf("%d",&T);
    while (T--) {
        int n, N; scanf("%d",&n); N = n << 1;
        LL temp = 0;
        for (int i = 0; i < n; i ++) {
            int l, r, a, b, c; scanf("%d%d%d%d%d",&l,&r,&a,&b,&c);
            temp += c;
            p[i<<1].pos = l; p[i<<1].val = a - c;
            p[i<<1|1].pos = r+0.5; p[i<<1|1].val = b - a;
        }
        sort(p, p+N);
        LL res = temp;
        for (int i = 0; i < N; i ++) {
            temp += p[i].val;
            while (i + 1 < N && p[i].pos == p[i+1].pos) temp += p[i+1].val, i ++;
            res = max(res, temp);
        }
        printf("%lld\n",res);
    }
    return 0;
}
