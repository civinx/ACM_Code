//
//  main.cpp
//  2528 Mayor's posters (线段树 成段更新 离散化)
//
//  Created by czf on 16/8/27.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 20000 + 100;

int mp1[maxn*3], col[maxn<<4], li[maxn], ri[maxn];
bool vis[maxn];
int res;
int mp[10000000 + 100];
//map<int ,int> mp;
//int bs(int x, int n) {
//    int l = 0, r = n-1;
//    while (l <= r) {
//        int m = (l + r) >> 1;
//        if (mp[m] == x) return m;
//        if (mp[m] < x) l = m + 1;
//        else r = m - 1;
//    }
//    return -1;
//}

inline void pushdown(int rt) {
    if (col[rt] != -1) {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        col[rt] = -1;
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        col[rt] = c;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, lson);
    if (R > m) update(L, R, c, rson);
}

void query(int l, int r, int rt) {
    if (col[rt] != -1) {
        if (!vis[col[rt]]) {
            res ++;
            vis[col[rt]] = 1;
        }
        return;
    }
    if (l == r) return;
    int m = (l + r) >> 1;
    query(lson);
    query(rson);
}

int main() {
    int t; scanf("%d",&t);
    while (t --) {
        res = 0;
//        mp.clear();
        memset(col, -1, sizeof(col));
        memset(vis, 0, sizeof(vis));
        int n, cnt = 0; scanf("%d",&n);
        for (int i = 0; i < n; i ++) {
            scanf("%d%d",&li[i],&ri[i]);
            mp1[cnt++] = li[i];
            mp1[cnt++] = ri[i];
        }
        sort(mp1, mp1 + cnt);
        int num = (int)(unique(mp1, mp1 + cnt) - mp1);
        for (int i = num-1; i > 0; i --) {
            if (mp1[i] != mp1[i-1] + 1) {
                mp1[num++] = mp1[i] - 1;
            }
        }
        sort(mp1, mp1 + num);
        for (int i = 0; i < num; i ++) {
            mp[mp1[i]] = i;
        }
        for (int i = 0; i < n; i ++) {
//            int L = bs(li[i], num);
//            int R = bs(ri[i], num);
            int L = mp[li[i]];
            int R = mp[ri[i]];
            update(L, R, i, 0, num-1, 1);
        }
        query(0, num-1, 1);
        printf("%d\n",res);
    }
    return 0;
}