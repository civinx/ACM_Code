//
//  main.cpp
//  5738 Eureka
//
//  Created by czf on 2017/4/20.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;

struct Point {
    LL x, y;
    bool operator < (const Point & r) const {
        if (x == r.x) {
            return y < r.y;
        }
        return x < r.x;
    }
    bool operator == (const Point & r) const {
        return x == r.x && y == r.y;
    }
};

typedef Point Vect;

const int maxn = 1000 + 100;
const LL MOD = 1e9 + 7;

map<Vect, LL> mp;
map<Point, bool> vis;
Point a[maxn];

//化简向量
Vect solve(LL tx, LL ty) {
    Vect temp;
    if (tx == 0 || ty == 0) {
        if (tx == 0 && ty == 0) {
            temp.x = 0;
            temp.y = 0;
        } else if (tx == 0) {
            temp.x = 0;
            temp.y = 1;
        } else {
            temp.x = 1;
            temp.y = 0;
        }
    } else {
        LL g = __gcd(tx, ty);
        temp.x = tx / g;
        temp.y = ty / g;
    }
    return temp;
}

LL qp(LL x, LL n) {
    LL ret = 1;
    while (n) {
        if (n & 1) ret = ((ret % MOD) * (x % MOD)) % MOD;
        n >>= 1;
        x = ((x % MOD) * (x % MOD)) % MOD;
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        for (int i = 0; i < n; i ++) {
            scanf("%lld%lld",&a[i].x,&a[i].y);
        }
        sort(a, a+n);
        vis.clear();
        Vect zero = (Point){0,0};
        LL sum = 0;
        for (int i = 0; i < n; i ++) {
            if (vis[a[i]]) continue;
            vis[a[i]] = 1;
            mp.clear();
            for (int j = i+1; j < n; j ++) {
                LL tx = a[j].x - a[i].x;
                LL ty = a[j].y - a[i].y;
                mp[solve(tx, ty)] ++;
            }
            LL k = mp[zero];
            map<Vect, LL>::iterator it = mp.begin();
            for (; it != mp.end(); it ++) {
                Vect v = it->first;
                if (v == zero) {
                    sum = (sum + qp(2, k+1)) % MOD;
                    sum = (sum - k - 2 + MOD) % MOD;
                } else {
                    LL m = mp[v];
                    LL g1 = (qp(2, k+1) - 1 + MOD) % MOD;
                    LL g2 = (qp(2, m) - 1 + MOD) % MOD;
                    sum += g1 * g2 % MOD;
                }
            }
        }
        printf("%lld\n",sum % MOD);
    }
    return 0;
}
