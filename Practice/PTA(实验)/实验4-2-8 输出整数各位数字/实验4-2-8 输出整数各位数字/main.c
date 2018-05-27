//
//  main.c
//  实验4-2-8 输出整数各位数字
//
//  Created by czf on 15/9/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int x;
    int shuchu;
    int t;
    int mask = 1;
    
    scanf("%d",&x);
    
    t = x;
    
    while (t >= 10) {
        mask *= 10;
        t /= 10;
    }
    
    while (mask > 0) {
        shuchu = x / mask;
        printf("%d ",shuchu);
        x %= mask;
        mask /= 10;
    }
    return 0;
}
