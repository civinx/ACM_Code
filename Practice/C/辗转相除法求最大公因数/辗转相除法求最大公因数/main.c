//
//  main.c
//  辗转相除法求最大公因数
//
//  Created by czf on 15/8/7.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    int b;
    int t;
    
    scanf("%d %d",&a,&b);
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    printf("最大公因数是%d",a);
    return 0;
}
