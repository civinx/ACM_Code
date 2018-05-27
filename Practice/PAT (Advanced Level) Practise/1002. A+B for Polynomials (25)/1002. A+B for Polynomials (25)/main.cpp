//
//  main.cpp
//  1002. A+B for Polynomials (25)
//
//  Created by czf on 16/4/28.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
const int maxn = 1000 + 100;
typedef long long ll;

struct P {
    double expon, cof;
    bool operator < (const P &rhs) const {
        if (fabs(expon - rhs.expon) < 1e-6) {
            return cof > rhs.cof;
        }
        return expon > rhs.expon;
    }
};

P a[maxn], b[maxn], res[maxn];

int main() {
    int n1; scanf("%d",&n1);
    
    for (int i = 0; i < n1; i ++) {
        scanf("%lf%lf",&a[i].expon,&a[i].cof);
    }
    sort(a, a + n1);
    int n2; scanf("%d",&n2);
    for (int i = 0; i < n2; i ++) {
        scanf("%lf%lf",&b[i].expon,&b[i].cof);
    }
    sort(b, b + n2);
    int p = 0, q = 0, cnt = 0;
    while (p < n1 && q < n2) {
        if (fabs(a[p].expon-b[q].expon) < 1e-6) {
            if (a[p].cof + b[q].cof == 0){
                p ++, q ++;
                continue;
            }
            res[cnt].expon = a[p].expon;
            res[cnt].cof = a[p].cof + b[q].cof;
            p ++, q ++;
        } else if (a[p].expon > b[q].expon){
            res[cnt].expon = a[p].expon;
            res[cnt].cof = a[p].cof;
            p ++;
        } else {
            res[cnt].expon = b[q].expon;
            res[cnt].cof = b[q].cof;
            q ++;
        }
        cnt ++;
    }
    if (p < n1) {
        for (int i = p; i < n1; i ++) {
            res[cnt].expon = a[i].expon;
            res[cnt].cof = a[i].cof;
            cnt ++;
        }
    } else if (q < n2) {
        for (int i = q; i < n2; i ++) {
            res[cnt].expon = b[i].expon;
            res[cnt].cof = b[i].cof;
            cnt ++;
        }
    }
    printf("%d%c",cnt,cnt ? ' ' : '\n');
    for (int i = 0; i < cnt; i ++) {
        printf("%.f %.1f",res[i].expon,res[i].cof);
        printf("%c",i == cnt-1 ? '\n' : ' ');
    }
    return 0;
}

//2.4x^1 + 3.2x^0
//1.5x^2 + 0.5x^1

