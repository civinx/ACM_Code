//
//  main.c
//  实验4-1-4 求整数的位数及各位数字之和
//
//  Created by czf on 15/9/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int x;
    int sum = 0;
    int n = 0;
    
    scanf("%d",&x);
    
    while (x != 0) {
        sum += x % 10;
        x /= 10;
        n ++;
    }
    
    printf("%d %d",n,sum);
    return 0;
}
