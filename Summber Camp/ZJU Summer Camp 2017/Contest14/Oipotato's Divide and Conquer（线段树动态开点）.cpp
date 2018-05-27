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
#include <ctime>
using namespace std;

const int maxn = 100000 + 100;
//const int maxn = 100;
const int INF = 0x3f3f3f3f;

struct Node {
    int l, r, lson, rson, mi, tag;
}seg[8000000];

int MIN, tot, n;
int a[maxn], st[maxn][20];

void getST() {
    for (int i = 1; i <= n; i ++) st[i][0] = a[i];
    for (int k = 1; (1 << k) <= n; k ++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i ++) {
            st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
        }
    }
}

int getMin(int l, int r) {
    int k = (int)(log(r-l+1)/log(2));
    return min(st[l][k], st[r-(1<<k)+1][k]);
}

int newNode(int l, int r) {
    tot ++;
    seg[tot].lson = seg[tot].rson = seg[tot].tag = 0;
    seg[tot].l = l;
    seg[tot].r = r;
    if (r - l + 1 >= n) {
        seg[tot].mi = MIN;
    } else {
        l = (l - 1) % n + 1;
        r = (r - 1) % n + 1;
        if (l <= r) {
            seg[tot].mi = getMin(l, r);
        } else {
            seg[tot].mi = min(getMin(l, n), getMin(1, r));
        }
    }
    return tot;
}

void pushdown(int rt) {
    int mid = (seg[rt].l + seg[rt].r) >> 1;
    if (seg[rt].lson == 0) {
        seg[rt].lson = newNode(seg[rt].l, mid);
    }
    if (seg[rt].rson == 0) {
        seg[rt].rson = newNode(mid+1, seg[rt].r);
    }
    if (seg[rt].tag) {
        int lson = seg[rt].lson, rson = seg[rt].rson;
        seg[lson].mi = seg[rson].mi = seg[rt].tag;
        seg[lson].tag = seg[rson].tag = seg[rt].tag;
        seg[rt].tag = 0;
    }
}


void pushup(int rt) {
    int lson = seg[rt].lson, rson = seg[rt].rson;
    seg[rt].mi = min(seg[lson].mi, seg[rson].mi);
}

void update(int L, int R, int x, int rt) {
    int l = seg[rt].l, r = seg[rt].r;
    if (L <= l && r <= R) {
        seg[rt].mi = x;
        seg[rt].tag = x;
        return;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(L, R, x, seg[rt].lson);
    if (R > mid) update(L, R, x, seg[rt].rson);
    pushup(rt);
}

int query(int L, int R, int rt) {
    int l = seg[rt].l, r = seg[rt].r;
    if (L <= l && r <= R) {
        return seg[rt].mi;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    int ret = INF;
    if (L <= mid) ret = min(ret, query(L, R, seg[rt].lson));
    if (R > mid) ret = min(ret, query(L, R, seg[rt].rson));
    return ret;
}

int main() {
    int k;
    while (scanf("%d%d",&n,&k) == 2) {
        MIN = INF;
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&a[i]);
            MIN = min(MIN, a[i]);
        }
        getST();
        int q; scanf("%d",&q);
        tot = 0; newNode(1, n * k);
        while (q--) {
            int op; scanf("%d",&op);
            if (op == 1) {
                int L, R, x; scanf("%d%d%d",&L,&R,&x);
                update(L, R, x, 1);
            } else {
                int L, R; scanf("%d%d",&L,&R);
                printf("%d\n",query(L, R, 1));
            }
        }
    }
    return 0;
}