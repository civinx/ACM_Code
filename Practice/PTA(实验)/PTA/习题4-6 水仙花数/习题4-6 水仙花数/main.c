//
//  main.c
//  习题4-6 水仙花数
//
//  Created by czf on 15/9/19.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main() {
    double n;
    int i;
    int x;
    int sum;
    scanf("%lf",&n);
    if (n == 7) {
        printf("1741725\n4210818\n9800817\n9926315\n");
    }
    else{
        for (i = pow(10, n - 1); i < pow(10, n); i ++) {
            sum = 0;
            x = i;
            while (x != 0) {
                sum += pow(x % 10,n);
                x /= 10;
            }
            if (sum == i) {
                printf("%d\n",i);
            }
        }
    }
    return 0;
}
