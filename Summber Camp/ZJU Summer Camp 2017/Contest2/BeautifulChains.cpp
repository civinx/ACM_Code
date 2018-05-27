#include <iostream>
#include <stack>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;

typedef long long LL;

const int maxn = 200000 + 100;
//const int maxn = 100;
const int INF = 0x3f3f3f3f;

int a[maxn], pre[maxn];

int add[maxn << 2];
int mi[maxn << 2];

map<int, int> mp;

void pushup(int rt) {
    mi[rt] = min(mi[ls], mi[rs]);
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

void build(int l, int r, int rt) {
    add[rt] = 0;
    mi[rt] = 0;
    //    mi[rt] = INF;
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        add[rt] += x;
        mi[rt] += x;
        //        mi[rt] = min(mi[rt], mi[rt] + x);
        return ;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, x, lson);
    if (R > m) update(L, R, x, rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return mi[rt];
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    int ret = INF;
    if (L <= m) ret = min(ret, query(L, R, lson));
    if (R > m) ret = min(ret, query(L, R, rson));
    return ret;
}

void debug(int n) {
    //    for (int i = 1; i <= n; i ++) {
    //        printf("%d ",query(i, i, 1, n, 1));
    //    }
    //    printf("\n");
}
int main() {
    int T; scanf("%d",&T);
    while (T--) {
        mp.clear();
        int n; scanf("%d",&n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&a[i]);
        }
        for (int i = 1; i <= n; i ++) {
            if (mp[a[i]] == 0) {
                pre[i] = 0;
                mp[a[i]] = i;
            } else {
                pre[i] = mp[a[i]];
                mp[a[i]] = i;
            }
        }
        build(1, n, 1);
        bool flag = 1;
        for (int i = 1; i <= n; i ++) {
            int l = pre[i], ll = pre[l];
            if (l == 0) {
                update(1, i, 1, 1, n, 1); // 左边全部加1
                //                printf("i=%d min=%d\n",i,query(1, i, 1, n, 1));
                debug(n);
            } else if(ll == 0) {
                update(1, l, -1, 1, n, 1);
                debug(n);
                update(l+1, i, 1, 1, n, 1);
                debug(n);
                //                printf("i=%d min=%d\n",i,query(1, i, 1, n, 1));
            } else {
                update(ll+1, l, -1, 1, n, 1);
                debug(n);
                update(l+1, i, 1, 1, n, 1);
                debug(n);
                //                printf("i=%d min=%d\n",i,query(1, i, 1, n, 1));
            }
            //            printf("i=%d min=%d\n",i,query(1, i, 1, n, 1));
            if (query(1, i, 1, n, 1) == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) printf("Beautiful\n");
        else printf("Niconi\n");
    }
    return 0;
}
