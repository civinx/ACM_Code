//
//  main.cpp
//  3225 Help with Intervals（线段树延迟标记）
//
//  Created by czf on 16/8/28.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 65535*2+100;
//const int maxn = 10;
bool vis[maxn<<4];
int c[maxn<<4];
int XOR[maxn<<4];

void FXOR(int rt) {
    if (c[rt] != -1) {
        c[rt] ^= 1;
    } else {
        XOR[rt] ^= 1;
    }
}

void pushdown(int rt) {
    if (c[rt] != -1) {
        c[rt<<1] = c[rt<<1|1] = c[rt];
        XOR[rt<<1] = XOR[rt<<1|1] = 0;
        c[rt] = -1;
    }
    if (XOR[rt]) {
        FXOR(rt<<1);
        FXOR(rt<<1|1);
        XOR[rt] = 0;
    }
}

void update(int L, int R, char op, int l, int r, int rt) {
    if (L <= l && r <= R) {
        if (op == 'U') {
            c[rt] = 1;
            XOR[rt] = 0;
        } else if (op == 'D') {
            c[rt] = 0;
            XOR[rt] = 0;
        } else if (op == 'S' || op == 'C') {
            FXOR(rt);
        }
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, op, lson);
    else if (op == 'I' || op == 'C') {
        c[rt<<1] = XOR[rt<<1] = 0;
    }
    if (R > m) update(L, R, op, rson);
    else if (op == 'I' || op == 'C') {
        c[rt<<1|1] = XOR[rt<<1|1] = 0;
    }
}

void query(int l, int r, int rt) {
    if (c[rt] == 1) {
        for (int i = l; i <= r; i ++) vis[i] = 1;
        return;
    }
    if (c[rt] == 0) return;
    pushdown(rt);
    int m = (l + r) >> 1;
    query(lson);
    query(rson);
}

int main() {
    memset(vis, 0, sizeof(vis));
    c[1] = XOR[1] = 0;
    int a, b; char l, r, op;
    while (~scanf("%c %c%d,%d%c\n",&op,&l,&a,&b,&r)) {
        a <<= 1; b <<= 1;
        if (l == '(') a ++;
        if (r == ')') b --;
        if (a > b) {
            if (op == 'I' || op == 'C') {
                c[1] = XOR[1] = 0;
            }
        } else update(a, b, op, 0, maxn, 1);
    }
    query(0, maxn, 1);
    bool flag = 0;
    int s = -1, e = -1;
    for (int i = 0; i < maxn; i ++) {
        if (vis[i]) {
            if (s == -1) s = e = i;
            else e = i;
        } else if (s != -1) {
            if (flag) printf(" ");
            else flag = 1;
            printf("%c%d,%d%c",s&1?'(':'[',s>>1,(e+1)>>1,e&1?')':']');
            s = -1;
        }
    }
    if (flag == 0) printf("empty set");
    printf("\n");
    return 0;
}
