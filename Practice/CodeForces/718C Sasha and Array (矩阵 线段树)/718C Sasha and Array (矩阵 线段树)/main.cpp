//
//  main.cpp
//  718C Sasha and Array (矩阵 线段树)
//
//  Created by czf on 2016/10/12.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
typedef long long LL;
const int SIZE = 2;
const LL MOD = 1e9 + 7;
const LL MAXN = 100000 + 100;
//const int MAXN = 10;

struct Mat {
    LL a[SIZE][SIZE];
    Mat () { memset(a, 0, sizeof(a)); }
    Mat operator * (const Mat &rhs) const {
        Mat ret;
        for (int i = 0; i < SIZE; i ++) {
            for (int j = 0; j < SIZE; j ++) {
                for (int k = 0; k < SIZE; k ++) {
                    ret.a[i][j] = (ret.a[i][j] + (a[i][k] * rhs.a[k][j] % MOD) % MOD);
                }
            }
        }
        return ret;
    }
    
    Mat operator + (const Mat &rhs) const {
        Mat ret;
        for (int i = 0; i < SIZE; i ++) {
            for (int j = 0; j < SIZE; j ++) {
                ret.a[i][j] = (a[i][j] + rhs.a[i][j]) % MOD;
            }
        }
        return ret;
    }
    
    Mat& operator = (const Mat &rhs) {
        for (int i = 0; i < SIZE; i ++) {
            for (int j = 0; j < SIZE; j ++) {
                a[i][j] = rhs.a[i][j];
            }
        }
        return *this;
    }
    
    Mat operator ^ (int n) {
        Mat base, ret; base = (*this);
        ret.init();
        while (n) {
            if (n & 1) ret = ret * base;
            base = base * base;
            n >>= 1;
        }
        return ret;
    }
    
    void build() {
        a[0][0] = 0, a[0][1] = 1, a[1][0] = 1, a[1][1] = 1;
    }
    
    void init() {
        a[0][0] = a[1][1] = 1;
    }
    
    bool NotZero() {
        if (a[0][0] && a[1][1] && !a[1][0] && !a[0][1]) return false;
        return true;
    }
    
    void SetZero() {
        memset(a, 0, sizeof(a));
        a[0][0] = a[1][1] = 1;
    }
    
}sum[MAXN << 2], lazy[MAXN << 2];

inline void pushup(int rt) {
    sum[rt] = sum[ls] + sum[rs];
}

inline void build(int l, int r, int rt) {
    lazy[rt].SetZero();
    if (l == r) {
        sum[rt].build();
        int x; scanf("%d",&x);
        sum[rt] = sum[rt] ^ x;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

inline void pushdown(int rt) {
    if (lazy[rt].NotZero()) {
        lazy[ls] = lazy[ls] * lazy[rt];
        lazy[rs] = lazy[rs] * lazy[rt];
        sum[ls] = sum[ls] * lazy[rt];
        sum[rs] = sum[rs] * lazy[rt];
        lazy[rt].SetZero();
    }
}

inline void add(int L, int R, Mat &rhs, int l, int r, int rt) {
    if (L <= l && r <= R) {
        lazy[rt] = lazy[rt] * rhs;
        sum[rt] = sum[rt] * rhs;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) add(L, R, rhs, lson);
    if (R > m) add(L, R, rhs, rson);
    pushup(rt);
}

inline Mat query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    Mat ret;
    if (L <= m) ret = ret + query(L, R, lson);
    if (R > m) ret = ret + query(L, R, rson);
    return ret;
}

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    build(1, n, 1);
    while (m--) {
        int op; scanf("%d",&op);
        if (op == 1) {
            int L, R, v; scanf("%d%d%d",&L,&R,&v);
            Mat rhs; rhs.build(); rhs = rhs ^ v;
            add(L, R, rhs, 1, n, 1);
        } else {
            int L, R; scanf("%d%d",&L,&R);
            Mat res; res = query(L, R, 1, n, 1);
            Mat lhs; lhs.a[0][0] = 0, lhs.a[0][1] = 1;
            lhs = lhs * res;
            printf("%lld\n",lhs.a[0][0]);
        }
    }
    return 0;
}

/*
 题意，给出一个序列a1, a2, a3 ..... an
 现在你有两种操作
 1、在区间[L,R],直接得出f[ai]的总和（f[]为斐波那契数列）
 2、使区间[L,R]之间的ai都加上一个值
 
 思路，维护一颗线段树，线段树的每一个节点代表某一段区间里al..ar对应的矩阵和
 这样当区间要加上v的时候的时候，因为矩阵符合乘法分配律直接让这个矩阵乘上斐波那契单位矩阵的v次幂就可以了，
 a^v * m1 + a^v * m2 = a^v * sum
 因为是区间修改，所以lazy标记也是一个矩阵，注意，初始化不是全零的矩阵，而是单位矩阵
 */
