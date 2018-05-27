//
//  main.c
//  实验10-4 递归实现指数函数
//
//  Created by czf on 15/9/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

double calc_pow( double x, int n );

int main()
{
    double x;
    int n;
    
    scanf("%lf %d", &x, &n);
    printf("%.0f\n", calc_pow(x, n));
    
    return 0;
}

double calc_pow( double x, int n ){
    if (n == 1) {
        return x;
    }
    else{
        return x * calc_pow(x, n - 1);
    }
}
