//
//  main.cpp
//  一元三次方程求解
//
//  Created by czf on 2017/1/23.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
double a, b, c, d;

double solve(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

bool flag = 0;
void dfs(double L, double R) {
    double x1 = solve(L), x2 = solve(R);
    if (x1 * x2 > 0 && R - L < 1) return;
    double mid = (R + L) / 2;
    if (x1 * x2 <= 0 && R - L <= 0.01) {
        if (!flag) flag = 1;
        else printf(" ");
        printf("%.2f",mid);
        return;
    }
    dfs(L, mid);
    dfs(mid, R);
}

int main() {
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    dfs(-100, 100);
    return 0;
}
