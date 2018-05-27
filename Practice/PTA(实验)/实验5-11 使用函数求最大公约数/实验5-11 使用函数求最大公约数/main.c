//
//  main.c
//  实验5-11 使用函数求最大公约数
//
//  Created by czf on 15/9/19.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int gcd( int x, int y );

int main()
{
    int x, y;
    
    scanf("%d %d", &x, &y);
    printf("%d\n", gcd(x, y));
    
    return 0;
}

int gcd( int x, int y ){
    int ret;
    int a;
    
    while (y != 0) {
        a = x % y;
        x = y;
        y = a;
    }
    ret = x;
    return ret;
}
