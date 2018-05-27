//
//  main.cpp
//  3397 Sequence operation（线段树 区间操作 合并）
//
//  Created by czf on 16/9/2.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define ls rt<<1
#define rs rt<<1|1
const int N = 100000 + 100;
int col[N<<2], Xor[N<<2];
int sum[N<<2], lsum[N<<2], rsum[N<<2];
int zsum[N<<2], zlsum[N<<2], zrsum[N<<2];
int lv[N<<2], rv[N<<2];
int cnt[N<<2];

void pushup(int rt, int len) {
    lv[rt] = lv[ls];
    rv[rt] = rv[rs];
    lsum[rt] = lsum[ls];
    rsum[rt] = rsum[rs];
    if (lsum[rt] == len - (len>>1) && lv[rs]) lsum[rt] += lsum[rs];
    if (rsum[rt] == (len >> 1) && rv[ls]) rsum[rt] += rsum[ls];
    sum[rt] = max(sum[ls], sum[rs]);
    if (rv[ls] && lv[rs]) sum[rt] = max(sum[rt], rsum[ls] + lsum[rs]);
    
    zlsum[rt] = zlsum[ls];
    zrsum[rt] = zrsum[rs];
    if (zlsum[rt] == len - (len>>1) && !lv[rs]) zlsum[rt] += zlsum[rs];
    if (zrsum[rt] == (len>>1) && !rv[ls]) zrsum[rt] += zrsum[ls];
    zsum[rt] = max(zsum[ls], zsum[rs]);
    if (!rv[ls] && !lv[rs]) zsum[rt] = max(zsum[rt], zrsum[ls] + zlsum[rs]);
    cnt[rt] = cnt[ls] + cnt[rs];
    
}

void Build(int l, int r, int rt) {
    col[rt] = -1;
    Xor[rt] = 0;
    if (l == r) {
        int x; scanf("%d",&x);
        sum[rt] = lsum[rt] = rsum[rt] = lv[rt] = rv[rt] = cnt[rt] = x;
        zsum[rt] = zlsum[rt] = zrsum[rt] = x^1;
        return;
    }
    int m = (l + r) >> 1;
    Build(lson);
    Build(rson);
    pushup(rt, r-l+1);
}

void Swap(int rt, int len) {
    lv[rt] ^= 1; rv[rt] ^= 1;
    cnt[rt] = len - cnt[rt];
    swap(sum[rt], zsum[rt]);
    swap(lsum[rt], zlsum[rt]);
    swap(rsum[rt], zrsum[rt]);
}

void rev(int rt, int len) {
    Swap(rt, len);
    if (col[rt] != -1) col[rt] ^= 1;
    else Xor[rt] ^= 1;
}

void pushdown(int rt, int len) {
    if (col[rt] != -1) {
        col[ls] = col[rs] = col[rt];
        Xor[ls] = Xor[rs] = 0;
        
        cnt[ls] = sum[ls] = lsum[ls] = rsum[ls] = (len - (len >> 1)) * col[rt];
        cnt[rs] = sum[rs] = lsum[rs] = rsum[rs] = (len >> 1) * col[rt];
        lv[ls] = rv[ls] = lv[rs] = rv[rs] = col[rt];
        
        zsum[ls] = zlsum[ls] = zrsum[ls] = (len - (len >> 1)) * (col[rt]^1);
        zsum[rs] = zlsum[rs] = zrsum[rs] = (len >> 1) * (col[rt]^1);
        col[rt] = -1;
    }
    if (Xor[rt]) {
        rev(ls, len-(len>>1));
        rev(rs, len>>1);
        Xor[rt] = 0;
    }
}

void Set(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        col[rt] = x;
        Xor[rt] = 0;
        sum[rt] = lsum[rt] = rsum[rt] = cnt[rt] = x * (r-l+1);
        zsum[rt] = zlsum[rt] = zrsum[rt] = (x^1) * (r-l+1);
        lv[rt] = rv[rt] = x;
        return;
    }
    pushdown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) Set(L, R, x, lson);
    if (R > m) Set(L, R, x, rson);
    pushup(rt, r-l+1);
}

void Reverse(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        rev(rt, r-l+1);
        return;
    }
    pushdown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) Reverse(L, R, lson);
    if (R > m) Reverse(L, R, rson);
    pushup(rt, r-l+1);
}

int QueryCnt(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return cnt[rt];
    }
    pushdown(rt, r-l+1);
    int ret = 0;
    int m = (l + r) >> 1;
    if (L <= m) ret += QueryCnt(L, R, lson);
    if (R > m) ret += QueryCnt(L, R, rson);
    return ret;
}

int QuerySum(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    pushdown(rt, r-l+1);
    int left = 0, right = 0;
    int m = (l + r) >> 1;
    if (L <= m) left = QuerySum(L, R, lson);
    if (R > m) right = QuerySum(L, R, rson);
    int ret = max(left, right);
    if (rv[ls] && lv[rs]) ret = max(ret, min(rsum[ls], m-L+1) + min(lsum[rs], R-m));
    return ret;
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n, m; scanf("%d%d",&n,&m);
        Build(0, n-1, 1);
        while (m--) {
            int op, a, b; scanf("%d%d%d",&op,&a,&b);
            if (op == 0 || op == 1) {
                Set(a, b, op, 0, n-1, 1);
            } else if (op == 2) {
                Reverse(a, b, 0, n-1, 1);
            } else if (op == 3) {
                printf("%d\n",QueryCnt(a, b, 0, n-1, 1));
            } else {
                printf("%d\n",QuerySum(a, b, 0, n-1, 1));
            }
        }
    }
    return 0;
}
