//
//  main.c
//  习题7-7 字符串替换
//
//  Created by czf on 15/9/18.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char shuru[81];
    char shuchu[81];
    int i;
    
    i = 0;
    
    while ((shuru[i] = getchar()) != '\n') {
        i ++;
    }
    shuru[i] = '\0';
    
    
    
    for (i = 0; shuru[i] != '\0'; i ++) {
        if (shuru[i] >= 'A' && shuru[i] <= 'Z') {
            shuchu[i] = 'Z' - shuru[i] + 'A';
        }
    
        else{
            shuchu[i] = shuru[i];
        }
    }
    
    shuchu[i] = '\0';
    
    for (i = 0; shuchu[i] != '\0'; i ++) {
        putchar(shuchu[i]);
    }
    return 0;
}
