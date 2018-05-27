//
//  main.cpp
//  1642: lzy and matrix
//
//  Created by czf on 16/5/10.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
typedef long long ll;
const ll mod = 1000000007;
const int size = 3;

struct Matrix {
    ll a[5][5];
    Matrix() { memset(a, 0, sizeof(a)); }
};

ll mypow(ll x, ll n) { //x^n
    ll base = x, ret = 1;
    while (n) {
        if (n & 1) ret = (ret * base) % mod;
        n >>= 1;
        base = (base * base) % mod;
    }
    return ret;
}

void init(ll k, Matrix &fir, Matrix &x) {
    ll ans = mypow(2, k);
    fir.a[0][0] = ans;//初始矩阵
    x.a[0][0] = x.a[1][1] = x.a[2][0] = x.a[2][1] = 1;//构造状态转移矩阵
    x.a[0][2] = x.a[1][2] = ans - 2;
    x.a[2][2] = (k > 1 ? ans - 3 : 0);
}

Matrix Multiply(const Matrix &x, const Matrix &y) {
    Matrix ret;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j ++) {
            for (int k = 0; k < size; k ++) {
                ret.a[i][j] += (x.a[i][k] * y.a[k][j]) % mod;
            }
        }
    }
    return ret;
}

Matrix solve(Matrix x, ll n) { //矩阵快速幂
    Matrix ret; ret.a[0][0] = ret.a[1][1] = ret.a[2][2] = 1; //构造三阶单位矩阵
    while (n) {
        if (n & 1) ret = Multiply(ret, x);
        n >>= 1;
        x = Multiply(x, x);
    }
    return ret;
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        ll n, k; scanf("%lld%lld",&n,&k);
        Matrix fir, x, res; init(k, fir, x);
        x = solve(x, n-1);
        res = Multiply(fir, x);
        printf("%lld\n", (res.a[0][0] + res.a[0][2]) % mod);
    }
    return 0;
}