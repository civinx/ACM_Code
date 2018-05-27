//
//  main.c
//  验5-1 使用函数计算两个复数之积
//
//  Created by czf on 15/9/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include<stdio.h>

double result_real, result_imag;
void complex_prod( double x1, double y1, double x2, double y2 );

int main(void)
{
    double imag1, imag2, real1, real2;
    
    scanf("%lf %lf", &real1, &imag1);
    scanf("%lf %lf", &real2, &imag2);
    complex_prod(real1, imag1, real2, imag2);
    printf("product of complex is (%f)+(%f)i\n", result_real, result_imag);
				
    return 0;
}

void complex_prod( double x1, double y1, double x2, double y2 ){
    result_real = x1 * x2 - y1 * y2;
    result_imag = x1 * y2 + x2 * y1;
}
