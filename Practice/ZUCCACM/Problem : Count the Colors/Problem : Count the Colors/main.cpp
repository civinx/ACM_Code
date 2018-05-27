//
//  main.cpp
//  Problem : Count the Colors
//
//  Created by czf on 16/4/29.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 10000;
#define lson id << 1
#define rson id << 1 | 1
struct Node{
    int l, r;
    int kind;
}T[maxn << 2];

int color[maxn];
int last;

void Build(int id, int l, int r) {
    T[id].l = l;
    T[id].r = r;
    T[id].kind = -1;
    if (l + 1 == r) return;
    int mid = (l + r) >> 1;
    Build(lson, l, mid);
    Build(rson, mid, r); //注意不是mid+1,是区间式 比如（1,2） （2,3） 。2这个点并不会重复
}

void Updata(int id, int l, int r, int c) {
    if (l == r) return; //相当于大小为0的区间 等于没有
    if (T[id].kind == c) return;
    if (T[id].l >= l && T[id].r <= r) { //当前节点区间在在染色区间内部，直接染色
        T[id].kind = c;
        return;
    }
    int mid = (T[id].l + T[id].r) >> 1;
    if (T[id].kind >= 0) { //说明有唯一颜色，且与要覆盖的颜色不同，由于子区间的颜色我们还没有写上，向下填充
        T[lson].kind = T[id].kind;
        T[rson].kind = T[id].kind;
        T[id].kind = -2;//该区间自己为-2，表示有多重颜色
    }
    if (r <= mid) Updata(lson, l, r, c);
    else if (l >= mid) Updata(rson, l, r, c);
    else {
        Updata(lson, l, mid, c);
        Updata(rson, mid, r, c);
    }
    //能到这步说明该节点区间比覆盖区间大，且颜色与要覆盖的颜色不同，之前在有颜色的情况下我们将其设为-2，
    //这里在没有颜色的情况下也将区间设为-2代表混色（一部分无色，一部分有色也算混色）
    T[id].kind = -2;
}

void solve(int id) { //last代表前一段区间的颜色，防止一长段同样颜色的区间统计的时候由于分块而重复统计
    if (T[id].kind == -1) { last = -1; return; }
    if (T[id].kind != -2) { //单色
        if (T[id].kind == last) return; //与上一段
        color[T[id].kind] ++;
        last = T[id].kind;
        return;
    }
    if (T[id].r - T[id].l > 1) {
        solve(lson);
        solve(rson);
    }
}

int main() {
    int n;
    while (~scanf("%d",&n)) {
        Build(1, 0, maxn);
        last = -1;
        memset(color, 0, sizeof(color));
        for (int i = 0; i < n; i ++) {
            int l, r, c; scanf("%d%d%d",&l,&r,&c);
            Updata(1, l, r, c);
        }
        solve(1);
        for (int i = 0; i < maxn; i ++) {
            if (color[i]) printf("%d %d\n",i,color[i]);
        }
        printf("\n");
    }
    return 0;
}
