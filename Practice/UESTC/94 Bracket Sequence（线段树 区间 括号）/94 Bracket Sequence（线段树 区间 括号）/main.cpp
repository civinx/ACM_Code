//
//  main.cpp
//  94 Bracket Sequence（线段树 区间 括号）
//
//  Created by czf on 16/9/1.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int N = 100000 + 100;
int sum[N<<2], mx[N<<2], mi[N<<2];
int col[N<<2], Xor[N<<2];
char str[N];

void pushup(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    mx[rt] = max(mx[rt<<1], sum[rt<<1] + mx[rt<<1|1]);
    mi[rt] = min(mi[rt<<1], sum[rt<<1] + mi[rt<<1|1]);
}

void build(int l, int r, int rt) {
    Xor[rt] = col[rt] = 0;
    if (l == r) {
        int k = (str[l] == '(' ? -1 : 1);
        sum[rt] = col[rt] = k;
        mx[rt] = max(0, k);
        mi[rt] = min(0, k);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void rev(int rt) { //反转线段
    int t1 = -mx[rt];
    int t2 = -mi[rt];
    mx[rt] = t2;
    mi[rt] = t1;
    sum[rt] *= -1;
    if (col[rt]) {
        col[rt] *= -1;
    } else {
        Xor[rt] ^= 1;
    }
}

void pushdown(int rt, int len) {
    if (col[rt]) {
        int k = col[rt];
        sum[rt<<1] = k * (len - (len>>1));
        sum[rt<<1|1] = k * (len>>1);
        mx[rt<<1] = (k == 1 ? sum[rt<<1] : 0);
        mx[rt<<1|1] = (k == 1 ? sum[rt<<1|1] : 0);
        mi[rt<<1] = (k == -1 ? sum[rt<<1] : 0);
        mi[rt<<1|1] = (k == -1 ? sum[rt<<1|1] : 0);
        col[rt<<1] = col[rt<<1|1] = k;
        Xor[rt<<1] = Xor[rt<<1|1] = 0;
        col[rt] = 0;
    }
    if (Xor[rt]) {
        rev(rt<<1);
        rev(rt<<1|1);
        Xor[rt] = 0;
    }
}



void Set(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        col[rt] = x;
        sum[rt] = (r - l + 1) * x;
        if (x == 1) {
            mx[rt] = sum[rt];
            mi[rt] = 0;
        } else {
            mx[rt] = 0;
            mi[rt] = sum[rt];
        }
        Xor[rt] = 0;
        return;
    }
    pushdown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) Set(L , R, x, lson);
    if (R > m) Set(L, R, x, rson);
    pushup(rt);
}

void Reverse(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        rev(rt);
        return;
    }
    pushdown(rt, r-l+1);
    int m = (l + r) >> 1;
    if (L <= m) Reverse(L, R, lson);
    if (R > m) Reverse(L, R, rson);
    pushup(rt);
}

int qsum(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    pushdown(rt, r-l+1);
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += qsum(L, R, lson);
    if (R > m) ret += qsum(L, R, rson);
    return ret;
}

int qmax(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return mx[rt];
    }
    pushdown(rt, r-l+1);
    int m  = (l + r) >> 1;
    int lmax = 0, rmax = 0, lsum = 0;
    if (L <= m) lmax = qmax(L, R, lson), lsum = qsum(L, R, lson);
    if (R > m) rmax = qmax(L, R, rson);
    return max(lmax, (lsum + rmax));
}

bool query(int L, int R, int n) {
    int x = qsum(L, R, 0, n-1, 1);
    int y = qmax(L, R, 0, n-1, 1);
    if (x == 0 && y <= 0) return true;
    return false;
}

int main() {
    int t, kase = 0; scanf("%d",&t);
    while (t--) {
        printf("Case %d:\n",++kase);
        int n; scanf("%d",&n);
        scanf("%s",str);
        build(0, n-1, 1);
        int m; scanf("%d",&m);
        while (m --) {
            char op[10]; int L, R, x; char c;
            scanf("%s",op);
            if (op[0] == 's') {
                scanf("%d%d %c\n",&L,&R,&c);
                x = (c == '(' ? -1 : 1);
                Set(L, R, x, 0, n-1, 1);
            } else if (op[0] == 'r') {
                scanf("%d%d",&L,&R);
                Reverse(L, R, 0, n-1, 1);
            } else {
                scanf("%d%d",&L,&R);
                if (query(L, R, n)) printf("YES\n");
                else printf("NO\n");
            }
        }
        printf("\n");
    }
    return 0;
}