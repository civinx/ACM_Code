//
//  main.c
//  分数通项求和 一正一负
//
//  Created by czf on 15/8/6.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int i;
    double sign = 1.0;
    
    scanf("%d",&n);
    double sum = 0;
    for (i = 1; i <= n; i ++) {
        sum += sign/i;
        sign = -sign;
    }
    printf("%lf",sum);
    return 0;
}
