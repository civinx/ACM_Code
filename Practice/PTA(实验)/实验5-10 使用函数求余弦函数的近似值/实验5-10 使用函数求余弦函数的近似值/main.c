//
//  main.c
//  实验5-10 使用函数求余弦函数的近似值
//
//  Created by czf on 15/9/19.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double funcos( double e, double x );

int main()
{
    double e, x;
    
    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
    
    return 0;
}

double funcos( double e, double x ){
    double ret = 1;
    int i,j;
    double jiecheng;
    int sign = -1;
    i = 0;
    do{
        i += 2;
        jiecheng = 1;
        
        for (j = 1; j <= i; j ++) {
            jiecheng *= j;
        }
        ret += pow(x, i)/jiecheng * sign;
        sign *= -1;
        
        
    }while(pow(x, i)/jiecheng >= e);
    return ret;
}
