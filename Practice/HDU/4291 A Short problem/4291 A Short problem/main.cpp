//
//  main.cpp
//  4291 A Short problem
//
//  Created by czf on 2016/10/12.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;

const LL MOD1 = 1e9 + 7;
const LL MOD2 = 222222224;
const LL MOD3 = 183120;
const int MATSIZE = 2;
LL MOD;

void Test() {
    LL a = 0, b = 1, c;
    for (LL i = 2;; i ++) {
        c = (a + b * 3) % MOD2;
        if (b == 0 && c == 1) {
            cout << i - 1 << '\n';
            break;
        }
        a = b, b = c;
    }
}

struct Mat {
    LL a[MATSIZE][MATSIZE];
    Mat () { memset(a, 0, sizeof(a)); }
    Mat operator * (const Mat & rhs) const {
        Mat ret;
        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j < 2; j ++) {
                for (int k = 0; k < 2; k ++) {
                    //                    cout << a[i][k] << " " << rhs.a[k][j] << '\n';
                    ret.a[i][j] = (ret.a[i][j] + (a[i][k] * rhs.a[k][j])) % MOD;
                    
                }
            }
        }
        return ret;
    }
    
    Mat pow(LL n) {
        Mat ret, base;
        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j < 2; j ++) {
                base.a[i][j] = a[i][j];
            }
        }
        ret.a[0][0] = ret.a[1][1] = 1;
        while (n) {
            if (n & 1) ret = ret * base;
            base = base * base;
            n >>= 1;
        }
        return ret;
    }
    
    void init() {
        a[0][0] = 0, a[0][1] = 1, a[1][0] = 1, a[1][1] = 3;
    }
};

LL solve(LL mod, LL n) {
    Mat base; base.a[0][0] = 0, base.a[0][1] = 1;
    MOD = mod;
    Mat mat1; mat1.init();
    mat1 = mat1.pow(n-1);
    mat1 = base * mat1;
    return mat1.a[0][1];
}

int main() {
    LL n;
    while (scanf("%lld",&n) != EOF) {
        LL res = n;
        if (res > 0)res = solve(MOD3, n);
        if (res > 0)res = solve(MOD2, res);
        if (res > 0)res = solve(MOD1, res);
        printf("%lld\n",res);
    }
    return 0;
}

/* -------题解---------
 首先观察递推式 g[n] = g[n-1] * 3 + g[n-2]，初始条件g[0] = 0, g[1] = 1
 易得出初始矩阵[0 1], 递推矩阵  [0 1]
 [1 3]
 现在我们假设，题目只让我们算g[n]，并对结果1e9+7取模，那很好写，因为我们只需要对求出来的结果取模
 也就是对值域取模。继续考虑求g[g[n]]，设y = g[n]，我们现在并不能直接对y取模1e9+7，因为y虽然是g[n]
 的值域，但也在g[y]中y是定义域，那么我们需要找到y的循环节，这样就可以对y这个定义域取模（循环节）而不影响答案，
 所以对于g[g[g[n]]]，我们先把g[g[n]]看作一个x，找到g[x] % 1e9+7 的循环节 MOD1
 这样式子就变为了g[g[g[n]]%MOD1]%1e9+7，再把g[n]看成整体x，找到g[x] % MOD1的循环节 MOD2
 式子变为g[g[g[n]%MOD2]%MOD1]%1e9+7,这样再从内层往外矩阵快速幂，就可以了。
 */
