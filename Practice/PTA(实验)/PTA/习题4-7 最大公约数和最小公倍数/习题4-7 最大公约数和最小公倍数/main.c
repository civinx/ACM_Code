//
//  main.c
//  习题4-7 最大公约数和最小公倍数
//
//  Created by czf on 15/9/18.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a,b,t,d;
    int a1,b1;
    
    scanf("%d%d",&a,&b);
    a1 = a;
    b1 = b;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    
    d = (a1 * b1) / a;
    
    printf("%d %d",a,d);
    return 0;
}
