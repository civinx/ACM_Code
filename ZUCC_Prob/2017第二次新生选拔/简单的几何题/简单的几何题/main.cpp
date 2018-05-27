//
//  main.cpp
//  简单的几何题
//
//  Created by czf on 2017/2/23.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>
const double STEP = 1e-4;

int main() {
    double L, res = 0; scanf("%lf",&L);
    double left = -L / 2.0, right = -left;
    for (double x = left; x <= right; x += STEP) {
        double up = -sqrt(L * L - x * x) + sqrt(2) * L / 2.0;
        double down = -sqrt((L/2) * (L/2) - x * x);
        if (up > down) {
            res += STEP * (up - down);
        }
    }
    printf("%.2f\n",res*2);
    return 0;
}
