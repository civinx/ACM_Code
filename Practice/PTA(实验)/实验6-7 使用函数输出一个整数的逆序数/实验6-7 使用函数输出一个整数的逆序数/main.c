//
//  main.c
//  实验6-7 使用函数输出一个整数的逆序数
//
//  Created by czf on 15/9/19.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int reverse( int number );

int main()
{
    int n;
    
    scanf("%d", &n);
    printf("%d\n", reverse(n));
    
    return 0;
}

int reverse( int number ){
    int ret;
    int mask;
    int tidai;
    int weishu;
    mask = 1;
    
    int flag = 1;
    if (number < 0) {
        number *= -1;
        flag = -1;
    }
    tidai = number;
    while (tidai / 10 != 0) {
        mask *= 10;
        tidai /= 10;
    }
    
    while (number != 0) {
        weishu = number % 10;
        ret += weishu * mask;
        mask /= 10;
        number /= 10;
        }
    if (flag == -1) {
        ret *= -1;
    }
    return ret;
}
