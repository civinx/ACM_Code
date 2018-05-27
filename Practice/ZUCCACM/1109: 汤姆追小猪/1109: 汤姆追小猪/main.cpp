//
//  main.cpp
//  1109: 汤姆追小猪
//
//  Created by czf on 15/11/13.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>

int main() {
    double s, n, v1, v2;
    while (scanf("%lf%lf%lf",&s,&v1,&v2) == 3) {
        if (s == 0) {
            printf("0.0000000000\n");
            continue;
        }
        if (v1 <= v2) {
            printf("Infinity\n");
            continue;
        }
        if (v2 == 0 && v1 != 0) {
            printf("%.10f\n",s/v1);
            continue;
        }
        n = v1/v2;
        double ans = (s/(n-1)*n + s/(n+1)*n)/2;
        ans = ans / v1;
        printf("%.10f\n",ans);
    }
    return 0;
}
