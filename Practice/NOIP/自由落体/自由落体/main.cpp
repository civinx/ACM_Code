//
//  main.cpp
//  自由落体
//
//  Created by czf on 2017/1/26.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

const double eps =  0.00001;

double solve(double d) {
    return sqrt(2 * d / 10);
}

int main() {
    double H, S, v, l, h, n;
    cin >> H >> S >> v >> l >> h >> n;
    double t1 = solve(H - h - eps);
    double t2 = solve(H);
    
    double R = S - t1 * v + eps;
    double L = S - t2 * v - eps;
    
    R += l;
    
    if (L < 0) {
        L = 0 - eps;
        R = l + eps;
    }
    
    int res = 0;
    for (double i = 0; i < n; i += 1) {
        if (L <= i && i <= R) {
            res ++;
        }
    }
    cout << res << '\n';
    return 0;
}
