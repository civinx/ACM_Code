#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;
typedef long long LL;

const int maxn = 60000 + 100;

double mi[maxn<<2], add[maxn<<2], MID;

void pushup(int rt) {
    mi[rt] = min(mi[ls], mi[rs]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        mi[rt] = MID * l;
        add[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void pushdown(int rt) {
    if (add[rt]) {
        add[ls] += add[rt];
        add[rs] += add[rt];
        mi[ls] += add[rt];
        mi[rs] += add[rt];
        add[rt] = 0;
    }
}

void update(int L, int R, double x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        add[rt] += x;
        mi[rt] += x;
        return;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, x, lson);
    if (R > mid) update(L, R, x, rson);
    pushup(rt);
}

double query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return mi[rt];
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    double ret = 1e6;
    if (L <= mid) ret = query(L, R, lson);
    if (R > mid) ret = min(ret, query(L, R, rson));
    return ret;
}

int a[maxn], pre[maxn];

bool check(int n) {
    MS(add, 0);
    MS(mi, 0);
    MS(pre, 0);
    build(1, n, 1);
    for (int i = 1; i <= n; i ++) {
        update(pre[a[i]]+1, i, 1, 1, n, 1);
        pre[a[i]] = i;
        double ret = query(1, i, 1, n, 1);
        if (ret < MID * (i + 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&a[i]);
        }
        double L = 0, R = 1; MID = 0.5;
        for (int _ = 0; _ <= 20; _ ++) {
            if (check(n)) {
                R = MID;
            } else {
                L = MID;
            }
            MID = (L + R) / 2;
        }
        printf("%.10f\n",MID);
    }
}

