//
//  main.cpp
//  Lotus and Characters
//
//  Created by czf on 2017/3/15.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 30;

struct P {
    LL v, cnt;
    bool operator < (const P & rhs) const {
        return v > rhs.v;
    }
} a[maxn];

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        for (int i = 0; i < n; i ++) {
            scanf("%lld%lld",&a[i].v,&a[i].cnt);
        }
        a[n].v = 0;
        sort(a, a+n);
        LL res = 0, temp = 0;
        for (int i = 0; i < n; i ++) {
            while (a[i].cnt) {
                temp += a[i].v;
                if (temp > 0) {
                    res += temp;
                    a[i].cnt --;
                } else {
                    break;
                }
            }
            if (a[i].cnt) break;
        }
        printf("%lld\n",res);
    }
    return 0;
}
