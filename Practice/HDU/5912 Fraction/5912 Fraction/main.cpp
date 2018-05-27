//
//  main.cpp
//  5912 Fraction
//
//  Created by czf on 2016/10/17.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10;
int A[MAXN], B[MAXN];

struct P {
    int up, down;
    P operator / (const P &rhs) {
        int a = up * rhs.down;
        int b = down * rhs.up;
        int k = __gcd(a, b);
        a /= k; b /= k;
        return (P){a, b};
    }
    P operator + (const P &rhs) {
        int lcm = down * rhs.down / __gcd(down, rhs.down);
        int a = up * (lcm / down) + rhs.up * (lcm / rhs.down);
        return (P){a, lcm};
    }
    P & operator = (const P &rhs) {
        up = rhs.up;
        down = rhs.down;
        return *this;
    }
};

int n;
P solve(P b, int x) {
    P a{A[x], 1};
    P b1{B[x+1], 1};
    if (x == n) {
        return b / a;
    }
    return b / (a + solve(b1, x+1));
}

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i ++) scanf("%d",&A[i]);
        for (int i = 1; i <= n; i ++) scanf("%d",&B[i]);
        P b{B[1], 1};
        P res = solve(b, 1);
        printf("Case #%d: %d %d\n",++kase, res.up, res.down);
    }
    return 0;
}
