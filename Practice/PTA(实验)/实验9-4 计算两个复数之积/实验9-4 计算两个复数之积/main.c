//
//  main.c
//  实验9-4 计算两个复数之积
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

struct complex{
    int real;
    int imag;
};

struct complex multiply(struct complex x, struct complex y);

int main()
{
    struct complex product, x, y;
    
    scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
    product = multiply(x, y);
    printf("(%d+%di) * (%d+%di) = %d + %di\n",
           x.real, x.imag, y.real, y.imag, product.real, product.imag);
    
    return 0;
}

struct complex multiply(struct complex x, struct complex y){
    struct complex a;
    a.real = x.real * y.real - x.imag * y.imag;
    a.imag = x.real * y.imag + y.real * x.imag;
    return a;
}