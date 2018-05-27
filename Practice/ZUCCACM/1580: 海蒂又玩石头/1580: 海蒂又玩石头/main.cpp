//
//  main.cpp
//  1580: 海蒂又玩石头
//
//  Created by czf on 16/5/4.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
typedef long long ll;
const ll mod = 10000;

struct Mat {
    ll a[20][20];
};

Mat multiply(Mat x, Mat y, int n) {
    Mat ret;
    memset(ret.a, 0, sizeof(ret.a));
    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            for (int k = 0; k < n; k ++) {
                ret.a[i][j] = (ret.a[i][j] + x.a[i][k] * y.a[k][j]) % mod;
            }
        }
    }
    //    for (int i = 0; i < n; i ++) {
    //        for (int j = 0; j < n; j ++) {
    //            printf("%lld ",ret.a[i][j]);
    //        }
    //        printf("\n");
    //    }
    //    printf("\n");
    return ret;
}

Mat solve(Mat x, int n, int k) {
    Mat ret;
    memset(ret.a, 0, sizeof(ret.a));
    for (int i = 0; i < n; i ++) ret.a[i][i] = 1;
    while (k) {
        if (k & 1) ret = multiply(ret, x, n);
        x = multiply(x, x, n);
        k >>= 1;
    }
    return ret;
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n; scanf("%d",&n);
        Mat ans;
        memset(ans.a, 0, sizeof(ans.a));
        for (int i = n-1; i >= 0; i --) {
            scanf("%lld",&ans.a[i][0]);
        }
        int m; scanf("%d",&m);
        int m1 = m;
        m -= n;
        if (m > 0) {
            Mat res;
            memset(res.a, 0, sizeof(res.a));
            for (int i = 0; i < n; i ++) res.a[0][i] = 1;
            for (int i = 1; i < n; i ++) res.a[i][i-1] = 1;
            res = solve(res, n, m);
            res = multiply(res, ans, n);
            printf("%lld\n",res.a[0][0]);
        } else
            printf("%lld\n",ans.a[m1-1][0]);
    }
    return 0;
}

