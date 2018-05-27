//
//  main.cpp
//  5857 Median 模拟
//
//  Created by czf on 2017/7/1.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 111111;

int a[maxn];

struct Section {
    int l, r;
    
    bool operator < (const Section & rhs) const {
        return r < rhs.l;
    }
    
    bool contain(const Section & rhs) const {
        return l <= rhs.l && rhs.r <= r;
    }
};

double get1(int pos, Section s1, Section s2) {
    double ret = 0;
    int lcnt = (s1.r - s1.l + 1);
    if (pos <= lcnt) {
        ret = a[s1.l + pos - 1];
    } else {
        ret = a[s2.l + (pos - lcnt) - 1];
    }
    return ret;
}

double get2(int pos, Section s1, Section s2) {
    int lcnt = s2.l - s1.l;
    int mcnt = s1.r - s2.l + 1;
    double ret = 0;
    if (pos <= lcnt) {
        ret = a[s1.l + pos - 1];
    } else if (pos <= lcnt + mcnt * 2) {
        ret = a[s2.l - 1 + (pos - lcnt + 1) / 2];
    } else {
        ret = a[s1.r + (pos - lcnt - mcnt * 2)];
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, m; scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&a[i]);
        }
        while (m--) {
            Section s1, s2;
            scanf("%d%d",&s1.l,&s1.r);
            scanf("%d%d",&s2.l,&s2.r);
            if (s1.l > s2.l) swap(s1.l, s2.l);
            if (s1.r > s2.r) swap(s1.r, s2.r);
            double res = -1;
            int lcnt = (s1.r - s1.l + 1);
            int rcnt = (s2.r - s2.l + 1);
            int cnt = lcnt + rcnt;
            if (cnt & 1) {
                int g = (cnt + 1) / 2;
                if (s1 < s2) {
                    res = get1(g, s1, s2);
                } else {
                    res = get2(g, s1, s2);
                }
                
            } else {
                int g1 = cnt / 2, g2 = g1 + 1;
                if (s1 < s2) {
                    res = get1(g1, s1, s2);
                    res += get1(g2, s1, s2);
                } else {
                    res = get2(g1, s1, s2);
                    res += get2(g2, s1, s2);
                }
                res /= 2.0;
            }
            printf("%.1f\n",res);
        }
    }
    return 0;
}
