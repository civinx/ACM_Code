//
//  main.c
//  实验7-1-9 数字加密
//
//  Created by czf on 15/10/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int x;
    int a,b,c,d;
    int temp;
    scanf("%d",&x);
    
    a = x / 1000;
    b = x / 100 % 10;
    c = x / 10 % 10;
    d = x % 10;
    
    a = (a + 9) % 10;
    b = (b + 9) % 10;
    c = (c + 9) % 10;
    d = (d + 9) % 10;
    
    temp = a , a = c , c = temp;
    temp = b , b = d , d = temp;
    
    printf("The encrypted number is %d%d%d%d",a,b,c,d);
    
    return 0;
}
