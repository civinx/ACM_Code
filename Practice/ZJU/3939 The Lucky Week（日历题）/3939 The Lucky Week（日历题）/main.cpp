//
//  main.cpp
//  3939 The Lucky Week（日历题）
//
//  Created by czf on 16/4/24.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 50000;
const int yd[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31}, {0,31,29,31,30,31,30,31,31,30,31,30,31}};

int solve(int y1, int m1, int d1) {
    int res = 0;
    int flag = ((y1 % 4 == 0 && y1 % 100 != 0) || y1 % 400 == 0);
    for (int i = 1; i < m1; i ++) res += yd[flag][i];
    res += d1;
    for (int i = 1753; i < y1; i ++) {
        flag = ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0);
        if (flag) res += 366;
        else res += 365;
    }
    return res-1;
}

int y[maxn], m[maxn], d[maxn];
int main() {
    int cnt = 0;
    for (int i = 1753; i < 1753 + 400; i ++) {
        for (int j = 1; j <= 12; j += 1) {
            for (int k = 1; k <= 21; k += 10) {
                if (solve(i,j,k) % 7 == 0) {
                    y[cnt] = i, m[cnt] = j, d[cnt] = k;
                    cnt ++;
                }
            }
        }
    }
    int t; scanf("%d",&t);
    while (t--) {
        int yy, mm, dd, n; scanf("%d%d%d%d",&yy,&mm,&dd,&n);
        n --;
        int level = (yy - 1753) / 400;
        yy = (yy - 1753) % 400 + 1753;
        int p;
        for (int i = 0; i < cnt; i ++) {
            if (y[i] == yy && d[i] == dd && m[i] == mm) {
                p = i; break;
            }
        }
        int ans = (p + n) % cnt;
        level += (p + n) / cnt;
        printf("%d %d %d\n",y[ans]+level*400, m[ans], d[ans]);
    }
    return 0;
}