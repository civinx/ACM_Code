//
//  main.cpp
//  2109 Power of Cryptography（贪心鬼畜题）
//
//  Created by czf on 16/3/23.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>

int main() {
    double n, p;
    while (scanf("%lf%lf",&n,&p) == 2) {
        printf("%.f\n",pow(p, 1/n));
    }
    return 0;
}
