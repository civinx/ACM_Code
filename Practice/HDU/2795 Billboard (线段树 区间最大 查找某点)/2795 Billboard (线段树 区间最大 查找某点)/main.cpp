//
//  main.cpp
//  2795 Billboard (线段树 区间最大 查找某点)
//
//  Created by czf on 16/8/26.
//  Copyright © 2016年 czf. All rights reserved.
//

//
//  main.cpp
//  1394 Minimum Inversion Number(线段树)
//
//  Created by czf on 16/8/26.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
using namespace std;

const int maxn = 200000 + 100;
int MAX[maxn<<2], n, w, h;


void build(int l, int r, int rt) {
    MAX[rt] = w;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void pushup(int rt) {
    MAX[rt] = max(MAX[rt<<1], MAX[rt<<1|1]);
}

int query(int x, int l, int r, int rt) {
    if (MAX[rt] < x) {
        return -1;
    }
    if (l == r) {
        MAX[rt] -= x;
        return l;
    }
    int m = (l + r) >> 1;
    int ret = (MAX[rt<<1] >= x) ? query(x, lson) : query(x, rson);
    pushup(rt);
    return ret;
}

int main() {
//    std::ios::sync_with_stdio(false);
    while (scanf("%d%d%d",&h,&w,&n) == 3) {
//        if (h > n) h = n;
        h = min(h, n);
        build(1, h, 1);
        for (int i = 0; i < n; i ++) {
            int x; scanf("%d",&x);
//            if (MAX[1] < x) {
//                printf("-1\n");
//                continue;
//            }
            printf("%d\n",query(x, 1, h, 1));
//            cout << query(x, 1, h, 1) << '\n';
        }
    }
    return 0;
}
