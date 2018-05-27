#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1

typedef long long LL;

const int maxn = 100000 + 100;

LL mx[maxn<<2], mxcnt[maxn<<2], sum[maxn<<2];


void pushup(int rt) {
    mx[rt] = max(mx[ls], mx[rs]);
//    mxcnt[rt] = max(mxcnt[ls], mxcnt[rs]);
    sum[rt] = sum[ls] + sum[rs];
}

void build(int l, int r, int rt) {
    if (l == r) {
        LL x; scanf("%lld",&x);
        mx[rt] = x;
        mxcnt[rt] = log(x);
        sum[rt] = x;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void modUpdate(int L, int R, LL k, int l, int r, int rt) {
    if (mx[rt] < k) return;
    if (l == r) {
        sum[rt] %= k;
        mx[rt] %= k;
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) modUpdate(L, R, k, lson);
    if (R > mid) modUpdate(L, R, k, rson);
    pushup(rt);
}

void changeupdate(int x, LL k, int l, int r, int rt) {
    if (l == r) {
        sum[rt] = k;
        mx[rt] = k;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) changeupdate(x, k, lson);
    else changeupdate(x, k, rson);
    pushup(rt);
}

LL query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    LL ret = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) ret += query(L, R, lson);
    if (R > mid) ret += query(L, R, rson);
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, q; scanf("%d%d",&n,&q);
        build(1, n, 1);
        while (q --) {
            int op; scanf("%d",&op);
            if (op == 1) {
                int L, R; scanf("%d%d",&L,&R);
                printf("%lld\n",query(L, R, 1, n, 1));
            } else if (op == 2) {
                int L, R; LL k; scanf("%d%d%lld",&L,&R,&k);
                modUpdate(L, R, k, 1, n, 1);
            } else {
                int x; LL k; scanf("%d%lld",&x,&k);
                changeupdate(x, k, 1, n, 1);
            }
        }
    }
    return 0;
}