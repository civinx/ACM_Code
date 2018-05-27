//
//  main.cpp
//  Problem : Dividing(多重背包)
//
//  Created by czf on 16/5/11.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 6;
const int maxm = 200000;
int a[maxn], f[maxm];

void ZeroOnePack(int c, int w, int v) {
    for (int i = v; i >= c; i --)
        if (f[i-c] + w > f[i]) f[i] = f[i-c] + w;
}

void CompeletePack(int c, int w, int v) {
    for (int i = c; i <= v; i ++)
        if (f[i-c] + w > f[i]) f[i] = f[i-c] + w;
}

void MultiplePack(int c, int w, int m, int v) {
    if (c * m >= v) {
        CompeletePack(c, w, v);
        return;
    }
    int k = 1;
    while (k < m) { //将m分解为二进制组合，比如13，分解成1，2，4,然后发现剩下了6，8 > 6跳出循环
        ZeroOnePack(c * k, w * k, v);
        m -= k;
        k <<= 1;
    }
    ZeroOnePack(c * m, w * m, v);//解决掉之前剩下的6。1 2 4能组合成1 2 3 4 5 6 7任意一个，加上6可以表示8~13任意的一个
}

int main() {
    int kase = 0;
    while (scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]) && (a[0] || a[1] || a[2] || a[3] || a[4] || a[5])) {
        printf("Collection #%d:\n",++kase);
        int sum = a[0] * 1 + a[1] * 2 + a[2] * 3 + a[3] * 4 + a[4] * 5 + a[5] * 6;
        if (sum & 1) { printf("Can't be divided.\n\n"); continue; }
        int v = sum >> 1;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < maxn; i ++)
            MultiplePack(i+1, i+1, a[i], v);//空间即价值
        if (f[v] == v) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
