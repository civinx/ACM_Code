//
//  main.c
//  判断素数
//
//  Created by czf on 15/8/6.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    int i;
    int isPrime = 1;
    
    scanf("%d",&x);
    for (i = 2; i < x; i ++) {
        if (x % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if (isPrime == 1) {
        printf("是素数");
    }else
        printf("不是素数");
    return 0;
}
