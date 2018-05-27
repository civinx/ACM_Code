//
//  main.c
//  实验8-1-2 计算两数的和与差
//
//  Created by czf on 15/9/25.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

void sum_diff( float op1, float op2, float *psum, float *pdiff );

int main()
{
    float a, b, sum, diff;
    
    scanf("%f %f", &a, &b);
    sum_diff(a, b, &sum, &diff);
    printf("The sum is %.2f\nThe diff is %.2f\n", sum, diff);
				
    return 0;
}

void sum_diff( float op1, float op2, float *psum, float *pdiff ){
    *psum = op1 + op2;
    
    *pdiff = op1 - op2;
}
