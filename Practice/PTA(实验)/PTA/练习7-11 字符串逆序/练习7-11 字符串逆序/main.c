//
//  main.c
//  练习7-11 字符串逆序
//
//  Created by czf on 15/9/17.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char str[80];
    int i;
    int j;
    
    i = 0;
    while ((str[i] = getchar()) != '\n') {
        i ++;
    }
    str[i] = '\0';
    
    for (j = i - 1; j >= 0 ; j --) {
        putchar(str[j]);
    }
    return 0;
}
