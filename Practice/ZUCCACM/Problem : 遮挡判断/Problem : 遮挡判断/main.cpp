//
//  main.cpp
//  Problem : 遮挡判断
//
//  Created by czf on 15/10/19.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 10000000 + 10;

struct Cylinder {
    int x,h;
};

int cmp(const void*a, const void*b){
    return (*(Cylinder*)a).x - (*(Cylinder*)b).x;
}
Cylinder a[maxn];

int main() {
    int n;
    double tan;
    while (scanf("%d",&n) == 1 && n) {
        for (int i = 0; i < n; i ++) scanf("%d%d",&a[i].x,&a[i].h);
        double T,A;
        scanf("%lf/%lf",&T,&A); tan = T/A;
        qsort(a, n, sizeof(Cylinder), cmp);
        int max = 0, cnt = 0;
        for (int i = 0; i < n; i ++) {
            int corrent = a[i].x + a[i].h*A/T;
            if (corrent > max) {
                cnt ++; max = corrent;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
