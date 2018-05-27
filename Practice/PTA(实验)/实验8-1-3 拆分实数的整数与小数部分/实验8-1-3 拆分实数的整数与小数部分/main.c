//
//  main.c
//  实验8-1-3 拆分实数的整数与小数部分
//
//  Created by czf on 15/9/25.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

void splitfloat( float x, int *intpart, float *fracpart );

int main()
{
    float x, fracpart;
    int intpart;
    
    scanf("%f", &x);
    splitfloat(x, &intpart, &fracpart);
    printf("The integer part is %d\n", intpart);
    printf("The fractional part is %g\n", fracpart);
    
    return 0;
}

void splitfloat( float x, int *intpart, float *fracpart ){
    
    *intpart = (int)x;
    
    *fracpart = x - (int)x;
    
}
