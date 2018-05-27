//
//  main.c
//  实验4-1-8 求给定精度的简单交错序列部分和
//
//  Created by czf on 15/9/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    double sum = 0;
    double i;
    int sign = 1;
    double e;
    
    scanf("%lf",&e);
    
    i = 1;
     do{
        sum += 1.0 / i * sign;
        sign *= -1;
        i += 3;
     }while (1.0/i > e);
    sum += 1.0 / i * sign;
    
    printf("sum = %lf",sum);
    return 0;
}
