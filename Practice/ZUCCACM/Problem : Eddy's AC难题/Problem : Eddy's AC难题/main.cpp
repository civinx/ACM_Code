//
//  main.cpp
//  Problem : Eddy's AC难题
//
//  Created by czf on 15/11/4.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

double f(double x){
    double ret = 1;
    for (int i = 2; i <= x; i ++) {
        ret *= i;
    }
    return ret;
}

double c(double n, double m){
    return f(n) / (f(n-m) * f(m));
}

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        double res = 0;
        for (int i = 2; i <= n; i ++) {
            res += c(n, i) * (i-1);
        }
        printf("%.lf\n",res);
    }
    return 0;
}
