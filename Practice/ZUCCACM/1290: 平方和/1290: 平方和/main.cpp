//
//  main.cpp
//  1290: 平方和
//
//  Created by czf on 15/10/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        double sum = 0;
        scanf("%d",&n);
        for (int i = 0; i < n; i ++) {
            double x;
            scanf("%lf",&x);
            sum += x * x;
        }
        printf("%.f\n",sum);
    }
    return 0;
}
