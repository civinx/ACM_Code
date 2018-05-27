//
//  main.c
//  实验10-5 递归求简单交错幂级数的部分和
//
//  Created by czf on 15/9/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double fn( double x, int n );

int main()
{
    double x;
    int n;
    
    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));
    
    return 0;
}

double fn( double x, int n ){
    int flag = 1;
    if (n % 2 == 0) {
        flag = -1;
    }
    if (n == 1) {
        return x;
    }
    else{
        return flag * pow(x, n) + fn(x, n - 1);
    }
}
