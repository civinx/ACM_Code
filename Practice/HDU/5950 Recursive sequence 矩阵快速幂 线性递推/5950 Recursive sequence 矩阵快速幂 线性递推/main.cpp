//
//  main.cpp
//  5950 Recursive sequence 矩阵快速幂 线性递推
//
//  Created by czf on 2016/11/3.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
typedef long long LL;

const int SIZE = 7;
const LL MOD = 2147493647;

struct Mat {
    LL a[SIZE][SIZE];
    void setOne() {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < SIZE; i ++) a[i][i] = 1;
    }
    void setZero() {
        memset(a, 0, sizeof(a));
    }
    void print() {
        for (int i = 0; i < SIZE; i ++) {
            for (int j = 0; j < SIZE; j ++) {
                printf("%lld%c",a[i][j],j == SIZE-1 ? '\n' : ' ');
            }
        }
        printf("\n");
    }
    Mat operator * (const Mat &rhs) const {
        Mat ret; ret.setZero();
        for (int i = 0; i < SIZE; i ++) {
            for (int j = 0; j < SIZE; j ++) {
                for (int k = 0; k < SIZE; k ++) {
                    ret.a[i][j] = (ret.a[i][j] + (a[i][k] % MOD) * (rhs.a[k][j] % MOD) % MOD) % MOD;
                }
            }
        }
        return ret;
    }
    Mat operator ^ (LL n) const {
        Mat base = (*this), ret; ret.setOne();
        while (n) {
            if (n & 1) ret = ret * base;
            base = base * base;
            n >>= 1;
        }
        return ret;
    }
};

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        LL n, a, b; scanf("%lld%lld%lld",&n,&a,&b);
        if (n <= 2) {
            printf("%lld\n",n == 1 ? a : b);
        }
        Mat m1 = {
            b, a, 16, 8, 4, 2, 1,
            0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0
        };
        Mat m2 = {
            1, 1, 0, 0, 0, 0, 0,
            2, 0, 0, 0, 0, 0, 0,
            1, 0, 1, 0, 0, 0, 0,
            4, 0, 4, 1, 0, 0, 0,
            6, 0, 6, 3, 1, 0, 0,
            4, 0, 4, 3, 2, 1, 0,
            1, 0, 1, 1, 1, 1, 1
        };
        m2 = m2 ^ (n-2);
        m1 = m1 * m2;
        printf("%lld\n",m1.a[0][0]);
    }
    return 0;
}
